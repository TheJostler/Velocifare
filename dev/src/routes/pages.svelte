<script>
    export let pages = [
        {id:"set-up", name:"Set up tutorial"}
    ]
</script>

<div id="pages">
    {#each pages as page}
        <a href="#{page.id}">{page.name}</a>
    {/each}
</div>