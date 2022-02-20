/**
 * File              : ktree.c
 * Author            : Igor V. Sementsov <ig.kuzm@gmail.com>
 * Date              : 19.02.2022
 * Last Modified Date: 20.02.2022
 * Last Modified By  : Igor V. Sementsov <ig.kuzm@gmail.com>
 */

#include "ktree.h"
#include <stdio.h>
#include <stdlib.h>

KTreeNode *k_tree_node_new(void *data) {
	KTreeNode *node = malloc(sizeof(KTreeNode));
	if (node == NULL) {
		perror("KTreeNode malloc");
		exit(EXIT_FAILURE);
	}
	node->parent = NULL;
	node->children = k_list_new();
	node->data = data;
	return node;
}

void k_tree_node_free(KTreeNode *node) {
	KList *ptr = node->children;
	free(node);
	while (ptr != NULL) {
		node = ptr->data;
		if (node) {
			k_tree_node_free(node);
		}
		KList *next = ptr->next;
		free(ptr);
		ptr = next;
	}
}

KTree *k_tree_new() {
	KTree *tree = k_list_new();
	return tree;
}

KTreeNode *k_tree_node_at(KTree *tree, KTreeNode *parent, int index){
	if (parent == NULL) {
		return (KTreeNode *)k_list_item_at(tree, index);
	} else {
		return (KTreeNode *)k_list_item_at(parent->children, index);
	}
}

void k_tree_append(KTree *tree, KTreeNode *parent, KTreeNode *node){
	if (parent == NULL) {
		k_list_append(tree, node);
	} else {
		node->parent=parent;
		k_list_append(parent->children, node);
	}
}

void k_tree_prepend(KTree *tree, KTreeNode *parent, KTreeNode *node){
	if (parent == NULL) {
		k_list_prepend(tree, node);
	} else {
		node->parent=parent;
		k_list_prepend(parent->children, node);
	}
}

void k_tree_insert_node_at_index(KTree *tree, KTreeNode *parent, KTreeNode *node, int index){
	if (parent == NULL) {
		k_list_insert_item_at_index(tree, node, index);
	} else {
		node->parent=parent;
		k_list_insert_item_at_index(parent->children, node, index);
	}
}

void k_tree_move_node(KTree *tree, KTreeNode *from_parent, int from_index, KTreeNode *to_parent, int to_index) {
	KTreeNode *node;
	if (from_parent == NULL) {
		node = (KTreeNode *)k_list_item_at(tree, from_index);
		k_list_remove_item_at_index(tree, from_index);
	} else {
		node = (KTreeNode *)k_list_item_at(from_parent->children, from_index);
		k_list_remove_item_at_index(from_parent->children, from_index);
	}
	if (to_parent == NULL) {
		k_list_insert_item_at_index(tree, node, to_index);
		node->parent = NULL;
	} else {
		k_list_insert_item_at_index(to_parent->children, node, to_index);
		node->parent = to_parent;
	}
}

void k_tree_remove_node_at_index(KTree *tree, KTreeNode *parent, int index){
	if (parent == NULL) {
		KTreeNode *node = (KTreeNode *)k_list_item_at(tree, index);
		k_list_remove_item_at_index(tree, index);
		free(node);
	} else {
		KTreeNode *node = (KTreeNode *)k_list_item_at(parent->children, index);
		k_list_remove_item_at_index(parent->children, index);
		free(node);
	}
}

KTreeIndexPath *k_tree_indexpath_new(){
	KTreeIndexPath *indexPath = malloc(sizeof(KTreeIndexPath));
	if (indexPath == NULL) {
		perror("KTreeIndexPath malloc");
		exit(EXIT_FAILURE);
	}

	indexPath->indexPath = malloc(sizeof(int));
	if (indexPath->indexPath == NULL) {
		perror("KTreeIndexPath->indexPath malloc");
		exit(EXIT_FAILURE);
	}

	indexPath->indexPath[0] = -1;
	
	indexPath->count = 0;

	return indexPath;
}


void k_tree_indexpath_free(KTreeIndexPath *indexPath) {
	free(indexPath->indexPath);
	free(indexPath);
}

void k_tree_indexpath_add_index(KTreeIndexPath *indexPath, int index) {
	indexPath->indexPath[indexPath->count] = index;
	indexPath->count++;

	indexPath->indexPath = realloc(indexPath->indexPath, (indexPath->count + 1) *sizeof(int));
	if (indexPath->indexPath == NULL) {
		perror("KTreeIndexPath->indexPath realloc");
		exit(EXIT_FAILURE);
	}
}

KTreeIndexPath *k_tree_indexpath_new_from_indexpath(KTreeIndexPath *indexPath){
	KTreeIndexPath *newIndexPath = k_tree_indexpath_new();
	for (int i = 0; i < indexPath->count; ++i) {
		k_tree_indexpath_add_index(newIndexPath, indexPath->indexPath[i]);
	}
	return newIndexPath;
}

