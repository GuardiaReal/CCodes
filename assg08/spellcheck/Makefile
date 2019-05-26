.PHONY: clean coverage

spellcheck: spellcheck.c
	gcc  -Wall -o  spellcheck -std=gnu99 spellcheck.c
coverage:
	gcc -Wall -o spellcheck -std=gnu99 -fprofile-arcs -ftest-coverage spellcheck.c
clean:
	rm -f *.o spellcheck *.gcov *.gcno *.gcda
