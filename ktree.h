/**
 * File              : ktree.h
 * Author            : Igor V. Sementsov <ig.kuzm@gmail.com>
 * Date              : 19.02.2022
 * Last Modified Date: 20.02.2022
 * Last Modified By  : Igor V. Sementsov <ig.kuzm@gmail.com>
 */

//KTree - tree container for C

#include <stdio.h>

#include "klist/klist.h"


typedef KList KTree;

typedef struct k_tree_node_t {
	struct k_tree_node_t *parent;
	KList *children;
	void *data;
} KTreeNode;


//create new tree
KTree *k_tree_new();

//create new tree node
KTreeNode *k_tree_node_new(void *data);

//return tree node at index
KTreeNode *k_tree_node_at(KTree *tree, KTreeNode *parent, int index);

//append tree node to tree
void k_tree_append(KTree *tree, KTreeNode *parent, KTreeNode *node);

//prepend
void k_tree_prepend(KTree *tree, KTreeNode *parent, KTreeNode *node);

//insert at index
void k_tree_insert_node_at_index(KTree *tree, KTreeNode *parent, KTreeNode *node, int index);

//move node
void k_tree_move_node(KTree *tree, KTreeNode *from_parent, int from_index, KTreeNode *to_parent, int to_index);

//remove node
void k_tree_remove_node_at_index(KTree *tree, KTreeNode *parent, int index);

typedef struct k_tree_indexpath_t {
	int *indexPath;
	int count;
} KTreeIndexPath;

//free indexpath
void k_tree_indexpath_free(KTreeIndexPath *indexPath);

//return indexpath from string, like "0:1:0:2"
KTreeIndexPath *k_tree_indexpath_from_string(const char *string);

//return string from indexpath
char *k_tree_string_from_indexpath(KTreeIndexPath *indexPath);
char *k_tree_string_from_node(KTree *tree, KTreeNode *node);

//return indexpath of node
KTreeIndexPath *k_tree_indexpath_of_node(KTree *tree, KTreeNode *node);

//return node at indexpath
KTreeNode *k_tree_node_at_indexpath(KTree *tree, KTreeIndexPath *indexPath);
KTreeNode *k_tree_node_at_indexpath_string(KTree *tree, const char *string);

//foreach node run callback. parent = NULL for root tree. 
//don't forget to free(indexPath) in callback function and free(node) when needed
void k_tree_foreach_node(KTree *tree, KTreeNode *parent, void *user_data, int(*callback)(KTreeNode *node, KTreeIndexPath *indexPath, void *user_data));

//remove node
void k_tree_remove_node(KTree *tree, KTreeNode *node);
