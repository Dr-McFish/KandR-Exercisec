/* code from book */
/* copy-v2.c */

#include <stdio.h>

/* copy input to output; 2nd version */
main()
{
	int c;

	c = getchar();
	while(c != EOF) {
		putchar(c);
		c = getchar();
	}
}