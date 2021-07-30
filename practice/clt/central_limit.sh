#!/bin/bash
#Dont forget to do chmod +x ./central_limit.sh first
echo -e "Compiling"
mpicxx -std=c++11 -O0 -o clt central_limit.cpp 2> err_log

rc=$?
if [[ $rc != 0 ]]; then
    echo -e "Error : mpicxx returned"
    cat err_log
    echo "success false"
    rm -rf out
    exit $rc
fi
echo "Compilation is OK"
echo -e "Execution ... "

mpirun -np 20 ./clt > norm
python3 check_clt.py
rm -rf clt
