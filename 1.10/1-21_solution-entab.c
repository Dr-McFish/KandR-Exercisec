/* 1-21_solution-entab.c  */
/* Write a program entab tha replaces strings of blanks minimum number of
tabs and blanks to achive the same spacing. Use the same tab stops as for
delta. When either a tab or a single blank would fufice to reach a tab
stop, which should be given preference? */

#include <stdio.h>

#define TAB_STOP 4

int main() {
	int current_column;
	int current_num_spaces;
	int i;
	char c;

	current_column = 0;
	current_num_spaces = 0;
	while ((c = getchar()) != EOF) {
		switch(c) {
			case ' ':
				current_num_spaces++;
				break;
			case '\n':
				putchar(c);
				current_column = 0;
				current_num_spaces = 0;
				break;
			default:
				if(current_num_spaces != 0) {
					while(current_num_spaces >= TAB_STOP) {
						putchar('\t');
						i = TAB_STOP - ((current_column) % TAB_STOP);
						current_column += i;
						current_num_spaces -= i;
					}
					i = TAB_STOP - (current_column % TAB_STOP);
					if( i == current_num_spaces && current_num_spaces > 1 ) {
						putchar('\t');
						current_num_spaces = 0;
						current_column += i;
					} else 
						for(;current_num_spaces > 0; current_num_spaces--) {
							putchar(' ');
							current_column++;
						}
				}
				putchar(c);
				if(c == '\t')
					current_column += TAB_STOP -((current_column) % TAB_STOP);
				else
					current_column++;
				current_num_spaces = 0;
				break;
		}
	}
}
