#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

typedef struct treeNode {
	char data;
	struct treeNode *left;
	struct treeNode *right;

}treeNode;

treeNode* makeRootNode(char data, treeNode* leftNode, treeNode* rightNode) {
	treeNode* root = (treeNode *)malloc(sizeof(treeNode));
	if (root != NULL) {
		root->data = data;
		root->left = leftNode;
		root->right = rightNode;
	}
	return root;
}

void preorder(treeNode* root) {
	if (root) {
		printf("%c", root->data);
		preorder(root->left);
		preorder(root->right);
	}
}

void inorder(treeNode* root) {
	if (root) {
		inorder(root->left);
		printf("%c", root->data);
		inorder(root->right);
	}
}

void postorder(treeNode* root) {
	if (root) {
		postorder(root->left);
		postorder(root->right);
		printf("%c", root->data);
	}
}

void main() {
	treeNode* t7 = makeRootNode('G', NULL, NULL);
	treeNode* t6 = makeRootNode('F', NULL, t7);
	treeNode* t5 = makeRootNode('E', NULL, NULL);
	treeNode* t4 = makeRootNode('D', NULL, NULL);
	treeNode* t3 = makeRootNode('C', t5, t6);
	treeNode* t2 = makeRootNode('B', t4, NULL);
	treeNode* t1 = makeRootNode('A', t2, t3);

	printf("preorder : ");
	preorder(t1);

	printf("\ninorder : ");
	inorder(t1);

	printf("\npostorder : ");
	postorder(t1);

}