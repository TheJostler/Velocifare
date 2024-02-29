<script>
    export let poemLines = [
        "In the realm of code, where languages intertwine,",
        "There's a framework fair, with elegance divine,",
        "Svelte JS, with its charm so bright,",
        "A symphony of simplicity, a coder's delight."
    ];
</script>

<div>
    {#each poemLines as line}
        <p>{line}</p>
    {/each}
</div>

