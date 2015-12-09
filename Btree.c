#include "Btree.h"

B_tree Create_BTree() {
	B_tree B;
	int i = 0;

	B = malloc(sizeof(*B));
	for(i = 0; i < (2*DEGRE + 1); i++) {
		B->key[i] = -1;
		B->son[i] = NULL;
	}
	B->son[i+1] = NULL;

	B->sonnb = B->keynb = 0;
	return B;
}

B_tree Add_Key(B_tree root, int key) {
	/*if(root->sonnb == 0){
		root->key[root->keynb] = key; // modif
		root->keynb++;
		root = adjust(root,root);
	}
	else{
		B_tree node = root;
		while(node->sonnb != 0){
			value = 0 ;
			while((node->key[value] != -1) && (node->key[value]< key)){
				value++;
			}
			node = node->son[value];
		}
	}*/

	B_tree node = root;
	while(node->sonnb != 0){
		int value = 0 ;
		while((node->key[value] != -1) && (node->key[value]< key)){
			value++;
		}
		node = node->son[value];
	}
	int value = 0 ;
	while((node->key[value] != -1) && (node->key[value]< key)){
		value++;
	}
	int i;
	for(i = 2*DEGRE ; i > value ; i--){
		node->key[i] = node->key[i-1];
	}
	node->key[value] = key;
	node->keynb++;
	root = adjust(root, node);
	return root;
}


B_tree split(B_tree root, B_tree node){
	printf("split start\n");
	debug(root);
	debug(node);//Split the value
	printf("part 1\n");
  B_tree newNode = Create_BTree();
	B_tree father = getFather(root, node);
  int i;
	printf("part 2\n");
  for(i = 0 ; i < DEGRE ; i++){
    newNode->key[i] = node->key[i+DEGRE+1];
    node->key[i+DEGRE+1] = -1;
  }
		printf("part 3\n");
  newNode->keynb = DEGRE;
  node->keynb = DEGRE;
  if(node->sonnb != 0){
    for(i = 0 ; i < DEGRE+1 ; i++){
      newNode->son[i] = node->son[i+DEGRE+1];
      node->son[i+DEGRE+1] = NULL;
    }
    newNode->sonnb = DEGRE + 1;
    node->sonnb = DEGRE + 1;
  }
	printf("part 4\n");
	//Reorder the link between trees
  int value = 0;
	if(father != node){
		printf("part 4.1\n");
  	while((father->key[value] != -1) && (father->key[value] < node->key[DEGRE]) ){
    	value++;
  	}
		printf("part 4.2\n");
  	for(i = (2 * DEGRE) + 1 ; i > value ; i--){
    	father->son[i] = father->son[i-1];
  	}
		printf("part 4.3\n");
		for(i = (2 * DEGRE) ; i > value ; i--){
			father->key[i] = father->key[i-1];
		}
	}
	else{
		father = Create_BTree();
		father->son[value] = node ;
		father->sonnb++;
		root=father;
	}
	father->son[value + 1] = newNode;
	father->sonnb++ ;
	father->key[value] = node->key[DEGRE];
	node->key[DEGRE] = -1;
	printf("part 5\n");
  father->keynb ++;
  return root;
}

B_tree adjust(B_tree root, B_tree node){
  if(node->keynb>2*DEGRE){
		printf("etape 1\n");
    root = split(root,node);
		printf("etape 2\n");
    root = adjust(root, getFather(root,node));
  }
  return root;
}

B_tree getFather(B_tree root, B_tree node){
	printf("Father start\n");
	debug(root);
	debug(node);
  if(root!=node){
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
	printf("Father end\n");
  return root;
}

B_tree Delete_Key(B_tree B, int key);

B_tree BelongTo_Btree(B_tree B, int key);

B_tree Empty_Btree(B_tree B);

B_tree Load_Btree(B_tree B, char* filename);

Boolean IsEmpty_Btree(B_tree B) {

	if(B->keynb == 0) {
		return 1;
	}
	return 0;
}

void Display_Btree(B_tree B);

void Save_Btree(B_tree B, char* filename);

void debugTree(B_tree tree){
	debug(tree);
	int i;
	for(i = 0 ; i< tree->sonnb ; i++){
		if(tree->son[i] != NULL){
			debugTree(tree->son[i]);
		}
	}
}

void debug(B_tree tree){
	printf("nb keys : %d - keys : ", tree->keynb);
	int i ;
	for(i = 0 ; i < tree->keynb ; i++){
		printf("%d ; ", tree->key[i]);
	}
	printf("nb sons : %d \n", tree->sonnb);
}
