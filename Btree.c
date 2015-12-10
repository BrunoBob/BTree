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
//		Trier(B);
		return B;
	}
}

B_tree split(B_tree root, B_tree node){
  B_tree father = getFather(root, node);
  B_tree newNode;// = createBTree();
  int i;
  for(i = 0 ; i < DEGRE ; i++){
    newNode->key[i] = node->key[i+DEGRE+1];
    node->key[i+DEGRE+1] = 0;
  }
  newNode->keynb = DEGRE;
  node->keynb = DEGRE;
  if(node->sonnb == 0){
    for(i = 0 ; i < DEGRE+1 ; i++){
      newNode->son[i] = node->son[i+DEGRE+1];
      node->son[i+DEGRE+1] = NULL;
    }
    newNode->sonnb = DEGRE + 1;
    node->sonnb = DEGRE + 1;
  }
  int value = 0;
  while(father->son[value] != node){
    value++;
  }
  for(i = DEGRE+2 ; i>value + 1 ; i--){
    father->son[i] = father->son[i-1];
  }
  father->son[value + 1] = newNode;
  father->keynb ++;
  return root;
}

B_tree adjust(B_tree root, B_tree node){
  if(node->sonnb>2*DEGRE){
    root = split(root,node);
    root = adjust(root, getFather(root,node));
  }
  return root;
}

B_tree getFather(B_tree root, B_tree node){
  if(root!=node){
    if(root->son[0] == node){
      return root;
    }
    else{
      root = root->son[0];
    }
    Boolean isFather = 0;
    while (! isFather) {
      int j;
      for(j = 0 ; j<root->sonnb ; j++){
        if(root->son[j] == node){
          isFather = 1;
          break;
        }
      }
      if(isFather){
        break;
      }
      int i = 0;
      while(node->key[0] > root->key[i]){
        i++;
      }
      if(i>4){
        i=4;
      }
      root = root->son[i];
    }
  }
  return root;
}

// Pas fini
B_tree Delete_Key(Btree B, int k) {

	Btree Bt = Create_Btree();
	Btree Bst = Create_Btree();

	if(!verif_Key(B, k)) {
		printf("La clef %d n'existe pas, et ne peut donc pas être supprimée.\n", k);
		return B;
	}

	Bt = search_Key(B, k);
	int i = 0;

	if(Bt->leaf = 1) {
		if(Bt->keyNbr <= DEGRE) {

			//A FAIRE
		}
		else {
			while(Bt->keys[i] != k) {
				i++;
			}
			while(i <= keyNbr) {
				Bt->keys[i] = Bt->keys[i + 1];
			}
			Bt->keys[keyNbr - 1] = NULL;
			Bt->keyNbr--;
		}
	}
	else {
		while(Bt->keys[i] != k) {
			i++;
		}
		if(Bt->sons[i + 1] != NULL) {
			Bst = Bt->sons[i + 1];
			while(Bst->sons[0] != NULL) {
				Bst = Bst->sons[0];
			}
			Bt->keys[i] = Bst->keys[0];
		}
		else {
			Bts = Bt->sons[i];
			while(Bst->sons[(B->sonNbr -1)] != NULL) {
				Bst = Bst->sons[(B->sonNbr -1)];
			}
			Bt->keys[i] = Bst->keys[(B->keyNbr - 1)];
		}
	}
}

B_tree BelongTo_Btree(B_tree B, int key);

B_tree Empty_Btree(B_tree B);

B_tree Load_Btree(B_tree B);

B_tree Search_Key(Btree B, int k) {

	int i = 0;
	while ((i < B->sonNbr) && (k > B->keys[i])) {
		i++;
	}
	if((i <= B->sonNbr) && (k = B-key[i]))
		return B;
	else {
		if(B->sonNbr == 0) {
			return NULL;
		}
		else {
			return search_Key(B->sons[i], k);
		}
	}
}

Boolean IsEmpty_Btree(B_tree B) {

	if(B->keynb == 0) {
		return 1;
	}
	return 0;
}

Boolean Verif_Key(Btree B, int k) {
	if(!(search_Key(B, k) = NULL) {
		return 1;
	}
	return 0;
}

void Display_Btree(B_tree B);

void Save_Btree(B_tree B);
