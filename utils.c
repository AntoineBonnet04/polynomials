/* Program designed to provide methods to parse data file in order to
 * extract information concerning polynomials as well as a tool for evaluating
 * powers of integers.
 *
 * *****************************************************
 * Author               Dept.           Date             Notes
 * Antoine Bonnet       Comp.Science    April 8th 2020   Initial version
 * Antoine Bonnet       Comp.Science    April 10th 2020  Completed powi()       
 * Antoine Bonnet       Comp.Science    April 10th 2020  Final version 
 * /
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
	
void parse(char *line, int *coef, int *exp){
// stores the coefficient and exponent to the address provided in the int pointers
	char *pointer1 = strtok(line, " ");
	char *pointer2 = strtok(NULL, " ");
	*coef = atoi(pointer1);
	*exp = atoi(pointer2);
}

int powi(int x, int exp){
	// returns an integer which is x raised to the power of the exponent
	// using a simple loop
	int result = 1;
	while (exp != 0){result *= x; 	exp--;}
	return result;
}
