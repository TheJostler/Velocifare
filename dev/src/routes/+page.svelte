<script>
    import Poem from './poem.svelte';

  let count = 0;

  function increment() {
    count += 1;
  }
</script>

<div>
    <h1>Ode To Svelte</h1>
    <Poem />

    <div class="container">
    <button on:click={increment} class="button">Click me</button>
    <p>Count: {count}</p>
  </div>
</div>

<style>
    /* Styles for the page */
    h1 {
        text-align: center;
        font-size: 24px;
        margin-bottom: 20px;
    }

    .container {
    display: flex;
    justify-content: center;
    align-items: center;
    height: 200px;
  }

  .button {
    background-color: #61dafb;
    color: #fff;
    padding: 10px 20px;
    font-size: 1em;
    cursor: pointer;
    border: none;
    border-radius: 5px;
  }
</style>

