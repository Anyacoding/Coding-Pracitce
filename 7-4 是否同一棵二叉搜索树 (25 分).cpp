#include <iostream>

using namespace std;

int N, L;
typedef struct nodeTree* Tree;
const int maxsize = 1000;

struct nodeTree {
	int data;
	Tree left;
	Tree right;
};

Tree T[maxsize];

Tree Insert(Tree BST, int x)
{
	if (BST == NULL) {
		BST = new struct nodeTree;
		BST->data = x;
		BST->left = NULL;
		BST->right = NULL;
	}
	if (BST->data > x) {

		BST->left = Insert(BST->left, x);
	}
	if (BST->data < x) {

		BST->right = Insert(BST->right, x);
	}
	return BST;
}


Tree TreeBuild()
{
	Tree BST = NULL;
	int i, x;
	for (i = 0; i < N; i++) {
		cin >> x;
		BST = Insert(BST, x);
	}
	return BST;
}



bool theSame(Tree T1, Tree T2)
{   //����
	if (T1 == NULL && T2 == NULL)
		return true;
	//һ��һ����
	if ((T1 != NULL && T2 == NULL) || (T1 == NULL && T2 != NULL))
		return false;
	//�����յ�data����
	if (T1->data != T2->data)
		return false;
	//����ɸѡʣ�µ��Ƕ����յ�data��ȵ���������������ж�
	return (theSame(T1->left, T2->left) && theSame(T1->right, T2->right));
	
}

int main( )
{
	int i, j;
	
	do {
	    cin >> N;
	    if (N) {
			cin >> L;
		for (i = 0; i <= L; i++) {

			T[i] = TreeBuild();
		}

		for (i = 1; i <= L; i++) {
			if (theSame(T[0], T[i]))
				cout << "Yes" << endl;
			else
				cout << "No" << endl;
		}
	    }
	} while (N);
	
	
	
	return 0;
}