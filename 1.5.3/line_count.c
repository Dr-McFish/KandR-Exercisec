/* code form book */
/* line_count.c */

#include <stdio.h>

/* count lines in input */
main()
{
	int c, nl;

	nl = 0;
	while ((c = getchar()) != '\\')
		if (c == '\n')
			++nl;
	printf("%d\n", nl);
}
