
.PHONY: clean

all: main.o ./lib/haizei_test.o ./lib/unit.o
	gcc  -L./lib -o ./bin/haizei_test main.o haizei_test.o unit.o -lgtest -lpthread
	./bin/haizei_test

main.o: main.c 
	gcc -c -I./include main.c

./lib/haizei_test.o: ./src/haizei_test.c ./include/haizei_test.h
	gcc -c -I./include ./src/haizei_test.c ./include/haizei_test.h 

./lib/unit.o: ./src/unit.c ./include/unit.h
	gcc -c -I./include ./src/unit.c ./include/unit.h 

clean:
	rm -rf ./a.out *.o *gch ./include/*gch ./bin/haizei_test
