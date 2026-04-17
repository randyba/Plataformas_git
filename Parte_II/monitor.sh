#!/bin/bash

if [ "$#" -ne 2 ]; then
    echo "Error, se necesita exactamente 2 argumentos"
    echo "Uso: $0 <intervalo_segundos> <comando>"
    exit 1
fi

INTERVAL="$1"
CMD="$2"
PID=""
LOG_FILE=""
PNG_FILE=""
START_TIME=$(date +%s)

plot_results() {
    if ! command -v gnuplot >/dev/null 2>&1; then
        echo "gnupot no está instalado, no se puede generar la gráfica."
        return
    fi

    PNG_FILE="monitor_${PID}.png"
    gnuplot <<-EOF
        set terminal pngcairo size 900,500 enhanced font 'Arial,10'
        set output "${PNG_FILE}"
        set title "Monitoreo: ${CMD} (PID ${PID})"
        set xdata time
        set timefmt "%s"
        set format x "%H:%M:%S"
        set xlabel "Tiempo transcurrido (s)"
        set ylabel "CPU %"
        set y2label "RSS (KB)"
        set y2tics
        set grid
        set key left top
        set datafile separator "|"
        plot "${LOG_FILE}" using 1:3 with lines lw 2 title "CPU %" axis x1y1, \
             "${LOG_FILE}" using 1:5 with lines lw 2 title "RSS (KB)" axis x1y2
EOF

    echo "Gráfica generada: ${PNG_FILE}"
}

on_interrupt() {
    echo
    echo "SIGINT recibido: terminando proceso monitoreado ${PID}..."
    kill -TERM "${PID}" 2>/dev/null
    wait "${PID}" 2>/dev/null
    echo "Proceso ${PID} terminado tras SIGINT."
    plot_results
    exit 130
}

trap on_interrupt SIGINT

eval "${CMD}" &
PID=$!
LOG_FILE="monitor_${PID}.log"
> "${LOG_FILE}"
echo "# elapsed|timestamp|cpu|mem|rss" >> "${LOG_FILE}"

echo "Monitoreo iniciado. PID: ${PID}"
echo "Log guardado en: ${LOG_FILE}"

while kill -0 "${PID}" 2>/dev/null; do
    TIMESTAMP=$(date '+%Y-%m-%d %H:%M:%S')
    ELAPSED=$(( $(date +%s) - START_TIME ))
    METRICS=$(ps -p "${PID}" -o %cpu,%mem,rss --no-headers 2>/dev/null)

    if [ -n "${METRICS}" ]; then
        CPU=$(echo "${METRICS}" | awk '{print $1}')
        MEM=$(echo "${METRICS}" | awk '{print $2}')
        RSS=$(echo "${METRICS}" | awk '{print $3}')
        echo "${ELAPSED}|${TIMESTAMP}|${CPU}|${MEM}|${RSS}" >> "${LOG_FILE}"
    fi

    sleep "${INTERVAL}"
done

wait "${PID}" 2>/dev/null
echo "Proceso ${PID} terminó."
plot_results#!/bin/bash

if [ "$#" -ne 2 ]; then
	echo "Error, se necesita extrictamente 2 argumentos"
	exit 1
fi

echo "hello there"

sleep 30 &
PID=$!

echo "Proceso $PID termino"
