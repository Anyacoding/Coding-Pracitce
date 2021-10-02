#include <iostream>
#include <string>
using namespace std;

typedef struct node* Tree;

struct node {
	char Data;
	Tree left;
	Tree right;
};

Tree BuildTree(string Fir, string Mid, int prel, int prer, int inl, int inr)
{
	if (prel > prer) {
		return NULL;
	}

	Tree BT = (Tree)malloc(sizeof(struct node));
	BT->Data = Fir[prel];
	BT->left = NULL;
	BT->right = NULL;

	int temp;
	for (int i = inl; i <= inr; i++) {
		if (Fir[prel] == Mid[i]) {
			temp = i;
			break;
		}
	}
	//计算左树的节点数
	
	int numberleft = temp - inl;
	BT->left = BuildTree(Fir, Mid, prel + 1, prel + numberleft, inl, temp - 1);
	BT->right = BuildTree(Fir, Mid, prel + numberleft + 1, prer, temp + 1, inr);
	
	return BT;
}

int FindTreeHight(Tree BT)
{
	if (BT == NULL)
		return 0;

	int m, n;
	m = FindTreeHight(BT->left) + 1;
	n = FindTreeHight(BT->right) + 1;
	
	return m > n ? m : n;
}

int main()
{
	int N, hight;
	string Fir, Mid;
	Tree BT;
	cin >> N >> Fir >> Mid;
	BT = BuildTree(Fir, Mid, 0, N - 1, 0, N - 1);
	hight = FindTreeHight(BT);
	cout << hight;
	return 0;
}