#include "Btree2.h"

Btree adjust(Btree root, Btree node);
Btree split(Btree root, Btree node);
Btree getFather(Btree root, Btree node);

Btree adjust(Btree root, Btree node){
  if(node->sonNbr>2*DEGRE){
    root = split(root,node);
    root = adjust(root, getFather(root,node));
  }
  return root;
}

Btree split(Btree root, Btree node){
  Btree father = getFather(root, node);
  Btree newNode;// = createBTree();
  int i;
  for(i = 0 ; i < DEGRE ; i++){
    newNode->keys[i] = node->keys[i+DEGRE+1];
    node->keys[i+DEGRE+1] = 0;
  }
  newNode->keyNbr = DEGRE;
  node->keyNbr = DEGRE;
  if(node->sonNbr == 0){
    for(i = 0 ; i < DEGRE+1 ; i++){
      newNode->sons[i] = node->sons[i+DEGRE+1];
      node->sons[i+DEGRE+1] = NULL;
    }
    newNode->sonNbr = DEGRE + 1;
    node->sonNbr = DEGRE + 1;
  }
  int value = 0;
  while(father->sons[value] != node){
    value++;
  }
  for(i = DEGRE+2 ; i>value + 1 ; i--){
    father->sons[i] = father->sons[i-1];
  }
  father->sons[value + 1] = newNode;
  father->keyNbr ++;
  return root;
}


Btree getFather(Btree root, Btree node){
  if(root!=node){
    if(root->sons[0] == node){
      return root;
    }
    else{
      root = root->sons[0];
    }
    int isFather = 0;
    while (! isFather) {
      int j;
      for(j = 0 ; j<root->sonNbr ; j++){
        if(root->sons[j] == node){
          isFather = 1;
          break;
        }
      }
      if(isFather){
        break;
      }
      int i = 0;
      while(node->keys[0] > root->keys[i]){
        i++;
      }
      if(i>4){
        i=4;
      }
      root = root->sons[i];
    }
  }
  return root;
}

int main (int argc, char *argv[]) {


}
