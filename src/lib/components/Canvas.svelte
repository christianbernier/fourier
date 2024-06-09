<script lang="ts">
	import { onDestroy, onMount } from "svelte";
	import { Constants } from "../Constants";

  export let setup: (context: CanvasRenderingContext2D, canvas: HTMLCanvasElement) => void;
  export let draw: ((context: CanvasRenderingContext2D) => void) | undefined;

  let canvas: HTMLCanvasElement;
  let context: CanvasRenderingContext2D;
  let drawInterval: NodeJS.Timeout;

  onMount(() => {
    context = canvas.getContext('2d')!;
    setup(context, canvas);

    if (draw) {
      drawInterval = setInterval(() => draw(context), 10);
    }
  });

  onDestroy(() => {
    if (drawInterval) {
      clearInterval(drawInterval!);
    }
  });
</script>

<canvas
  width={Constants.CANVAS_WIDTH}
  height={Constants.CANVAS_HEIGHT}
  bind:this={canvas}
/>

<style>
  canvas {
    position: absolute;
    left: 0;
    top: 0;
    width: min(100%, var(--canvas-width));
    aspect-ratio: 1;
  }
</style>
