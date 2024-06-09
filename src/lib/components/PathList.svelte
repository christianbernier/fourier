<script lang="ts">
	import type { LoadedPath } from "$lib/LoadedPath";
	import { deletePathFromLocalStorage } from "$lib/LocalStorage";
	import Sidebar from "./Sidebar.svelte";

  export let knownPaths: Array<LoadedPath>;
  export let currentPath: LoadedPath;

  const deletePath = (path: LoadedPath) => {
    if (path.isDefaultPath) {
      alert('You cannot delete a default path!');
      return;
    }
    if (confirm(`Are you sure you'd like to delete the path named "${path.name}"?`)) {
      deletePathFromLocalStorage(path);
      window.location.href = '/'
    }
  }
</script>

<Sidebar title="Paths">
  <div slot="sidebar-content" class="path-list">
    {#each knownPaths as knownPath}
      <button
        on:click={() => currentPath = knownPath}
        class={currentPath.key === knownPath.key ? 'active' : ''}
      >
        {knownPath.name}
        {#if !knownPath.isDefaultPath}
          <a on:click={deletePath(knownPath)} style="font-size: 1.5rem;">×</a>
        {/if}
      </button>
    {/each}
  </div>
  <div slot="sidebar-links">
    <p><a href="/new">Draw a new path</a></p>
    <p><a href="/about">Learn more</a></p>
  </div>
</Sidebar>

<style>
  .path-list {
    width: 300px;
    display: flex;
    flex-direction: column;
  }

  button {
    display: flex;
    flex-direction: row;
    justify-content: space-between;
    align-items: center;
  }
</style>
