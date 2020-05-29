/* Program designed to create a linked list representation for polynomials.
 * Reads a data file, creates a polynomial, displays it and evaluates the polynomial
 * for different values of x. 
 * *****************************************************
 * Author               Dept.           Date             Notes
 * Antoine Bonnet       Comp.Science    April 8th 2020   Initial version
 * Antoine Bonnet       Comp.Science    April 12th 2020  Final version      
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utils.h"

// Create a linked list that can be used to store a polynomial of arbitrary length
struct PolyTerm{//3 fields: coefficient, exponent and a pointer to the next PolyTerm
	int coeff;
	int expo;
	struct PolyTerm *next;
};

typedef struct PolyTerm term;
term *head = NULL;//global variable

int addPolyTerm(int c, int e){
	// Create new Node
	term *temp = (term *) malloc(sizeof(term));
	if (temp == NULL){return -1;}
	temp->coeff = c;
	temp->expo = e;
	
	if (head == NULL){ // If linked list is empty, add node to head;
		head = temp;
		temp -> next = NULL;
		return 0;
	}
	else { // Non-empty linked list
		if (head->expo > e){ // if exponent of head is larger than new one, replace head
			temp->next = head;
			head = temp;
			return 0;
		}
		else{ // exponent of head smaller than new one
			term *ptr = head;
			term *prev = NULL;
			// Iterate over the linked list until new node is added
			while (ptr != NULL){ 
				if (ptr->expo == e){
					ptr->coeff += c;
					return 0;
				} 
				else if (ptr->expo > e){
					prev->next = temp;
					temp->next = ptr;
					return 0;
				}
				else if (ptr->next == NULL){
					ptr->next = temp;
					temp->next = NULL;
					return 0;
				}
				// go to next node of linked list
				prev = ptr;
				ptr = ptr->next;
			}
		}
	}
}

void displayPolynomial(){
	// addPolyTerm sorts terms in increasing order of exponent, so we simply
	// display each PolyTerm starting from the head

	// Print head term
	printf("%dx%d", head->coeff, head->expo);
	
	//create pointer pointing to head's next node
	term *pointer = head->next;
	while(pointer){// Iterate over all nodes in LinkedList
		int c = pointer->coeff;
		int e = pointer->expo;
		// Print term for each node
		if (c<0){printf("%dx%d",c,e);}
		else {printf("+%dx%d",c,e);}
		// go to next node
		pointer = pointer->next;
		
	}
	printf("\n");
}

int evaluatePolynomial(int x){
	int result = 0;
	// create pointer
	term *pointer = head;
	while (pointer){
		int c = pointer->coeff;
		int e = pointer->expo;
		// add coeff*(x**expo)	
		result += c*powi(x,e);
		// go to next term
		pointer = pointer->next;
	}
	return result;
}


