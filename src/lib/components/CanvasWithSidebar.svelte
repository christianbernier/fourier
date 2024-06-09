<div>
  <slot name="canvas" />
	<slot name="sidebar" />
</div>

<style>
	div {
		display: flex;
		flex-direction: row;
		justify-content: center;
		gap: var(--margin-md);
	}

	@media only screen and (max-width: 850px) {
    div {
			flex-direction: column;
			gap: var(--margin-lg);
		}
	}
</style>
