/* solution 1-12 */
/* 1-12_solution.c */

#include <stdio.h>

#define IN 1
#define OUT 0

/* count lines, words, and characters in input */
main()
{
	char c, state;

	state = OUT;
	while ((c = getchar()) != EOF) {
		
		if (c == ' ' || c == '\n' || c == '\t') 
			putchar('\n');
		else 
			putchar(c);	
	}
}