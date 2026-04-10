#!/bin/bash

if [ "$#" -ne 2 ]; then
	echo "Error, se necesita extrictamente 2 argumentos"
	exit 1
fi

echo "hello there"

sleep 30 &
PID=$!

echo "Proceso $PID termino"
