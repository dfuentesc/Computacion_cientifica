# Configuración general
set terminal pngcairo size 1200,800 enhanced font "Helvetica,12"
set datafile separator whitespace
set key off
set grid
set style line 1 lc rgb '#0060ad' pt 7 ps 1   # Define estilo de punto

# Crear carpeta para gráficas
system "mkdir -p graficas"

# Obtener lista de archivos
filelist = system("ls resultados_probabilidad/*.txt")
filecount = words(filelist)

# Loop a través de todos los archivos
do for [i=1:filecount] {
    # Obtener nombre de archivo
    filename = word(filelist, i)
    
    # Extraer solo el nombre base para el título
    basefile = system("basename ".filename." .txt")
    
    # Configurar salida
    set output "graficas/".basefile.".png"
    
    # Títulos personalizados
    set title basefile
    set xlabel "Primera columna"
    set ylabel "Probabilidad"
    
    # Rango para eje Y (probabilidad entre 0 y 1)
    set yrange [0:1.1]
    
    # Graficar
    plot filename using 1:3 with points ls 1
}

print "Se generaron ".filecount." gráficas en la carpeta 'graficas'"