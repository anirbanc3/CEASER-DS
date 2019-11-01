#!/bin/bash

export GEM5_HOME=$1

mkdir $2/temp
cd $2/temp

cp -r $GEM5_HOME/configs ./povray
cp $GEM5_HOME/m2s-bench-spec2006/453.povray/povray_base.i386 ./povray
cp -r $GEM5_HOME/m2s-bench-spec2006/453.povray/data-ref/* ./povray

cd povray


${GEM5_HOME}/build/X86_MESI_Two_Level/gem5.opt ${GEM5_HOME}/configs/example/se.py --cmd=./povray_base.i386 --options="SPEC-benchmark-ref.ini" --ruby --caches --l2cache --l1d_assoc=4 --l2_assoc=8 --l1i_assoc=4 --cpu-type=TimingSimpleCPU --num-cpus=1 --mem-type=SimpleMemory  --maxinsts=25000000  -F 1000000000 --mem-size=512MB --network=simple --topology=Mesh_XY --mesh-rows=1 --num-dirs=1 --cacheline_size=64
