#!/bin/bash

#This is the directory that contains your html, js, and css files
dir="dev/build"

r="$(cd -- "$(dirname -- "${BASH_SOURCE[0]}")" &> /dev/null && pwd)"
cd $dir
if [ ! -d $r/views/static ]
then
	mkdir $r/views/static
	mkdir $r/views/static/headers
else
	rm $r/views/static/* 2&> /dev/null
fi

header_file="$r/views/static/headers/views.h"
static_routes="$r/routes/static-routes.c"

echo "" > $header_file

echo "
#include \"../views/static/headers/views.h\"
#include \"../views/headers/views.h\"
#include \"../server/headers/http.h\"

// This file was generated at build time by the $0 script

int static_routes() {
" > $static_routes

find . -name *.js -o -name *.html -o -name *.css | while read f
do
    # Input and output file paths
    input_file="$f"
    path=$(echo $f | tail -c +2)
    no_slash="$(echo ${path////_})"
    no_slash_dash="$(echo ${no_slash//-/_})"
    no_dot="$(echo ${no_slash_dash//./_})"
    output_file="$r/views/static/$no_slash_dash.c"
    function_name=render_$no_dot

    echo "
    #include <unistd.h>
    #include \"../../server/headers/network.h\"
    #include \"../../server/headers/kernel.h\"

    int $function_name() {
        char *page[] = {
        " > $output_file
    # Read each line from input file, add backslash before double quotes, wrap with double quotes, and write to output file
    while IFS= read -r line; do
        # Escape existing double quotes with a backslash
        escaped_line=$(echo "$line" | sed 's/"/\\"/g')
        # Wrap the line with double quotes
        modified_line="\"$escaped_line\","
        echo "$modified_line" >> "$output_file"
    done < "$input_file"

    # Add the final part
    echo "};int n = sizeof(page)/sizeof(page[0]);return put(page, n);}" >> $output_file

    # Register the function name in the static views header file
    echo "int $function_name();" >> $header_file

    #Register the new route in the static-routes file
    echo "if (isroute(\"GET\", \"$path\")) return $function_name();" >> $static_routes
done

# Finalize the the static routes file
echo "http_status = 404;return render_404();}" >> $static_routes
