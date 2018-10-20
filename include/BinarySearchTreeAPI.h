
#ifndef BST_GUARD
#define BST_GUARD

#include <stdlib.h>

// Constants to specify the type of traversal
#define IN_ORDER 0
#define PRE_ORDER 1
#define POST_ORDER 2

/**
 * Function pointer tyepdefs
 */
typedef int (*CompareFunc)(const void* a, const void* b);
typedef void (*DeleteFunc)(void* data);
typedef void (*PrintFunc)(void* data);

/*
 * Typedef the void* to make the API cleaner and more readable.
 */
typedef void* TreeDataPtr;

/**
* Typedef the binTreeNode struct
*/
typedef struct binTreeNode TreeNode;

/**
 * This is the definition of the Binary Tree.
 *
 */
typedef struct binTree
{
	TreeNode *root;
	CompareFunc compareFunc;
	DeleteFunc deleteFunc;
} Tree;

/*
 * A Single Binary Tree Node.
 * Left and Right branches
 * void* data
 */
struct binTreeNode{

	TreeDataPtr data;
	TreeNode * left;
	TreeNode * right;

};

/**
 * Creates a TreeNode. TreeNode children are set to NULL and data is set to the passed in data.
 * @param data - the data to be stored within the Node. 
 * @return Newly created TreeNode
 *
 */
TreeNode* createTreeNode(TreeDataPtr data);

/**
 * createBinTree allocates memory for Tree and assigned function pointers
 * @param  compare [Function pointer to Compare data in tree nodes]
 * @param  del     [Function pointer to delete data from node]
 * @return Newly created Tree
 */
Tree * createBinTree(CompareFunc compare, DeleteFunc del);

/**
* Recursively destroys each node
* @param toDestroy
* @param node pointer
*/
void destroy (Tree *toDestroy, TreeNode *root);

/**
 * destroyBinTree - remove all items and free memory
 * @param  toDestroy - the tree
 * @return
 */
void  destroyBinTree(Tree * toDestroy);

/**
 * Add data to a tree
 * @param theTree 
 * @param data    
 */
void addToTree(Tree * theTree, TreeDataPtr data);

/**
* Function to insert a node to tree appropriately
*/
TreeNode *insertNode (Tree * theTree, TreeNode *root, TreeDataPtr data);

/**
* Function locates most left of the right branch
* @return TreeNode
*/
TreeNode * getMinNode (TreeNode *root);

/**
* Function to recursively locate and remove a node from the tree
* the BST properties remain intact
*/
TreeNode *deleteNode (Tree* theTree, TreeNode *root, TreeDataPtr data);

/**
 * Remove data from the tree
 * @param theTree 
 * @param data    
 */
void removeFromTree(Tree * theTree, TreeDataPtr data);

/**
 * This function searches the tree for the target data
 * @param  theTree 
 * @param  data    
 * @return         NULL if fail, otherwise return data
 */
TreeDataPtr findInTree( Tree* theTree, TreeDataPtr data );

/**
 * Get data from the root of the Tree if it exists.
 * @param  theTree 
 * @return NULL if tree is empty, otherwise return root
 */
TreeDataPtr getRootData(Tree * theTree);

/**
* Recursive print 
* @param root
* @param typeOfPrint - (post/pre/in order traversal)
* @param printFunction pointer
*/
void print (TreeNode *root, int typeOfPrint, PrintFunc printData);

/**
 * [printInOrder This function prints the tree using an inOrder traversal
 * @param theTree   [description]
 * @param printData [description]
 */
void printInOrder(Tree * theTree, PrintFunc printData);

/**
 * [printPreOrder This function prints the tree using an preOrder traversal
 * @param theTree   [description]
 * @param printData [description]
 */
void printPreOrder(Tree * theTree, PrintFunc printData);

/**
 * [printPostOrder This function prints the tree using an postOrder traversal
 * @param theTree   [description]
 * @param printData [description]
 */
void printPostOrder(Tree * theTree, PrintFunc printData);

/**
 * Checks if a tree is empty
 * @param  theTee [description]
 * @return        0 if false, 1 otherwise
 */
int isTreeEmpty(Tree* theTee);


/**
 * Helper function for checking if a single node is a leaf (no children)
 * @param  treeNode [description]
 * @return          0 if false, 1 otherwise
 */
int isLeaf( TreeNode * treeNode);

/**
 * Helper funciton for checking if a single node has two children.
 * @param  treeNode [description]
 * @return         0 if false, 1 otherwise
 */
int hasTwoChildren( TreeNode *treeNode);

/**
 * Helper funciton Get the height of a particulat Node in the tree. 
 * @param  treeNode [description]
 * @return    (1-Based) heigh for the tree. 
 */
int getHeight( TreeNode* treeNode );


#endif
