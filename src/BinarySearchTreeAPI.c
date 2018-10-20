#include "BinarySearchTreeAPI.h"
#include <stdio.h>

TreeNode* createTreeNode(TreeDataPtr data) {

	TreeNode *newNode = malloc(sizeof(TreeNode));
	newNode->data = data;
	newNode->left = NULL;
	newNode->right = NULL;

	return newNode;
}

Tree * createBinTree(CompareFunc compare, DeleteFunc del) {


	Tree *binaryTree = malloc(sizeof(Tree));
	binaryTree->root = NULL;
	binaryTree->compareFunc = compare;
	binaryTree->deleteFunc = del;

	return binaryTree;
}


void destroy (Tree *toDestroy, TreeNode *root) {

	if (root) {
		destroy(toDestroy, root->left);
		destroy(toDestroy, root->right);
		toDestroy->deleteFunc(root->data);
	}

}

void  destroyBinTree(Tree * toDestroy) {
	destroy(toDestroy, toDestroy->root);
	free(toDestroy);
	toDestroy = NULL;
}

void addToTree(Tree * theTree, TreeDataPtr data) {
		
	theTree->root = insertNode(theTree, theTree->root, data);
}

TreeNode *insertNode (Tree *theTree, TreeNode *root, TreeDataPtr data) {

	if (root == NULL) 
		root = createTreeNode(data);
	else if (theTree->compareFunc( root->data, data) > 0) //to place in right child
		root->right = insertNode( theTree, root->right, data);
	else if (theTree->compareFunc( root->data, data) < 0) //to place in left child
		root->left = insertNode(theTree, root->left, data);

	return root;
}

TreeNode * getMinNode (TreeNode *root) {

	TreeNode *currPosition = root;

	while (currPosition->left != NULL)
		currPosition = currPosition->left;

	return currPosition;
}

TreeNode *deleteNode (Tree* theTree, TreeNode *root, TreeDataPtr data) {

	if (root == NULL)
		return root;
	if (theTree->compareFunc(root->data, data) > 0)
		root->right = deleteNode(theTree, root->right, data);
	else if (theTree->compareFunc(root->data, data) < 0)
		root->left = deleteNode(theTree, root->left, data);
	else {

		if (root->left == NULL) {
			TreeNode *temp = root->right;
			theTree->deleteFunc(root->data);
			free(root);
			return temp;
		} 
		else if (root->right == NULL) {
			TreeNode *temp = root->left;
			theTree->deleteFunc(root->data);
			free(root);
			return temp;
		}
		TreeNode *temp = getMinNode(root->right);

		root->data = temp->data;

		root->right = deleteNode(theTree, root->right, temp->data);
	}
	return root;
}

void removeFromTree(Tree * theTree, TreeDataPtr data) {
	theTree->root = deleteNode (theTree, theTree->root, data);
}

TreeDataPtr find(Tree* theTree, TreeNode *root, TreeDataPtr data) {

	if (root == NULL)
		return NULL;
	if (theTree->compareFunc(root->data,data)== 0)
		return root->data;
	else if (theTree->compareFunc(root->data, data) > 0)
		return find(theTree, root->right, data);
	else return find(theTree, root->left, data);


}

TreeDataPtr findInTree( Tree* theTree, TreeDataPtr data ) {
	TreeDataPtr foundData = find(theTree, theTree->root, data);
	return foundData;
}

TreeDataPtr getRootData(Tree * theTree) {
	return theTree->root->data;
}

void print (TreeNode *root, int typeOfPrint, PrintFunc printData) {

	switch (typeOfPrint) {
		case PRE_ORDER:
			if (root) {
				printData(root->data);
				print(root->left, PRE_ORDER, printData);
				print(root->right, PRE_ORDER, printData);
			}
		  	break;
		case IN_ORDER:
			if (root) {
				print(root->left, IN_ORDER, printData);
				printData(root->data);
				print(root->right, IN_ORDER, printData);
			}
			break;
		case POST_ORDER:
			if (root) {
				print(root->left, POST_ORDER, printData);
				print(root->right, POST_ORDER, printData);
				printData(root->data);
			}
			break;
	}

}

void printInOrder(Tree * theTree, PrintFunc printData) {
	print(theTree->root,IN_ORDER,printData);
}

void printPreOrder(Tree * theTree, PrintFunc printData) {
	print(theTree->root,PRE_ORDER,printData);
}

void printPostOrder(Tree * theTree, PrintFunc printData) {
	print(theTree->root,POST_ORDER,printData);
}

int isTreeEmpty(Tree* theTree) {

	if (theTree->root == NULL)
		return 1;
	else return 0;
}

int isLeaf( TreeNode * treeNode) {

	if (treeNode->right == NULL && treeNode->left == NULL)
		return 1;
	else return 0;
}

int hasTwoChildren( TreeNode *treeNode) {

	if (treeNode->right != NULL && treeNode->left != NULL)
		return 1;
	else return 0;
}

int max (int right, int left) {

	if (right > left)
		return right;
	else return left;
}

int getHeight( TreeNode* treeNode ) {
	
	if (treeNode == NULL)
		return 0; 
	int left = getHeight(treeNode->left);
	int right = getHeight(treeNode->right);
	return max(right,left) + 1;
}

