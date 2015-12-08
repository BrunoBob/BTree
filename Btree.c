#include "Btree.h"

B_tree Create_BTree() {
	B_tree B;
	int i = 0;

	B = malloc(sizeof(B_tree));
	for(i = 0; i < (2*DEGRE + 1); i++) {
		B->key[i] = 0;
		B->son[i] = NULL;
	}
	B->son[i+1] = NULL;

	B->sonnb = B->keynb = 0;
	return B;
}

B_tree Add_Key(B_tree B, int key) {

	int i = 0;
	int j;

	if(B->keynb < NBKEY) {

		while(i <= B->keynb) {
			if(key < B->key[i]) {
				for(j = B->keynb; j > i; j--) {
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

		B->keynb++;
		Trier(B);
		return B;
	}




}

B_tree Delete_Key(B_tree B, int key);

B_tree BelongTo_Btree(B_tree B, int key);

B_tree Empty_Btree(B_tree B);

B_tree Load_Btree(B_tree B);

Boolean IsEmpty_Btree(B_tree B) {

	if(B->keynb == 0) {
		return 1;
	}
	return 0;
}

void Display_Btree(B_tree B);

void Save_Btree(B_tree B);
