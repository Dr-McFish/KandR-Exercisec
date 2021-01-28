/* solution to 1-8 */
/* 1-8_solution.c */

#include <stdio.h>

/* count lines in input */
main()
{
	int c, nl, s, t;

	nl = 1;
	s = 0;
	t = 0;
	while ((c = getchar()) != EOF) {
		if (c == '\n') 
			nl++;
		else if (c == ' ')
			s++;
		else if (c == '\t')
			t++;
	}
	printf("This file had:\t");
	printf("%d lines\n", nl);
	printf("\t\t%d spases\n", s);
	printf("\t\t%d tabs\n", t);
}
