/* 1-20_solution_deltab.c */
/* Write a program deltab that replaces  tabs in the input with the proper
 numberof blanks to space to the next tab stop. Assume  a fixed ser of tab
 stops, say every n columns. Should n be a variable or a symbolic parameter. */

#include <stdio.h>

#define TAB_STOP 4

int main() {
	int current_column;
	char c;

	current_column = 0;
	while ((c = getchar()) != EOF) {
		switch(c) {
			case '\t':
				/* handle it. insert proper number of spaces */
				putchar(' ');
				for(current_column++; (current_column % TAB_STOP ) != 0; current_column++) {
					putchar(' ');
				}
				break;
			case '\n':
				putchar(c);
				current_column = 0;
				break;
			default:
				putchar(c);
				current_column++;
				break;
		}
	}
}
