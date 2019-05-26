.PHONY: clean coverage

dna:dna.c
	gcc -Wall dna.c -o dna

coverage:
	gcc -Wall dna.c -o dna -fprofile-arcs -ftest-coverage

clean:
	rm -f dna *.o *.gcov *.gcno *.gcda

