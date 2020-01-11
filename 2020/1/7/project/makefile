
.PHONY: clean

all: main.o haizei/test.o
	g++ -o ./bin/haizei main.o haizei/test.o

main.o: main.cpp
	g++ -I./ -c main.cpp

haizei/test.o: haizei/test.h haizei/test.cc
	g++ -I./ -c haizei/test.cc -o haizei/test.o

clean:
	rm -rf ./a.out *.o haizei/*.o bin/haizei
