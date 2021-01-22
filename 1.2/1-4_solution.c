/* Solution to 1-4 */
/* 1-4_solution.c */
#include <stdio.h>

/* print Fahrenheit-Celsius table 
	for fahr = 0, 20, ..., 300 */
main()
{
	float fahr, celsius;
	int lower, upper, step;

	lower = -10;		/* lower limit of temperature table */
	upper = 110;	/* upper limit */
	step = 5;		/* step size */

	/* Print a heading */
	printf("Celsius to Fahrenhiet conversion table\n");
	
	fahr = lower;
	while(celsius <= upper) {
		fahr = ( (9.0/5.0) * celsius ) +32;
		printf("%3.0f%6.1f\n", celsius, fahr);
		celsius = celsius + step;
	}
}
