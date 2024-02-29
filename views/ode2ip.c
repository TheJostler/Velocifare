#include "headers/views.h"

int render_ode2ip() {
    http_type = "text/html";
    http_respond();
    
    char *page[] = {
        "<html>",
            "<body>",
                "<h1>Ode To IP</h1>",
                "<p>In realms of cyberspace, where data streams doth flow,</p>",
                "<p>Where routers stand as sentinels in lines aglow,</p>",
                "<p>A dance of packets, swift and free,</p>",
                "<p>Through cables unseen, 'neath the deep sea.</p>",
                "<br>",
                "<p>Like stars that twinkle in the midnight sky,</p>",
                "<p>IP addresses gleam, as they pass by,</p>",
                "<p>Each one a beacon, a digital guide,</p>",
                "<p>In the vast expanse, where connections abide.</p>",
                "<br>",
                "<p>Subnets like gardens, neatly arrayed,</p>",
                "<p>Masking the paths where packets parade,</p>",
                "<p>Gateways like portals to realms unknown,</p>",
                "<p>Where routers reign, on their thrones of stone.</p>",
                "<br>",
                "<p>Yet amidst this digital tapestry so grand,</p>",
                "<p>Lies the heart of networking, a wondrous band,</p>",
                "<p>For in the exchange of bits and bytes,</p>",
                "<p>Lies the power to connect, to unite.</p>",
                "<br>",
                "<p>Oh, let us marvel at this intricate art,</p>",
                "<p>Where data flows freely, a symphony's start,</p>",
                "<p>In the world of IP networking, let us find,</p>",
                "<p>A modern ode to connectivity, one of a kind.</p>",
            "</body>",
        "</html>",
    };
	int n = sizeof(page)/sizeof(page[0]);
	return put(page, n);
}
