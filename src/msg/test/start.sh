#!/bin/bash
export LD_LIBRARY_PATH=`pwd`/lib:$LD_LIBRARY_PATH
export PYTHONPATH=`pwd`/lib:`pwd`/bin:`pwd`/test:$PYTHONPATH

sysctl -w net.core.wmem_max=10485760
sysctl -w net.core.rmem_max=10485760
sysctl -w net.core.rmem_default=10485760
sysctl -w net.core.wmem_default=10485760

./bin/node --add 127.0.0.1
