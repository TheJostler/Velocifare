#!/bin/bash

dir="site/build"

cd $dir
find . -name *.js -o -name *.html -o -name *.css | while read f
do
    # Input and output file paths
    input_file="$f"
    no_slash="$(echo ${f////_})"
    no_dot="$(echo ${no_slash//./_})"
    output_file="../../views/static/$no_slash.c"
    header_file="../../views/static/headers/views.h"
    function_name=render_$no_dot
    path=$(echo $f | tail -c +2)

    echo "
    #include <unistd.h>
    #include \"../server/headers/network.h\"
    #include \"../server/headers/kernel.h\"

    int $function_name() {
        char *page[] = {
        " > $output_file
    # Read each line from input file, add backslash before double quotes, wrap with double quotes, and write to output file
    while IFS= read -r line; do
        # Escape existing double quotes with a backslash
        escaped_line=$(echo "$line" | sed 's/"/\\"/g')
        # Wrap the line with double quotes
        modified_line="		\"$escaped_line\","
        echo "$modified_line" >> "$output_file"
    done < "$input_file"

    # Add the final part
    echo "	};
    for (int l=0; l<(sizeof(page)/sizeof(page[0])); l++) {
        put(page[l], peer);
    }
    return 0;
    }" >> $output_file

    echo "
    void $function_name();" >> $header_file
done
