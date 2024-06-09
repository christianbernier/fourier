<script lang="ts">
	import type { Epicycle } from "../Epicycle";
	import type { CanvasPoint } from "../CanvasPoint";
	import { Constants } from "../Constants";
	import Canvas from "./Canvas.svelte";

  export let epicycles: Epicycle[];

  let time = 0;
  const timeSpeed = 0.005;

  const maxNumPoints = 1000;
  const drawnPoints: Array<CanvasPoint> = []

  const setup = (context: CanvasRenderingContext2D) => {
    context.strokeStyle = Constants.COLOR_DARK;
  }

  const draw = (context: CanvasRenderingContext2D) => {
    time += timeSpeed;

    context.clearRect(0, 0, Constants.CANVAS_WIDTH, Constants.CANVAS_HEIGHT);
    
    context.fillStyle = Constants.COLOR_LIGHT;
    context.fillRect(0, 0, Constants.CANVAS_WIDTH, Constants.CANVAS_HEIGHT);
    context.save();

    context.translate(Constants.CANVAS_WIDTH / 2, Constants.CANVAS_HEIGHT / 2);

    epicycles.forEach(epicycle => drawEpicycle(context, epicycle))

    addPoint(new DOMPoint(0, 0).matrixTransform(context.getTransform()))

    context.restore();

    context.fillStyle = Constants.COLOR_DARK;
    drawnPoints.forEach(point => {
      context.beginPath();
      context.ellipse(point.x, point.y, Constants.CANVAS_STROKE_SIZE, Constants.CANVAS_STROKE_SIZE, 0, 0, 2 * Math.PI);
      context.fill();
    })
  }

  const addPoint = (point: CanvasPoint) => {
    if (drawnPoints.length >= maxNumPoints) {
      drawnPoints.shift();
    }

    drawnPoints.push(point)
  }

  const drawEpicycle = (context: CanvasRenderingContext2D, epicycle: Epicycle) => {
    const phase = epicycle.angularVelocity * time + epicycle.initialPhase;
    const pointX = epicycle.radius * Math.cos(phase);
    const pointY = -1 * (epicycle.radius * Math.sin(phase));

    context.beginPath();
    context.ellipse(0, 0, epicycle.radius, epicycle.radius, 0, 0, 2 * Math.PI);
    context.moveTo(0, 0);
    context.lineTo(pointX, pointY);
    context.translate(pointX, pointY);
    context.stroke();
  }
</script>

<Canvas
  {setup}
  {draw}
/>
