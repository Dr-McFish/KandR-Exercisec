/* code from book */
/* wordcount.c */

#include <stdio.h>
#include <string.h>

#define IN 1
#define OUT 0
#define MAXLENGTH 12
#define MAX_BAR_WIDTH 70

int min(int a, int b) {	
	return a < b ? a : b;
}
int max(int a, int b) {	
	return a > b ? a : b;
}

main()
{
	char c; 
	int state, i, j;
	int current_word_length;
	int most_words, div_factor;
	int words_of_length_n_count[MAXLENGTH];

	state = OUT;
	current_word_length = 0;
	for (i = 0; i < MAXLENGTH; i++)
		words_of_length_n_count[i] = 0;	

	while ((c = getchar()) != EOF) {
		if (c == ' ' || c == '\n' || c == '\t'){
			state = OUT;
			words_of_length_n_count[min(current_word_length-1, 11)]++;
			current_word_length = 0;
		}
		else {
			if (isalpha(c) || c == '-' || c == '\'' || c == '`')
				++current_word_length;
			if (state == OUT) {
				state = IN;
			}
		}
	}

	most_words = 0;
	for (i = 0; i < MAXLENGTH; i++)
		most_words = max(most_words, words_of_length_n_count[i]);
	div_factor = max(1, most_words / MAX_BAR_WIDTH);
	for (i = 0; i < MAXLENGTH; i++)
		words_of_length_n_count[i] /= div_factor;

	printf("Histogram of word lengths\n");
	for (i = 0; i < MAXLENGTH; i++)
	{
		if (i != MAXLENGTH -1)
			printf("%2d :", i+1);
		else
			printf("%2d+:", MAXLENGTH);

		for (j = 0; j < words_of_length_n_count[i]; j++)
			printf("#");
		printf("\n");
	}
}