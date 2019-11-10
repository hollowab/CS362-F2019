#CFLAGS= -Wall -fpic -coverage -lm -std=c99

testme: testme.c
	gcc -o testme testme.c -coverage -fpic -lm
	./testme

clean: 
	rm -f *.o testme *.gcov *.gcda *.gcno *.so *.out