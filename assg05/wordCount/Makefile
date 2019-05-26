.PHONY: clean coverage
 
wordCount: wordCount.c
	gcc -Wall wordCount.c -o wordCount -std=gnu99 
coverage: wordCount.c 
	gcc -Wall wordCount.c -o wordCount -std=gnu99 -fprofile-arcs -ftest-coverage
clean:
	rm -f wordCount *.gcov *.gcno *.gcda

