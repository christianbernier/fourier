<script lang="ts">
	export let title: string;
</script>

<div class="sidebar-container">
  <div class="sidebar-top">
    <p>{title}</p>
    <slot name="sidebar-content" />
  </div>
  <div class="sidebar-links">
    <slot name="sidebar-links" />
  </div>
</div>

<style>
  .sidebar-container {
    display: flex;
    flex-direction: column;
    justify-content: space-between;
  }

  .sidebar-top {
    width: 300px;
  }

  p {
    margin-bottom: var(--margin-md);
    font-weight: bold;
    font-size: 1.2rem;
  }

  .sidebar-links {
    padding-top: var(--margin-md);
  }
</style>
