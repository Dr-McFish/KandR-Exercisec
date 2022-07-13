/* 1.15_solution.c */

/* 1-15. Rewrite the temperature conversion program of */
/*  Section 1.2 to use a function for conversion       */
#include <stdio.h>

float fahrenhiet_to_celsius(float deg_fahrenhiet);

/* print Fahrenheit-Celsius table 
	for fahr = 0, 20, ..., 300 */
main()
{
	float fahr, celsius;
	int lower, upper, step;

	lower = 0;		/* lower limit of temperature table */
	upper = 300;	/* upper limit */
	step = 20;		/* step size */

	fahr = lower;
	while(fahr <= upper) {
		celsius = fahrenhiet_to_celsius(fahr);
		printf("%3.0f%6.1f\n", fahr, celsius);
		fahr = fahr + step;
	}
}

float fahrenhiet_to_celsius(float deg_fahrenhiet) {
	return (5.0/9.0) * (deg_fahrenhiet-32);
}
