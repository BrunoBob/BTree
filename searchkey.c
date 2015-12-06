Boolean search_Key(Btree B, int k) {

	int i = 0;
	while ((i < B->sonNbr) && (k > B->keys[i])) {
		i++;
	}
	if((i <= B->sonNbr) && (k = B-key[i]))
		return B;
	else {
		if(B->leaf) {
			return NULL;
		}
		else {
			return search_Key(B->sons[i], k);
		}
}
