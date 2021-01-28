/* solution to 1-10 */
/* 1-10_solution.c / escp.exe */
#include <stdio.h>

/* copy input to output and replases tabs backcpace and
 * backslashes with thier escape sequences */
main()
{
	int c;
	while((c =getchar()) != EOF) {
		if (c == '\t') {
			putchar('\\');
			putchar('t');
			/* putchar('\t'); /* this makes it more readable */
		} else if (c == '\b') {
			putchar('\\');
			putchar('b');
		} else if (c == '\\') {
			putchar('\\');
			putchar('\\');
		} else
			putchar(c);
	}
}