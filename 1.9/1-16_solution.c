/* 1-16_solution.c */
/* Revise the routine of the longest-line program so it will correctly print 
the length of arvitrarily long input lines, and as much as possible of the text */

#include <stdio.h>
#define MAXLINE 1000

int get_line(char line[], int maxline);
void copy(char to[], char from[]);

/* print the longest input line */
main()
{
	int len;
	int max;
	char c;
	char line[MAXLINE];
	char longest[MAXLINE];

	max = 0;
	while ((len = get_line(line, MAXLINE)) > 0) {
		if (len == MAXLINE - 2 && line[MAXLINE - 3] != '\n') {
			/* overflow line, actual length more than MAXLINE */
			while((c = getchar()) != '\n' && c != '\0')
				++len;
			if (c == '\n')
				++len;
			else if (c == '\0')
				break;
		}
		if (len > max) {
			max = len;
			copy(longest, line);
		}
	}
	if(max > 0) /* there was a line */
		printf("length: %d \n%s", max, longest);
	return 0;
}

/* get_line: read a  line into s, return length */
int get_line(char s[], int lim)
{
	int c, i;
	for(i = 0; i<lim-2 && (c=getchar())!=EOF && c!='\n'; ++i)
		s[i] = c;
	if(c == '\n') {
		s[i] = c;
		++i;
	}
	s[i] = '\0';
	return i;
}

/* copy 'from' into 'to'; assume to is big enough */
void copy(char to[], char from[])
{
	int i;

	i = 0;
	while ((to[i] = from[i]) != '\0')
		++i;
}
