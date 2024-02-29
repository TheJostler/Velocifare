#!/bin/bash

#This is the directory that contains your html, js, and css files
dir="dev/build"

echo "== Compiling your project =="
echo ""

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

echo "#include <unistd.h>
#include \"../../../server/headers/network.h\"
#include \"../../../server/headers/kernel.h\"
#include \"../../../server/headers/http.h\"" > $header_file

echo "
#include \"../views/static/headers/views.h\"
#include \"../views/headers/views.h\"
#include \"../server/headers/http.h\"

// This file was generated at build time by the $0 script

int static_routes() {
" > $static_routes

find . -name "*.js" -o -name "*.html" -o -name "*.css" -o -name "*.png"| while read f
do
    # Input and output file paths
    input_file="$f"
    input_file_ext="$(echo $input_file | rev | cut -d '.' -f 1 | rev)"
    path=$(echo $f | tail -c +2)
    no_slash="$(echo ${path////_})"
    no_slash_dash="$(echo ${no_slash//-/_})"
    no_dot="__$(echo ${no_slash_dash//./_} | tail -c +2)"
    output_file="$r/views/static/$no_slash_dash.c"
    function_name=render$no_dot

    case $input_file_ext in
        "html")
            ftype="text/html"
        ;;
        "js")
            ftype="text/javascript"
        ;;
        "css")
            ftype="text/css"
        ;;
	"png")
	    ftype="image/png"
	;;
    esac

    echo "Compiling - $path"

    echo "
    #include \"headers/views.h\"
    

    int $function_name() {
        http_type=\"$ftype\";
        http_respond();
        
        " > $output_file
	xxd --include $input_file >> $output_file
	echo "write(peer, $no_dot, $no_dot""_len);return 0;}" >> $output_file

    # Register the function name in the static views header file
    echo "int $function_name();" >> $header_file

    #Register the new route in the static-routes file
    echo "if (isroute(\"GET\", \"$path\")) return $function_name();" >> $static_routes
done

# Finalize the the static routes file
echo "http_status = 404;return render_404();}" >> $static_routes

echo "Compiling - done\n"
