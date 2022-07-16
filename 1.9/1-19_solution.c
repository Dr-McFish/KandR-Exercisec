/* 1-19_solution.c */
/* Write a function reverse(s) that reverses the character string s. Use it to weite a program that reverses it's input one a line at a time */

#include <stdio.h>
#define MAXLINE 1000

int get_line(char line[], int maxline);
void reverse(char s[]);

main()
{
	int len;
	char c;
	char line[MAXLINE];

	while ((len = get_line(line, MAXLINE)) > 0) {
		if (len == MAXLINE - 2 && line[MAXLINE - 3] != '\n') {
			/* overflow line, actual length more than MAXLINE */
			line[MAXLINE-3] = '\n';
		}
		reverse(line);
		printf("%s", line);
	}
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

void reverse(char s[]) {
	char c;
	int len;
	int i;

	for (len = 0; s[len] != '\n'; len++);
	len--;

	for (i = 0; i < (len + 1)/2; i++) {
		c = s[i];
		s[i] = s[len-i];
		s[len-i] = c;
	}
}
