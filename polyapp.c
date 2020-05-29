/* Program designed to parse a data file and extract information
 * concerning a polynomial. 
 *
 * *****************************************************
 * Author               Dept.           Date             Notes
 * Antoine Bonnet       Comp.Science    April 8th 2020   Initial version
 * Antoine Bonnet	Comp.Science	April 10th 2020	 Fixed bugs	
 * Antoine Bonnet       Comp.Science    April 10th 2020  Final version
 */

#include <stdlib.h>
#include <stdio.h>
#include "utils.h"
#include "poly.h"

int main(int argc, char *argv[]){
        // parse each line of the data file to extract coeff/exponent
        // and add it to the polynomial using the addPolyTerm function
        // if run out of memory, print an appropriate message to the screen
        char line[100];

        FILE* filetest = fopen(argv[1],"r");
        if (filetest == NULL) {// file not found   
        printf("Error, unable to locate the data file %s\n", argv[1]); exit(100);}

        while (fgets(line,sizeof(line),filetest)){// while end of file not reached
                int c, e;
                parse(line, &c, &e);
                int err = addPolyTerm(c, e);
                if (err == -1){
                        fprintf(stderr,"Memory insufficient, could not allocate space");
                        return 100;
                }
        }
        displayPolynomial();
        for (int i = -2; i<3; i++){
                int y = evaluatePolynomial(i);
                printf("for x=%d, y=%d\n",i, y);
        }
}


