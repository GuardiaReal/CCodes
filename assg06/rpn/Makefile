.PHONY: clean coverage

rpn: rpn.c
	gcc -Wall -o rpn rpn.c

coverage:
	gcc -Wall -o rpn -fprofile-arcs -ftest-coverage rpn.c

clean:
	rm -f rpn *.o *.gcov *.gcda *.gcno
