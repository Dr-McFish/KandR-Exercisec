/* Solution to 1-3 */
/* 1-4_solution.c */
#include <stdio.h>

/* print Fahrenheit-Celsius table 
	for fahr = 0, 20, ..., 300 */
main()
{
	float fahr, celsius;
	int lower, upper, step;

	lower = 0;		/* lower limit of temperature table */
	upper = 300;	/* upper limit */
	step = 20;		/* step size */

	/* Print a heading */
	printf("Fahrenhiet to Celsius conversion table\n");

	fahr = lower;
	while(fahr <= upper) {
		celsius = (5.0/9.0) * (fahr-32);
		printf("%3f%6.1f\n", fahr, celsius);
		fahr = fahr + step;
	}
}
