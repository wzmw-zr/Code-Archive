

.PHONY: clean

all : main.o haizei/test.o
	g++ -o ./bin/haizei main.o haizei/test.o

main.o:
	g++ -I./ -c main.cpp

haizei/test.o: haizei/test.h haizei/test.cc
	g++ -I./ -c haizei/test.cc -o haizei/test.o

clean:
	rm -rf ./a.out ./main.o ./haizei/test.o ./bin/haizei