KTreeIndexPath *k_tree_indexpath_of_node(KTree *tree, KTreeNode *node) {
	KTreeIndexPath *indexPath = k_tree_indexpath_new();
	KTreeNode *ptr = node;
	while (ptr->parent != NULL) {
		int index = k_list_index_of_item(ptr->parent->children, ptr);
		k_tree_indexpath_add_index(indexPath, index);
		ptr = ptr->parent;
	}
	int index = k_list_index_of_item(tree, ptr);
	k_tree_indexpath_add_index(indexPath, index);

	KTreeIndexPath *indexPathReverse = k_tree_indexpath_new();
	for (int i = indexPath->count - 1; i >= 0; --i) {
		int index = indexPath->indexPath[i];	
		k_tree_indexpath_add_index(indexPathReverse, index);
	}

	k_tree_indexpath_free(indexPath);

	return indexPathReverse;
}

KTreeIndexPath *k_tree_indexpath_from_string(const char *string){
	KTreeIndexPath *indexPath = k_tree_indexpath_new();
	char *ptr = (char *)string;	
	char buff[BUFSIZ];
	int index;
	while (sscanf(ptr, "%d:%s", &index, buff) == 2) {
		k_tree_indexpath_add_index(indexPath, index);
		ptr = buff;
	}
	k_tree_indexpath_add_index(indexPath, index);

	return indexPath;
}

char *k_tree_string_from_indexpath(KTreeIndexPath *indexPath){
	if (indexPath->count < 1) {
		return NULL;
	}

	char *string = malloc(BUFSIZ * sizeof(char));
	if (string == NULL) {
		perror("string malloc");
		exit(EXIT_FAILURE);
	}
		
	int index = indexPath->indexPath[0];
	sprintf(string, "%d", index);
		
	int i;
	for (i = 1; i < indexPath->count; ++i) {
		int index = indexPath->indexPath[i];
		sprintf(string, "%s:%d", string, index);
	}
	
	return string;
}

char *k_tree_string_from_node(KTree *tree, KTreeNode *node){
	KTreeIndexPath *indexPath = k_tree_indexpath_of_node(tree, node);
	char *string = k_tree_string_from_indexpath(indexPath);
	k_tree_indexpath_free(indexPath);
	return string;
}

KTreeNode *k_tree_node_at_indexpath(KTree *tree, KTreeIndexPath *indexPath){
	if (indexPath->count < 1) {
		return NULL;
	}

	int index = indexPath->indexPath[0];
	KTreeNode *ptr = k_list_item_at(tree, index);
	for (int i = 1; i < indexPath->count; ++i) {
		if (ptr == NULL) {
			return NULL;
		}
		
		int index = indexPath->indexPath[i];
		ptr = k_list_item_at(ptr->children, index);
	}

	return ptr;
}

KTreeNode *k_tree_node_at_indexpath_string(KTree *tree, const char *string){
	KTreeIndexPath *indexPath = k_tree_indexpath_from_string(string);
	KTreeNode *node = k_tree_node_at_indexpath(tree, indexPath);
	k_tree_indexpath_free(indexPath);
	return node;
}

struct k_tree_foreach_node_struct {
	void *user_data;
	int (*callback)(KTreeNode *node, KTreeIndexPath *indexPath, void *user_data);	
	KTreeIndexPath *indexPath;
	int index;
};

int k_tree_foreach_node_callback(void *item, void *_user_data){
	struct k_tree_foreach_node_struct *data = _user_data; 
	void *user_data = data->user_data;
	int (*callback)(KTreeNode *node, KTreeIndexPath *indexPath, void *user_data) = data->callback;	
	
	//update indexPath
	data->indexPath->indexPath[data->indexPath->count -1] = data->index;
	data->index++;

	KTreeIndexPath *indexPath = k_tree_indexpath_new_from_indexpath(data->indexPath);
	
	KTreeNode *node = (KTreeNode *)item;
	KList *children = node->children;
	int c = callback(node, indexPath, user_data);
	if (c!=0) {
		return c;
	}

	//run callback for each children in node
	if (!k_list_is_empty(children)) {
		struct k_tree_foreach_node_struct newdata; 
		newdata.user_data = user_data;
		newdata.callback = callback;
		newdata.indexPath = k_tree_indexpath_new_from_indexpath(data->indexPath);
		k_tree_indexpath_add_index(newdata.indexPath, 0); //add new index to path
		newdata.index = 0;	
		k_list_foreach_item(children, &newdata, k_tree_foreach_node_callback);
	}

	return 0;
}

void k_tree_foreach_node(KTree *tree, KTreeNode *parent, void *user_data, int (*callback)(KTreeNode *node, KTreeIndexPath *indexPath, void *user_data)){
	struct k_tree_foreach_node_struct data; 
	data.user_data = user_data;
	data.callback = callback;
	data.indexPath = k_tree_indexpath_new();
	k_tree_indexpath_add_index(data.indexPath, 0);
	data.index = 0;

	if (parent == NULL) {
		k_list_foreach_item(tree, &data, k_tree_foreach_node_callback);
	} else {
		k_list_foreach_item(parent->children, &data, k_tree_foreach_node_callback);
	}

	k_tree_indexpath_free(data.indexPath);
}

void k_tree_remove_node(KTree *tree, KTreeNode *node){
	if (node->parent == NULL) {
		k_tree_node_free(node);
		k_list_remove_item(tree, node);
	} else {
		k_tree_node_free(node);
		k_list_remove_item(node->parent->children, node);
	}
}
