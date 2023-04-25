make: clean library

clean:
	rm -rf obj/* out/* lib/*

library:
	cd obj ;\
	gcc ../src/*.c -c -O2
	cd lib ;\
	ar rcs librotmatrix.a ../obj/*.o
	cp src/rotmatrix.h out/
	cp lib/librotmatrix.a out/