#include <stdio.h>
#include <stdlib.h>
#include "Btree.h"

int getParameter() {
	int parameter;
	scanf("%d", parameter);
	return parameter;
}

char* getFileName() {
	char* filename;
	filename = malloc(25*sizeof(char));
	scanf("%s", filename);
	return filename;
}

int main(int argc, char *argv[]) {

	system("clear");

	int choice = 0;
	Btree B = Create_Btree();

	while(choice != 8) {

		printf("This program is to be used as a B-tree.\n");
		printf("Several options are possible.\n");
		printf("Write the number before ':' to call the related function.\n");
		printf("--------------------------------\n");
		printf("1: Add a key (integer) in the B-tree.\n");
		printf("2: Delete a key (integer) in the B-tree.\n");
		printf("3: Display B-tree.\n");
		printf("4: Verify if a key (integer) is in the B-tree.\n");
		printf("5: Empty B-tree.\n");
		printf("6: Save the keys of the B-tree in a '.key' file.\n");
		printf("7: Construct a B-tree from a '.key' file.\n");
		printf("8: Quit.\n");

		printf("Select which action to make: ");
		scanf("%d", &choice);
		system("clear");
		int parameter ;

		switch(choice) {
			case 1 :
				printf("Key to add: \n");
				parameter = getParameter();
				if(!Is_Empty_Btree(B)) {
					if(Exist_Key(B, parameter) == True) {
						printf("Key %d already in the B-tree.\n", parameter);
						break;
					}
				}
				B = Add_Key(B, parameter) ;
				free(parameter);
				break;
			case 2 :
				printf("Key to delete: \n");
				parameter = getParameter();
				if(Is_Empty_Btree(B)) {
					printf("Can't delete because the B-tree is empty.\n");
				}
				else if(!Exist_Key(B, parameter) == True) {
					printf("Key %d is not in the B-tree.\n", parameter);
				}
				else {
					B = Delete_Key(B, parameter);
				}
				free(parameter);
				break;
			case 3 :
				if(Is_Empty_Btree(B)) {
					printf("The B-tree is empty.\n") ;
				}
				else {
					Display_Btree(B);
				}
				break;
			case 4 :
				printf("Key to verify: \n");
				parameter = getParameter();
				if(Is_Empty_Btree(B)) {
					printf("The B-tree is empty.\n") ;
					break;
				}
				if(Exist_Key(B, parameter) == True) {
					printf("The key %d is in the B-tree.\n", parameter);
				}
				else {
					printf("The key %d is not in the B-tree.\n", parameter);
				}
				free(parameter);
				break;
			case 5 :
				B = Empty_Btree(B);
				if(Is_Empty_Btree(B)) {
					printf("The B-tree is empty.\n") ;
				}
				break;
			case 6 :
				if(Is_Empty_Btree(B)) {
					printf("The B-tree is empty.\n") ;
				}
				else{
					printf("Name of the file in which you want to save: \n");
					char* filename;
					filename = getFileName();
					Save_Btree(B, filename);
					free(filename);
				}
				break;
			case 7 :
				printf("Name of the file to load: \n");
				char* filename;
				filename = getFileName();
				B = Load_Btree(filename, B);
				free(filename);
				break;
		}
	}
	return 0;
}
