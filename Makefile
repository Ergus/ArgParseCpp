#####################################################
# Argparse example for reading command line arguments.
# This is a simple template example to simplify the
# Command Line reading arguments.
#
# Author: Jimmy Aguilar Mena
# June 6, 2018
#
# This is under GPL license.
#####################################################

all: argparse.x

argparse.x: main.cpp CommandLine.hpp
	g++ $^ -o $@ -I .

.PHONY: clean test

clean:
	rm -r *.x

test: argparse.x
	./$< 1 texto 3 4 texto2 6
	./$< 1 texto 3 4 texto2
	./$< 1 texto 3 4
	./$< 1 texto 3
