
.PHONY: clean

all: main.o haizei_test.o unit.o
	g++ -I./ -L./lib -o haizei main.o haizei_test.o unit.o -lgtest -lpthread

main.o: main.cpp 
	g++ -c -I./ main.cpp

haizei_test.o: haizei_test.cc haizei_test.h
	g++ -c -I./ haizei_test.cc haizei_test.h

unit.o: unit.cpp unit.h
	g++ -c -I./ unit.cpp unit.h

clean:
	rm -rf ./a.out *.o *gch haizei
