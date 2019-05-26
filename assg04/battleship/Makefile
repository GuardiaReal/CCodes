.PHONY: coverage clean

battleship:battleship.c
	gcc -Wall battleship.c -o battleship -std=c99
coverage:
	gcc battleship.c -o battleship -std=c99 -fprofile-arcs -ftest-coverage
clean:
	rm -f *.o *.gcov *.gcno *.gcda battleship
