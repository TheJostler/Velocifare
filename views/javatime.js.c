#include "headers/views.h"

int render_javatime_js() {
    http_type = "text/javascript";
    http_respond();
    
    char *page[] = {
        "async function getHTML() {",
            "return fetch('ode2ip')",
            ".then(function(response) {",
                "return response.text()",
            "})",
            ".then(function(html) {",
                "var parser = new DOMParser();",
                "var doc = parser.parseFromString(html, \"text/html\");",
                "return doc.innerHTML;",
            "});",
        "}",
        "async function fillBox() {",
            "box.innerHTML = await getHTML();",
        "}",
        "var box = document.getElementById('test');",
        "box.innerHTML = \"<h1>Loading...</h1>\";",
        "fillBox();",
    };
	int n = sizeof(page)/sizeof(page[0]);
	return put(page, n);
}