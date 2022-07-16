/* 1-20_solution_deltab.c */
/* Write a program deltab that replaces  tabs in the input with the proper number  of blanks to space to the next tab stop. Assume  a fixed ser of tab stops, say every n columns. Should n be a variable or a symbolic parameter. */

#include <stdio.h>

#define TAB_STOP 4

int main() {
	int current_space;
	char c;

	current_space = 0;
	while ((c = getchar()) != EOF) {
		switch(c) {
			case '\t':
				/* handle it. insert proper number of spaces */
				putchar(' ');
				for(current_space++; (current_space % TAB_STOP ) != 0; current_space++) {
					putchar(' ');
				}
				break;
			case '\n':
				putchar(c);
				current_space = 0;
				break;
			default:
				putchar(c);
				current_space++;
				break;
		}
	}
}
