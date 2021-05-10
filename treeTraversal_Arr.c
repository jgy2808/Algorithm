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

void preorder_arr(char arr[], int root) {
	if (arr[root] >= 'A' && arr[root] <= 'Z') {
		printf("%c", arr[root]);
		preorder_arr(arr, root * 2);
		preorder_arr(arr, root * 2 + 1);
	}
}

void inorder(treeNode* root) {
	if (root) {
		inorder(root->left);
		printf("%c", root->data);
		inorder(root->right);
	}
}

void inorder_arr(char arr[], int root) {
	if (arr[root] >= 'A' && arr[root] <= 'Z') {
		inorder_arr(arr, root * 2);
		printf("%c", arr[root]);
		inorder_arr(arr, root * 2 + 1);
	}
}

void postorder(treeNode* root) {
	if (root) {
		postorder(root->left);
		postorder(root->right);
		printf("%c", root->data);
	}
}

void postorder_arr(char arr[], int root) {
	if (arr[root] >= 'A' && arr[root] <= 'Z') {
		postorder_arr(arr, root * 2);
		postorder_arr(arr, root * 2 + 1);
		printf("%c", arr[root]);
	}
}

void main() {
	char t[16] = {'0', 'A', 'B', 'C', 'D', '0', 'E', 'F', '0', '0', '0', '0', '0', '0', '0', 'G' };
	treeNode* t7 = makeRootNode('G', NULL, NULL);
	treeNode* t6 = makeRootNode('F', NULL, t7);
	treeNode* t5 = makeRootNode('E', NULL, NULL);
	treeNode* t4 = makeRootNode('D', NULL, NULL);
	treeNode* t3 = makeRootNode('C', t5, t6);
	treeNode* t2 = makeRootNode('B', t4, NULL);
	treeNode* t1 = makeRootNode('A', t2, t3);

	for (int i = 0; i < 16; i++) {
		printf("%2c", t[i]);
	}printf("\n");

	printf("preorder_Arr : ");
	preorder_arr(t, 1);
	printf("\npreorder : ");
	preorder(t1);

	printf("\n\ninorder_Arr : ");
	inorder_arr(t, 1);
	printf("\ninorder : ");
	inorder(t1);

	printf("\n\npostorder_Arr : ");
	postorder_arr(t, 1);
	printf("\npostorder : ");
	postorder(t1);

}