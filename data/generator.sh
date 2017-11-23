#!/bin/bash
PPATH=$(realpath ..)
. ../../testdata_tools/gen.sh

setup_dirs
use_solution dpSegTree.cpp
compile generator.py

samplegroup
sample 1
sample 2

group g1 12
tc g1-1 generator n=1 iWidth=1
tc g1-2 generator n=2 iWidth=1
tc g1-3 generator n=10 iWidth=1
tc g1-4 generator n=10 iWidth=1
tc g1-5 generator n=10 iWidth=1
tc g1-6 generator n=10 iWidth=1

group g2 11
include_group g1
tc g2-1 generator n=500 iWidth=1
tc g2-2 generator n=500 iWidth=1
tc g2-3 generator n=500 iWidth=1
tc g2-4 generator n=500 iWidth=1 genType=2
tc g2-5 generator n=500 iWidth=1 genType=2
tc g2-6 generator n=500 iWidth=1 genType=2

group g3 10
include_group g1
include_group g2
tc g3-1 generator n=500
tc g3-2 generator n=500
tc g3-3 generator n=500
tc g3-4 generator n=500 genType=2
tc g3-5 generator n=500 genType=2
tc g3-6 generator n=500 genType=2

group all 67
include_group g1
include_group g2
include_group g3
tc all-1 generator
tc all-2 generator
tc all-3 generator
tc all-4 generator
tc all-5 generator
tc all-6 generator genType=2
tc all-7 generator genType=2
tc all-8 generator genType=2
tc all-9 generator genType=2
tc all-10 generator genType=2

generate_grader
cleanup_programs
