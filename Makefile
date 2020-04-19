
tesf: tesf.o interface.o loadorder.o getmods.o paths.o
	gcc tesf.o interface.o loadorder.o getmods.o paths.o -lncurses -o tesf

tesf.o: tesf.c tesf.h
	gcc -c tesf.c

interface.o: interface.c tesf.h
	gcc -c interface.c

loadorder.o: loadorder.c tesf.h
	gcc -c loadorder.c

getmods.o: getmods.c tesf.h
	gcc -c getmods.c

paths.o: paths.c tesf.h
	gcc -c paths.c

clean:  
	rm *.o tesf

