#!/bin/bash

cd /mnt/repo/gem5

scons build/X86_MESI_Two_Level/gem5.opt -j4 PROTOCOL=MESI_Two_Level
