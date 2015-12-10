#include <stdlib.h>
#include <stdio.h>
#include <malloc.h>

#define DEGRE 2 // degré d'un B-arbre
#define NBKEY ((2*DEGRE) + 1)
#define NBSON ((2*DEGRE) + 2)

typedef int Boolean;

typedef struct noeud {
	int key[NBKEY];
	int keynb,sonnb;
	struct noeud *son[NBSON];
}*B_tree;

B_tree Create_BTree();
B_tree Add_Key(B_tree B, int key);
B_tree Delete_Key(B_tree B, int k);
B_tree BelongTo_Btree(B_tree B, int key);
B_tree Empty_Btree(B_tree B);
B_tree Load_Btree(B_tree B);
B_tree Search_Key(Btree B, int k);

Boolean IsEmpty_Btree(B_tree B);
Boolean Verif_Key(Btree B, int k);

void Display_Btree(B_tree B);
void Save_Btree(B_tree B);
