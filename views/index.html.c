#include "headers/views.h"

int render_index() {
	char *page[] = {
	
		"<!doctype html>",
		"<html lang=\"en\">",
		"	<head>",
		"		<meta charset=\"utf-8\" />",
		"		<meta name=\"viewport\" content=\"width=device-width, initial-scale=1\" />",
		"		",
		"	</head>",
		"	<body data-sveltekit-preload-data=\"hover\">",
		"		<div>  <h1 data-svelte-h=\"svelte-15pgwlj\">Welcome to Site in C Feat. Svelte</h1> <p data-svelte-h=\"svelte-td5yc3\">This site is a working static Svelte app that is compiled by SiteInC into the webserver itself. The webapp and server are compiled directly into a single executable file.</p> <p data-svelte-h=\"svelte-1gcp1ig\">Create your package using @sveltejs/package and preview/showcase your work with SvelteKit</p> <p data-svelte-h=\"svelte-jl9sbz\">Visit <a href=\"https://kit.svelte.dev\">kit.svelte.dev</a> to read the documentation</p> ",
		"			",
		"		</div>",
		"	</body>",
		"</html>",
	};
	int n = sizeof(page)/sizeof(page[0]);
	return put(page, n);
}
