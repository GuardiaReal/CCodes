.PHONY: clean coverage

median: median.c
	gcc -Wall -o median median.c -std=gnu99

coverage: 
	gcc -Wall -o median median.c -fprofile-arcs -ftest-coverage -std=gnu99

clean:
	rm -f *.o median *.gcov *.gcno *.gcda 

