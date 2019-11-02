#!/bin/bash

export GEM5_HOME=$1

mkdir $2/temp
cd $2/temp

cp -r $GEM5_HOME/configs ./gcc 
cp $GEM5_HOME/m2s-bench-spec2006/403.gcc/gcc_base.i386 ./gcc
cp -r $GEM5_HOME/m2s-bench-spec2006/403.gcc/data-ref/* ./gcc
cd gcc

${GEM5_HOME}/build/X86_MESI_Two_Level/gem5.opt $GEM5_HOME/configs/example/se.py --cmd=./gcc_base.i386 --options="166.i -o 166.s" --ruby --caches --l2cache --l1d_assoc=8 --l2_assoc=16 --l1i_assoc=4 --cpu-type=TimingSimpleCPU --num-cpus=1 --mem-type=SimpleMemory  --maxinsts=2500000  -F 1000000000 --mem-size=4GB --network=simple --topology=Mesh_XY --mesh-rows=1 --num-dirs=1 --cacheline_size=64

mv /temp/gcc/m5out $GEM5_HOME/gcc
