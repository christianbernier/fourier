<div id="page_buffer">
  <div id="content_container">
    <h1>Fourier Fun!</h1>
    <noscript>
      <p id="noscript">Your browser does not support JavaScript!</p>
      <style>.js_only { display: none; }</style>
    </noscript>
    <div class="js_only">
      <slot></slot>
    </div>
  </div>
</div>

<style>
  #page_buffer {
    display: flex;
    justify-content: center;
  }

  #content_container {
    max-width: 1000px;
  }

  #noscript {
    color: var(--color-error);
    margin: 5px 0;
    font-weight: bold;
  }

  h1 {
    margin: var(--margin-md) 0;
  }
  @media only screen and (max-width: 850px) {
    h1 {
			text-align: center;
		}
	}
</style>
