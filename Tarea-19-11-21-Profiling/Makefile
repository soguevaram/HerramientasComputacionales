EXE=transpose_blocking.x
CPPFLAGS=-g -pg -fsanitize=address -fsanitize=leak -fsanitize=undefined

all: $(EXE)

%.x : %.cpp
	g++ $(CPPFLAGS) $< -o $@

test1: $(EXE) 
	./$< 512 32

blocking.png: plot.gp bsize_total.txt
	gnuplot $<

clean:
	rm -rf a.out *.x *.x.dSYM *# *~
