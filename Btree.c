#include  <stdlib.h>
#include <stdio.h>
#include "B-arbre.h"

B_tree Create_BTree() {
	B_tree B;
	int i = 0;
	
	B = malloc(sizeof(B_tree));
	for(i = 0; i < (2*DEGRE + 1); i++) {
		B->key[i] = NULL;
		B->son[i] = NULL;
	}
	
	nbkey = 0;
	return B;
}

B_tree Add_Key(B_tree B, int key) {
	
	int i = 0;
	
	if(B->nbkey < NBKEY) {
		
		while(i <= B->nbkey) {
			if(key < B->key[i]) {
				for(j = nbkey; j > i; j--) {
					B->key[j] = B->key[j - 1];
				}
				B->key[i] = key;
				i = NBKEY;
			}
			i++;
		}
		if(i != NBKEY) {
			B->key[i + 1] = key;
		}
		
		B->nbkey++;
		Trier(B);
		return B;
	}
	
	
	
	
}

B_tree Delete_Key(B_tree B, int key);

B_tree BelongTo_Btree(B_tree B, int key);

B_tree Empty_Btree(B_tree B);

B_tree Load_Btree(B_tree B);

Boolean IsEmpty_Btree(B_tree B) {
	
	if(B->nbkey == 0) {
		return 1;
	}
	return 0;
}

void Display_Btree(B_tree B);

void Save_Btree(B_tree B);
