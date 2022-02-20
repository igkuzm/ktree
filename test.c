/**
 * File              : test.c
 * Author            : Igor V. Sementsov <ig.kuzm@gmail.com>
 * Date              : 13.02.2022
 * Last Modified Date: 20.02.2022
 * Last Modified By  : Igor V. Sementsov <ig.kuzm@gmail.com>
 */

#include "ktree.h"
#include <stdio.h>
#include <stdlib.h>

char readChar(){
	char a;
	scanf("%c", &a);
	return a;	
}

char *readString(){
	int i = 0;
	char *a = (char *) calloc(BUFSIZ, sizeof(char));
	if (!a) {
		fprintf(stderr, "ERROR. Cannot allocate memory\n");		
		return NULL;
	}										
	
	while (1) {
		scanf("%c", &a[i]);
		if (a[i] == '\n') {
			break;
		}
		else {
			i++;
		}
	}
	a[i] = '\0';
	return a;
}

void print_header(){
	system("clear");	
	printf("#######################################\n");
	printf("TREE test\n");
	printf("#######################################\n");
	printf("\n");
}

int print_tree_callback(KTreeNode *node, KTreeIndexPath *indexPath, void *user_data) {
	char *text = node->data;
	if (text == NULL) {
		text = "NULL";
	}	
	char *indexPathStr = k_tree_string_from_indexpath(indexPath); 
	if (indexPathStr) {
		printf("%s.\t%s\n", indexPathStr, text);
		//free(indexPathStr);
	}
	//k_tree_indexpath_free(indexPath);

	return 0;
}

void print_list(KTree *tree){
	printf("#######################################\n");
	printf("TREE ITEMS:\n");
	if (k_list_is_empty(tree)) {
		printf("NULL\n");
	} else {
		k_tree_foreach_node(tree, NULL, NULL, print_tree_callback);
	}
	printf("#######################################\n");
	printf("\n");
}

void print_navigation(){
	printf("#######################################\n");
	printf("a - append node to indexPath\n");
	printf("r - remove item at index\n");
	printf("#######################################\n");
	printf("q - quit\n");
}

void start_test(KTree *tree){
Start:;
	print_header();
	print_list(tree);
	print_navigation();
	char c;
	while (1){		
		c = readChar();
		switch (c) {
			case 'q':
				goto Exit;
				break;
			case 'a':
				{
					printf("Enter string to append\n");
					getchar();
					char *str = readString();
					KTreeNode *node = k_tree_node_new(str);
					printf("Enter indexPath (like 0:1:0), or -1 for root\n");
					char *indexPathStr = readString();					
					KTreeNode *parent = k_tree_node_at_indexpath_string(tree, indexPathStr);
					k_tree_append(tree, parent, node);
					goto Start;
					break;
				}				
			case 'r':
				{
					printf("Enter indexPath\n");
					getchar();
					char *indexPathStr = readString();					
					KTreeNode *node = k_tree_node_at_indexpath_string(tree, indexPathStr);
					k_tree_remove_node(tree, node);
					goto Start;
					break;
				}				
			default:
				goto Start;
				break;
		}	
	}
	Exit:;
	printf("Exit...\n");
	k_list_free(tree);
}

int main(int argc, char *argv[])
{
	printf("Starting klist test...\n");
	KTree *tree = k_tree_new();
	start_test(tree);
	return 0;
}

