
tesf: tesf.o interface.o loadorder.o getmods.o paths.o modinstaller.o
	gcc tesf.o interface.o loadorder.o getmods.o paths.o modinstaller.o -lncurses -o tesf

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

modinstaller.o: modinstaller.c tesf.h
	gcc -c modinstaller.c

install: tesf
	mkdir -p ${HOME}/.config/tesf-loadorder
	cp -f tesf /usr/bin

uninstall:
	rm -f /usr/bin/tesf

clean:  
	rm *.o tesf

