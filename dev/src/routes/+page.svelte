<div>
  <canvas></canvas>
  <canvas></canvas>

  <div class="card">
    <h1 class="neon">Happy</h1>
    <h1 class="flux">Anniversary</h1>
    <div class="paragraph">
      <p>I promise to love you</p>
      <p>When your jokes are not funny.</p>
      <p>I promise to love you </p>
      <p>When you have no money. </p>
      <p>I promise to love you</p>
      <p>When you’re sick and all snotty.</p>
      <p>I'll always love you,</p>
      <p>Whether it's rainy or sunny</p>
    </div>
    <div class="paragraph">
      <p>Happy Anniversary, my love!</p>
      <p>Your one and only Joshy</p>
    </div>
  </div>
</div>  
<script>
  import { onMount } from 'svelte';
  import neonbg from '../scripts/neon.js';

  onMount(() => {
    neonbg();
  });
</script>