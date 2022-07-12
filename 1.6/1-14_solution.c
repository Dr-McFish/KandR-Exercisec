/* solution to 1-14 */
/* print histogram of the frequencies of different charechters in it's input */

#include <stdio.h>
#include <string.h>

#define MAX_BAR_WIDTH 70
#define START_WITH ' '

int min(int a, int b) {	
	return a < b ? a : b;
}
int max(int a, int b) {	
	return a > b ? a : b;
}

main()
{
	char c; 
	int i, j;
	int div_factor, most_used;
	int chars_count[127];

	for (i = START_WITH; i < 127; i++)
		chars_count[i] = 0;	

	while ((c = getchar()) != EOF) {
	
		if (c >= 0)
			chars_count[c]++;
	}

	most_used = 0;
	for (i = START_WITH; i < 128; i++)
		most_used = max(most_used, chars_count[i]);
	div_factor = max(1, most_used / MAX_BAR_WIDTH);
	for (i = START_WITH; i < 128; i++)
		chars_count[i] /= div_factor;

	printf("Histogram of charecter frequency\n");
	for (i = START_WITH; i < 128; i++)
	{
		 switch(i) {
			case('\n'):
				printf("\\n :");
				break;
			case(' '):
				printf("SPC:");	
				break;
			case('\t'):
				printf("\\t :");	
				break;
			default:
				printf("%c  :", i);
				break;
		}
		for (j = 0; j < chars_count[i]; j++)
			printf("#");
		printf("\n");
	}
}
