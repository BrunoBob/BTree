Btree delete_key(Btree B, int k) {

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
