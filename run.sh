#!/bin/bash

cc $(find . -type f -name '*.c' -print0 | xargs -0 stat -f "%m %N" | sort -rn | head -1 | cut -f2- -d" " ) && ./a.out
