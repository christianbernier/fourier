<a href="/">Back home</a>
<h2>How does this work?</h2>
<p>
	This is a demonstration of a concept known as the Discrete Fourier Transform (DFT) in the complex plane. Essentially, DFT is a way of converting a periodic singal from a time domain into a frequency domain.
</p><p>
	On this site, a path (created from a finite number of points, shown in blue) is the input function. This function is then approximated via trigonometric interpolation using DFT, resulting in a series of epicycles (points moving around circles at constant speeds). These are displayed to trace out the approximation!
</p><p>
	If you'd like to learn more about the math behind epicycles and DFT, check out <a href="https://mathed.miamioh.edu/index.php/ggbj/article/view/197/159">this paper</a> by Juan Carlos Ponce Campuzano describing the process. I found it helpful in creating this site!
</p>

<h2>How does this happen so fast?</h2>
<p>
	Short answer: computers are fast at math :)
</p><p>
	Longer answer: The cool thing about DFT is that every calculation that occurs is addition, subtraction, multiplication, division, or trigonometric functions. Computers are well-optimized for these operations (as opposed to more complicated ones like integrals), so they happen very fast. Additionally, this site compiles C++ code to WebAssembly, essentially allowing fast C++ code to run in your web browser! This makes the calculation process much faster than if it happened in JavaScript.
</p>

<h2>Who made this site?</h2>
<p>
	Hello! My name is <a href="https://cbernier.com">Christian Bernier</a>, and I'm a student studying computer science and physics. I have long been interested in this phenomenon, ever since <a href="https://www.youtube.com/watch?v=r6sGWTCMz2k">the 3Blue1Brown video on the topic</a>. I thought this site would be a fun way to learn more about the discrete Fourier transform, try my hand at WebAssembly, and share the cool math with my friends and family. I hope you enjoy it!
</p>

<h2>References</h2>
<p>
	I was inspired to make this site after watching <a href="https://www.youtube.com/watch?v=r6sGWTCMz2k">this excellent YouTube video</a> from 3Blue1Brown! I followed <a href="https://mathed.miamioh.edu/index.php/ggbj/article/view/197/159">this paper</a> to learn about the math behind epicycles and DFT. I also got the coordinates for the square path from this paper. I used <a href="https://dsp.stackexchange.com/questions/59068/how-to-get-fourier-coefficients-to-draw-any-shape-using-dft">the set of coordinates from this post</a> from a user named Chris on StackExchange for the pi path.
</p>

<style>
	a, h2, p {
		padding: 0 5%;
	}

	p > a {
		padding: 0;
	}

	h2 {
		margin: var(--margin-lg) 0 var(--margin-md) 0;
	}

	p {
		margin-bottom: var(--margin-md);
		max-width: min(80ch, 90%);
	}
</style>
