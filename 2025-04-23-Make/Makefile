# target: dependencias
# $< es para la primera dependencia
# $@ es el target
# $^ son todas las dependencias
# % todos los archivos

fig.pdf: script.gp data.txt
	gnuplot $< 

%.x : %.cpp
	g++ $< -o $@

data.txt : sumupdown.x
	./$< > $@ 

clean: 
	rm -f *.x a.out *.txt *pdf