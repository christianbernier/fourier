<script lang="ts">
	import { type LoadedPath, PiPath, getPathsFromLocalStorage } from "$lib";
	import { onMount } from "svelte";
	import PathList from "$lib/components/PathList.svelte";
	import CanvasWithSidebar from "$lib/components/CanvasWithSidebar.svelte";
	import CanvasContainer from "$lib/components/CanvasContainer.svelte";
	import EpicycleCanvas from "$lib/components/EpicycleCanvas.svelte";
	import InputCanvas from "$lib/components/InputCanvas.svelte";
	
  let currentPath = PiPath;
	let knownPaths: Array<LoadedPath> = []

	onMount(() => {
		knownPaths = getPathsFromLocalStorage();

		const urlParams = new URL(window.location.href).searchParams;
		if (urlParams.has('path')) {
			knownPaths.forEach(path => {
				if (path.key === urlParams.get('path')) {
					currentPath = path
				}
			})
		}
	})
</script>

<CanvasWithSidebar>
	<CanvasContainer slot="canvas">
		{#key currentPath.key}
			<EpicycleCanvas epicycles={currentPath.epicycles}/>
			<InputCanvas inputPoints={currentPath.inputPoints}/>
		{/key}
	</CanvasContainer>
	<PathList
		slot="sidebar"
		bind:knownPaths={knownPaths}
		bind:currentPath={currentPath}
	/>
</CanvasWithSidebar>
