#include <stdio.h>
#include <stdlib.h>

#define DEGRE 2; //

typedef enum{0, 1} Boolean;
typedef struct Node {
	int sonNbr, keyNbr;
	int keys[2*DEGRE];
	Boolean leaf;
	struct Node *sons[(2*DEGRE) + 1];
}*Btree;
