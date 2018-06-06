Readme
======

Simple command line argument parser using only C++ templates. 
This bare simple version parses the command line in the constructor of command line arguments declaration.

The version will be improved in the future to follow a similar logic than the
bash version. But now it already supports *mandatory* and *optional* parameters.

Now there are two different interfaces for the constructors. A template function and some macros.

The main advantage with the macros is that the parameter name is automatically converted to string.

The **main.cxx** example shows how to use it. 

**Author:** Jimmy Aguilar Mena

**Date:** June 6, 2018

