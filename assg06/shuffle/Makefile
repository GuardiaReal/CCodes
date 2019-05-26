.PHONY: coverage clean

shuffle: shuffle.c
	gcc -Wall -o shuffle shuffle.c -std=gnu99

coverage:
	gcc -Wall -o shuffle shuffle.c -fprofile-arcs -ftest-coverage -std=gnu99

clean: 
	rm -f *.gcov shuffle *.gcno *.gcda *.o
