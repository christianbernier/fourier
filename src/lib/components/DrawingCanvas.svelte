<script lang="ts">
	import type { CanvasPoint } from "../CanvasPoint";
	import { Constants } from "../Constants";
	import Canvas from "./Canvas.svelte";

  export let points: Array<CanvasPoint>;

  let context: CanvasRenderingContext2D;
  let canvas: HTMLCanvasElement;

  const setup = (_context: CanvasRenderingContext2D, _canvas: HTMLCanvasElement) => {
    context = _context;
    canvas = _canvas;
    canvas.onclick = newPoint;
    context.fillStyle = Constants.COLOR_DARK;
  }

  let newPoint = (mouseEvent: MouseEvent) => {
    if (!canvas || !context) {
      return;
    }

    const canvasBoundingRect = canvas.getBoundingClientRect();
    // Adjust for scaling on mobile, if we can't show the entire canvas
    const x = (mouseEvent.clientX - canvasBoundingRect.x) * Constants.CANVAS_WIDTH / canvasBoundingRect.width;
    const y = (mouseEvent.clientY - canvasBoundingRect.y) * Constants.CANVAS_HEIGHT / canvasBoundingRect.height;
    console.log(x, y)
    points.push({
      x: x - Constants.CANVAS_WIDTH / 2,
      y: Constants.CANVAS_HEIGHT / 2 - y
    })
    context.beginPath();
    context.ellipse(x, y, Constants.CANVAS_STROKE_SIZE, Constants.CANVAS_STROKE_SIZE, 0, 0, 2 * Math.PI);
    context.fill();
  }
</script>

<Canvas
  {setup}
  draw={undefined}
/>
