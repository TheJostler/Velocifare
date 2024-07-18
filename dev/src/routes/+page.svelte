<script>
  import Pages from './pages.svelte';
</script>

<div class="header">
  <h1>Welcome to the Velocifare Wiki</h1>
</div>
<article>
  <div class="tableofcontents">
    <h2>Contents</h2>
    <div class="bubble">
      <Pages />
    </div>
  </div>

  <div class="" id="set-up">
    <h2>Setup tutorial</h2>

    <p>Here I will teach you how to install and build your website in Velocifare</p>

    <ol>
      <li>1. Clone the repository:</li><span class="code">`git clone https://github.com/TheJostler/velocifare`</span>
      <li>2. Navigate to the project directory:</li><span class="code">`cd velocifare/dev`</span>
      <li>3. Install node packages for the demo app with:</li><span class="code">`npm install`</span>
      <li>4. Navigate back to the parent directory:</li><span class="code">`cd ..`</span>
      <li>5. Build the project using the provided MakeFile:</li><span class="code">`make build`</span><br><span class="code">`make rebuild`</span> to force a rebuild
      <li>6. Run the compiled binary executable:</li><span class="code">`./demo`</span>
    </ol>
  </div>
</article>