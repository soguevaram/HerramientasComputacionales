all: fig.pdf

Makefiles.x: Makefiles.cpp

%.x: %.cpp
	g++ $< -o $@

datos.txt: Makefiles.x
	./$< > $@

fig.pdf: plot.gp datos.txt
	gnuplot $<

clean:
	rm -f a.out *.x *.txt *.pdf
