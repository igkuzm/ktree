# Container for TREE

Container to store tree-like nodes written in pure C.
Simpe example:

```
#include "ktree.h"

int callback(KTreeNode *node, KTreeIndexPath *indexPath, void *user_data) {
	(char *)string = node->data;
	char buffer[BUFSIZ];
	for (int i=0; i<indexPath->count, i++) { //add spaces for each children
		sprintf(buffer, " ");
	}
	printf("%s%s\n", buffer, string);
	
	k_tree_indexpath_free(indexPath); //free memory
	return 0;
}

int main(int argc, char *argv[])
{
	KTree *tree = k_tree_new(); //create new container
	KTreeNode *hello = k_tree_node_new("Hello"); //create new node with data
	k_tree_append(tree, NULL, hello); //append hello node to ROOT
	KTreeNode *world = k_tree_node_new("World!");
	k_tree_append(tree, hello, hello); //append world node to hello

	k_list_foreach_node(tree, NULL, NULL, callback);//run callback for each node and it's children

	k_tree_free(tree); //free memory

	
return 0;
}
```

