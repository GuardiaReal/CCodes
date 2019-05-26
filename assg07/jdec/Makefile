.PHONY: clean coverage

jdec:jdec.c
	gcc -Wall -o jdec -std=gnu99 jdec.c

coverage:
	gcc -Wall -o jdec jdec.c -std=gnu99 -fprofile-arcs -ftest-coverage

clean:
	rm -f *.o jdec *.gcov *.gcno *.gcda
