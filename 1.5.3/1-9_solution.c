/* solution to 1-9 */
/* 1-9_solution.c / shrspc.exe */

#include <stdio.h>

/* copy input to output and shorten spaces */
main()
{
	int c;
	char isSpace;
	#define false 0
	#define true 1
	
	while((c =getchar()) != EOF) {
		if (!isSpace || c != ' ')
			putchar(c);

		if (c == ' ')
			isSpace = true;
		else
			isSpace = false;
	}
}