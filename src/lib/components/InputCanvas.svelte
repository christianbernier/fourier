<script lang="ts">
	import type { CanvasPoint } from "../CanvasPoint";
	import { Constants } from "../Constants";
	import Canvas from "./Canvas.svelte";

  export let inputPoints: Array<CanvasPoint>;

  const setup = (context: CanvasRenderingContext2D) => {
    context.translate(Constants.CANVAS_WIDTH / 2, Constants.CANVAS_HEIGHT / 2);
    context.fillStyle = Constants.COLOR_PRIMARY;
    inputPoints.forEach(point => {
      context.beginPath();
      context.ellipse(point.x, -point.y, Constants.CANVAS_STROKE_SIZE, Constants.CANVAS_STROKE_SIZE, 0, 0, 2 * Math.PI);
      context.fill();
    })
  }
</script>

<Canvas
  {setup}
  draw={undefined}
/>
