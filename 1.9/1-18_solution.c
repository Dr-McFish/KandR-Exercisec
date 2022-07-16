/* 1-18_solution.c */
/* Write a program to remove trailing blanks and tabs from each line of input,
	and to delete entierly plank lines. */

#include <stdio.h>
#define MAXLINE 1000
#define TRUE 1
#define FALSE 0

int get_line(char line[], int maxline);
int is_blank(const char s[]);
int remove_trailing_whitespace(char s[]);

int main()
{
	int len, status;
	int i, j;
	char c;
	char line[MAXLINE];

	while ((len = get_line(line, MAXLINE)) > 0) {
		if (is_blank(line))
			continue;
		status = remove_trailing_whitespace(line);
		if (status == 0) {
			printf("%s", line);
		} else 
			return 1; /* line too long */
	}

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

int is_blank(const char s[]) {
	int i;

	for(i = 0; s[i] != '\0' && s[i] != '\n'; i++)
		if (s[i] != ' ' && s[i] != '\t')
			return FALSE;
	return TRUE;
}

int remove_trailing_whitespace(char s[]) {
	int whitespace_before;
	int i;

	whitespace_before = 0;

	for(i = 0; s[i] != '\0' && s[i] != '\n'; i++) {
		if (s[i] == ' ' ||s[i] == '\t')
			whitespace_before++;
		else
			whitespace_before = 0;
	}
	if (s[i] == '\n') {
		s[i - whitespace_before] = '\n';
		s[i - whitespace_before + 1] = '\0';
		return 0;
	} else
		return 1;
}

