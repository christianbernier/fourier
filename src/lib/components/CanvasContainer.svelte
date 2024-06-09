<script lang="ts">
	import { Constants } from "$lib/Constants";
</script>

<div
  id="canvas_container"
  style={`
		width: ${Constants.CANVAS_WIDTH + 2 * Constants.CANVAS_BORDER_WIDTH}px;
		height: ${Constants.CANVAS_HEIGHT + 2 * Constants.CANVAS_BORDER_WIDTH}px
	`}
>
  <slot></slot>
</div>

<style>
	#canvas_container {
		position: relative;
	}
</style>
