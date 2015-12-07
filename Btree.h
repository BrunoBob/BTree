#include  <stdlib.h>
#include <stdio.h>

#define DEGRE 2 // degré d'un B-arbre
#define NBKEY ((2*DEGRE) + 1)

typedef enum {0, 1} Boolean;

typedef struct noeud {
	int key[NBKEY];
	int nbkey;
	struct noeud *son[NBKEY];
}*B_tree;

B_tree Create_BTree();
B_tree Add_Key(B_tree B, int key);
B_tree Delete_Key(B_tree B, int key);
B_tree BelongTo_Btree(B_tree B, int key);
B_tree Empty_Btree(B_tree B);
B_tree Load_Btree(B_tree B);

Boolean IsEmpty_Btree(B_tree B);

void Display_Btree(B_tree B);
void Save_Btree(B_tree B);
