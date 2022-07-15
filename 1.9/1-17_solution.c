/* 1-17_solution.c */
/* Write a program  to print all input line that are longer than 80 charechters */

#include <stdio.h>
#define MAXLINE 1000

int get_line(char line[], int maxline);

main()
{
	int len;
	char c;
	char line[MAXLINE];

	while ((len = get_line(line, MAXLINE)) > 0) {
		if (len == MAXLINE - 2 && line[MAXLINE - 3] != '\n') {
			/* overflow line, actual length more than MAXLINE */
			while((c = getchar()) != '\n' && c != '\0');
			if (c == '\0')
				break;
		}
		if (len > 80) {
			printf("%s", line);
		}
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

