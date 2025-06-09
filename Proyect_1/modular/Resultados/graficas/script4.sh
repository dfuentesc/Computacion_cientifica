cd resultados_probabilidad

# Ordenar cada archivo por la primera columna (numérica, decimal)
for archivo in prob_*.txt; do
    sort -k1,1g "$archivo" -o "$archivo"
done