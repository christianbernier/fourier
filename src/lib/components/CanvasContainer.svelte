<div
  id="canvas_container"
>
  <slot></slot>
</div>

<style>
	#canvas_container {
		position: relative;
		width: calc(var(--canvas-width) - var(--border-width));
	}

	@media only screen and (max-width: 850px) {
    #canvas_container {
			width: min(100%, calc(var(--canvas-width) - var(--border-width)));
			aspect-ratio: 1;
		}
	}
</style>
