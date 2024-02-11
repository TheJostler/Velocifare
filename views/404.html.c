#include "headers/views.h"

int render_404() {

	http_status = 404;
	http_respond();

	char *page[] = {
	
		"<!doctype html>",
		"<html lang=\"en\">",
		"	<head>",
		"		<meta charset=\"utf-8\" />",
		"		<link rel=\"icon\" href=\"./favicon.png\" />",
		"		<meta name=\"viewport\" content=\"width=device-width, initial-scale=1\" />",
		"		",
		"	</head>",
		"	<body data-sveltekit-preload-data=\"hover\">",
		"		<div>  <h1 data-svelte-h=\"svelte-15pgwlj\">404 Not found</h1> <p data-svelte-h=\"svelte-td5yc3\">Not Found</p> <p data-svelte-h=\"svelte-1gcp1ig\">Create your package using @sveltejs/package and preview/showcase your work with SvelteKit</p> <p data-svelte-h=\"svelte-jl9sbz\">Visit <a href=\"https://kit.svelte.dev\">kit.svelte.dev</a> to read the documentation</p> ",
		"			",
		"			<script>",
		"				{",
		"					__sveltekit_wt6hr3 = {",
		"						base: new URL(\".\", location).pathname.slice(0, -1)",
		"					};",
		"",
		"					const element = document.currentScript.parentElement;",
		"",
		"					const data = [null,null];",
		"",
		"					Promise.all([",
		"						import(\"./_app/immutable/entry/start.c3pWsHWM.js\"),",
		"						import(\"./_app/immutable/entry/app.4o45qfuJ.js\")",
		"					]).then(([kit, app]) => {",
		"						kit.start(app, element, {",
		"							node_ids: [0, 2],",
		"							data,",
		"							form: null,",
		"							error: null",
		"						});",
		"					});",
		"				}",
		"			</script>",
		"		</div>",
		"	</body>",
		"</html>",
	};
	int n = sizeof(page)/sizeof(page[0]);
	return put(page, n);
}
