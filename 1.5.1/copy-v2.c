/* code from book */
/* copy-v2.c */

#include <stdio.h>

/* copy input to output; 2nd version */
main()
{
	int c;
	
	while((c =getchar()) != EOF)
		putchar(c);
}