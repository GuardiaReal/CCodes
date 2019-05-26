.PHONY: clean coverage

maxPerLine:maxPerLine.c
	gcc -Wall maxPerLine.c -o maxPerLine -std=gnu99
coverage:
	gcc -Wall maxPerLine.c -o maxPerLine -std=gnu99 -fprofile-arcs -ftest-coverage
clean:
	rm -f maxPerLine *.gcov *.gcno *.gcda
