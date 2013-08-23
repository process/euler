#!/bin/bash
# Finds the solution to the given problem number
# If the solution finder is not built, it will be done

set -e

if [ ! -d bin/ ]
then
  mkdir bin
fi

if [ -f src/$1/*.py ]
then
  python src/$1/*.py
else
  g++ -o bin/$1 -lgmp src/$1/*
  ./bin/$1
fi

