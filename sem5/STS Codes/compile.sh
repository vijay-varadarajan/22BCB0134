#!/bin/bash

# .java files 

files=("main" "simpleSieve" "segementedSieve" "eulerPhi" "stroboGrammatic" "remainderTheroem" "toggleSwitch" "aliceApple")


# Iterating through file names
for file in "${files[@]}" ; do

    javac "$file.java"

done
