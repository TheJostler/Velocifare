#!/bin/bash

dir="site/build"

#find site/build -name *.js -o -name *.html -o -name *.css | while read f
#do
# Input and output file paths
input_file="$dir/$1"
output_file="views/$1.c"
header_file="views/headers/$1.h"
function_name=$2

echo "
#include <unistd.h>
#include \"../server/headers/network.h\"
#include \"../server/headers/kernel.h\"

int $function_name(int soc) {
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
}" >> $output_file

echo "
void $function_name(int soc);" > $header_file

