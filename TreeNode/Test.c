#include "TreeNode.h"


int main()
{
	STNode* A = (STNode*)malloc(sizeof(STNode));
	A->data = 'A';
	A->left = NULL;
	A->right = NULL;

	STNode* B = (STNode*)malloc(sizeof(STNode));
	B->data = 'B';
	B->left = NULL;
	B->right = NULL;

	STNode* C = (STNode*)malloc(sizeof(STNode));
	C->data = 'C';
	C->left = NULL;
	C->right = NULL;

	STNode* D = (STNode*)malloc(sizeof(STNode));
	D->data = 'D';
	D->left = NULL;
	D->right = NULL;

	STNode* E = (STNode*)malloc(sizeof(STNode));
	E->data = 'E';
	E->left = NULL;
	E->right = NULL;

	A->left = B;
	A->right = C;
	B->left = D;
	B->right = E;

	PrevOrder(A);
	printf("\n");

	InOrder(A);
	printf("\n");

	PostOrder(A);
	printf("\n");

	/*TreeSize(A);
	printf("TreeSize:%d\n", size);

	size = 0;
	TreeSize(B);
	printf("TreeSize:%d\n", size);*/

	/*int Asize = 0;
	TreeSize(A, &Asize);
	printf("TreeSize:%d\n", Asize);

	int Bsize = 0;
	TreeSize(B, &Bsize);
	printf("TreeSize:%d\n", Bsize);*/


	printf("TreeSize:%d\n", TreeSize(A));

	printf("TreeSize:%d\n", TreeSize(B));

	LevelOrder(A);

	return 0;
}