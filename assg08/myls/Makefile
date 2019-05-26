.PHONY: clean coverage

myls: myls.c
	gcc -o myls -std=gnu99 myls.c
coverage:
	gcc -o myls -fprofile-arcs -ftest-coverage -std=gnu99 myls.c
clean:
	rm -f *.o myls *.gcov *.gcno *.gcda

