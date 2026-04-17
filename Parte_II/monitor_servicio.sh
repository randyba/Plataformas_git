#!/bin/bash

LOG_FILE="/var/log/monitor_sistema.log"
INTERVAL=5

# Crear archivo si no existe
if [ ! -f "$LOG_FILE" ]; then
    touch "$LOG_FILE"
fi

# Bucle infinito
while true; do
    TIMESTAMP=$(date '+%Y-%m-%d %H:%M:%S')

    # Obtener los 5 procesos con mayor uso de CPU
    ps -eo pid,comm,%cpu,%mem --sort=-%cpu | head -n 6 | tail -n 5 | while read PID NAME CPU MEM; do
        echo "${TIMESTAMP}|${PID}|${NAME}|${CPU}|${MEM}" >> "$LOG_FILE"
    done

    sleep "$INTERVAL"
done
