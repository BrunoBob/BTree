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
  B_tree newNode = Create_BTree();
	B_tree father = getFather(root, node);
  int i;
  for(i = 0 ; i < DEGRE ; i++){
    newNode->key[i] = node->key[i+DEGRE+1];
    node->key[i+DEGRE+1] = -1;
  }
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

	//Reorder the link between trees
  int value = 0;
	if(father != node){
  	while((father->key[value] != -1) && (father->key[value] < node->key[DEGRE]) ){
    	value++;
  	}
  	for(i = (2 * DEGRE) + 1 ; i > value ; i--){
    	father->son[i] = father->son[i-1];
  	}
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
  father->keynb ++;
  return root;
}

B_tree adjust(B_tree root, B_tree node){
  if(node->keynb>2*DEGRE){
    root = split(root,node);
    root = adjust(root, getFather(root,node));
  }
  return root;
}

B_tree getFather(B_tree root, B_tree node){
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
	return root;
}

B_tree Delete_Key(B_tree B, int key);

Boolean BelongTo_Btree(B_tree B, int key){
	Boolean belong = 0;
	int i;
	for(i = 0 ; i < B->keynb ; i++){
		if(B->son[i] != NULL){
			belong = BelongTo_Btree(B->son[i], key);
		}
		if(belong){
			break;
		}
		if(key == B->key[i]){
			belong = 1;
			break;
		}
	}
	if((!belong) && (B->son[i] != NULL)){
		belong = BelongTo_Btree(B->son[i], key);
	}
	return belong;
}

B_tree Empty_Btree(B_tree B){
	int i;
	for(i = 0 ; i < B->keynb ; i++){
		if(B->son[i] != NULL){
			Empty_Btree(B->son[i]);
			B->son[i] = NULL;
		}
		B->key[i] = -1;
	}
	if(B->son[i] != NULL){
		Empty_Btree(B->son[i]);
		B->son[i] = NULL;
	}
	free(B);
	B = Create_BTree();
	return B;
}

B_tree Load_Btree(B_tree B, char* filename){

	B = Empty_Btree(B);
	FILE* file = fopen(filename,"r");
	if(file == NULL){
		printf("Error opening file %s\n", filename);
	}
	else{
		int i;
		fscanf(file, "%d", &i);
		while(!feof(file)){
			if(BelongTo_Btree(B, i)){
				printf("%d already in the B-Tree\n", i);
			}
			else{
				printf("%d loaded to the B-Tree\n", i);
				B = Add_Key(B,i);
			}
			fscanf(file, "%d", &i);
		}
	}
	fclose(file);
	return B;
}

Boolean IsEmpty_Btree(B_tree B) {

	if(B->keynb == 0) {
		return 1;
	}
	return 0;
}

void Display_Btree(B_tree B){
	int i;
	for(i = 0 ; i < B->keynb ; i++){
		if(B->son[i] != NULL){
			Display_Btree(B->son[i]);
		}
		printf("%d ,", B->key[i]);
	}
	if(B->son[i] != NULL){
		Display_Btree(B->son[i]);
	}
}

void Save_Btree(B_tree B, char* filename){
	FILE* file = fopen(filename,"w");

	if(file == NULL){
		printf("error in opening file %s\n", filename);
	}
	else{
		SaveDisplay_Btree(B,file);
	}

	fclose(file);
}

void SaveDisplay_Btree(B_tree B, FILE* file){
	int i;
	for(i = 0 ; i < B->keynb ; i++){
		if(B->son[i] != NULL){
			SaveDisplay_Btree(B->son[i],file);
		}
		fprintf(file, "%d ", B->key[i]);
	}
	if(B->son[i] != NULL){
		SaveDisplay_Btree(B->son[i],file);
	}
}
