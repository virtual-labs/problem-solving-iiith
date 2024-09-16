#!/bin/bash

# This command applies the gtm-patcher.py script to each html and php file
# recursively in the directory where it is executed.  As this intended
# applying analytics code to each lab and experiment file, this script
# should be executed in the src/ directory.

# Any html file that starts with 'content' in its name, will be ignored
# by the script as applying the script to these files breaks the page
# structure.

# The gtm-patcher.py file comes from vlabs-analytics project which
# can be found here: https://github.com/virtual-labs/vlabs-analytics

# NOTE: This command will change the src files.

find . -type f \
     \( \
     \( -name "*.html" -or -name "*.php" \) \
     ! -name "content*.html" \
     \) \
     -exec ../scripts/gtm-patcher.py {} \;
