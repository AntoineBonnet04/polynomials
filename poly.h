struct PolyTerm{
	int coeff;
	int expo;
	struct PolyTerm *next;
};

extern struct PolyTerm head;

int addPolyTerm(int c, int e);

void displayPolynomial();

int evaluatePolynomial(int x);

int main(int argc, char *argv[]);
