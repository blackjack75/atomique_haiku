#!/usr/bin/env bash

export debug=1

script_dir="$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )"
cd "$script_dir"

source build_common.sh
