#!/usr/bin/env bash

echo current dir is
pwd

script_dir="$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )"
cd "$script_dir"

cores=$(nproc)

echo "Will build with $cores cores"

if [ "$debug" = "1" ]; then
    version="DEBUG"
else
    version="RELEASE"
fi


/bin/notify --timeout 4 --icon '/boot/system/data/icons/haiku/mimetypes/64/image-x-portable-bitmap.svg' --type information --title "Building $version on $cores cores" "Folder: $script_dir" 

compiledb make -j$cores -Bwk debug=$debug

/bin/notify --timeout 4 --icon '/boot/system/data/icons/haiku/mimetypes/64/image-x-portable-bitmap.svg' --type information --title "Finished build" "DONE ! Check Folder: $script_dir" 
