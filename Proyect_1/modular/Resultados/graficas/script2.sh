#!/bin/bash
for archivo in *.txt; do
    sort -k1,1n "$archivo" > tmp && mv tmp "$archivo"
done