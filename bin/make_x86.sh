#!/bin/bash
mkdir x86;
cp -R aarch64/* x86
cd x86
mv a-le a
mv a-le-g a-g
mv o-le o
mv o-le-g o-g
