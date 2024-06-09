<script lang="ts">
	import { type CanvasPoint } from "$lib";
	import CanvasContainer from "$lib/components/CanvasContainer.svelte";
	import CanvasWithSidebar from "$lib/components/CanvasWithSidebar.svelte";
	import DrawingCanvas from "$lib/components/DrawingCanvas.svelte";
	import NewPath from "$lib/components/NewPath.svelte";

	let points: Array<CanvasPoint> = [];
</script>

<CanvasWithSidebar>
	<CanvasContainer slot="canvas">
		<DrawingCanvas bind:points={points}/>
	</CanvasContainer>
	<NewPath slot="sidebar" bind:points={points}/>
</CanvasWithSidebar>
