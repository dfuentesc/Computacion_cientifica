#!/bin/bash
# Crear carpeta para resultados
# Crear carpeta para resultados
mkdir -p resultados_probabilidad
# Procesar cada archivo en la carpeta 'graficas'

for archivo in *.txt; do
    awk '{
        # Crear clave única: columna1-columna2
        clave = $1 " " $2
        
        # Contar total de ocurrencias de esta clave
        total[clave]++
        
        # Si la tercera columna es positiva (1)
        if ($3 == 1) {
            positivos[clave]++
            suma_cuarta[clave] += $4
        }
    }
    END {
        # Recorrer todas las claves únicas
        for (clave in total) {
            # Calcular probabilidad
            prob = positivos[clave] / total[clave]
            
            # Calcular promedio de la cuarta columna (solo para positivos)
            promedio_cuarta = positivos[clave] ? (suma_cuarta[clave] / positivos[clave]) : 0
            
            # Formatear salida: clave, probabilidad, promedio
            printf "%s %.4f %.4f\n", clave, prob, promedio_cuarta
        }
    }' "$archivo" > "resultados_probabilidad/prob_$archivo"
done
