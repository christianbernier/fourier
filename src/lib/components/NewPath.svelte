<script lang="ts">
	import type { CanvasPoint } from "../CanvasPoint";
	import type { Epicycle } from "../Epicycle";
	import Module from "../compute/calculate";
	import {v4 as uuidv4} from 'uuid';
	import Sidebar from "./Sidebar.svelte";
	import { addPathToLocalStorage } from "$lib";

	export let points: Array<CanvasPoint>;
  let name: string;
  let errorText: string = '';

  const addPath = async () => {
    errorText = '';

    if (!name) {
      errorText = 'Your drawing must have a name!';
      return;
    }

    if (points.length < 4) {
      errorText = 'Your drawing must have at least 4 points!';
      return;
    }

		const wasmModule = await Module()
		const inputVector = new wasmModule.VectorCanvasPoint();
		points.forEach(point => inputVector.push_back([point.x, point.y]))
		const computed = wasmModule['compute'](inputVector)
		const epicycles = [];
		for (let i = 0; i < computed.size(); i++) {
			const epicycle = computed.get(i);
			if (epicycle[0] < 1) {
				break;
			}
			epicycles.push({
        radius: epicycle[0],
        angularVelocity: epicycle[1],
        initialPhase: epicycle[2]
      } as Epicycle);
		}

    const key = uuidv4()
    addPathToLocalStorage({
			key,
			name,
			inputPoints: points,
			epicycles,
      isDefaultPath: false,
		})

    window.location.href = `/?path=${key}`
	}
</script>

<Sidebar title="New Path">
  <div slot="sidebar-content">
    <p class="help">Click on the canvas to add points to your drawing. The order of your points matters!</p>
    <input bind:value={name} type="text" placeholder="Name" minlength="1">
    <button class="active" on:click={addPath}>Add!</button>
    {#if errorText}
      <p class="error">{errorText}</p>
    {/if}
  </div>
  <div slot="sidebar-links">
    <a href="/">Back to home</a>
  </div>
</Sidebar>
