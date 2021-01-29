# **Exercise 1-11.** How would you test the word count program? What kinds of input are most likely to uncover bugs if there are any?

Program from book for context:
```c
#include <stdio.h>

#define IN 1
#define OUT 0

/* count lines, words, and characters in input */
main()
{
	int c, nl, nw, nc, state;

	state = OUT;
	while ((c = getchar()) != EOF) {
		++nc;
		if (c == '\n')
			++nl;
		if (c == ' ' || c == '\n' || c == '\t')
			state = OUT;
		else if (state == OUT) {
			state = IN;
			++nw;
		}
	}
	printf("%d %d %d\n", nl, nw, nc);
}
```

I was thinking that inputs that start with a space or that contain multiple whitespace chars next to each other would break it, but nope it's really solid. I have no idea.