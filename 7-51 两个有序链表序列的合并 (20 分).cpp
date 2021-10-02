#include <iostream>

using namespace std;

typedef struct Node* ProToNode;

struct Node {
	int Data;
	ProToNode Next;
};

typedef ProToNode List;

List read()
{
	List L = NULL, p;
	int temp;
	cin >> temp;
	while (temp != -1) {
		p = (List)malloc(sizeof(List));
		p->Data = temp;
		p->Next = L;
		L = p;
		cin >> temp;
	}
	return L;
}

int main()
{
	List L1, L2, L3 = NULL, p;
	L1 = read();
	L2 = read();
	while (L1 != NULL && L2 != NULL) {
		if (L1->Data == L2->Data) {
			p = (List)malloc(sizeof(List));
			p->Data = L1->Data;
			p->Next = L3;
			L3 = p;
			p = (List)malloc(sizeof(List));
			p->Data = L2->Data;
			p->Next = L3;
			L3 = p;
			L1 = L1->Next;
			L2 = L2->Next;
		}
		else if (L1->Data > L2->Data) {
			p = (List)malloc(sizeof(List));
			p->Data = L1->Data;
			p->Next = L3;
			L3 = p;
			L1 = L1->Next;
		}
		else {
			p = (List)malloc(sizeof(List));
			p->Data = L2->Data;
			p->Next = L3;
			L3 = p;
			L2 = L2->Next;
		}
	}
	if (L1 == NULL) {
		while (L2 != NULL) {
			p = (List)malloc(sizeof(List));
			p->Data = L2->Data;
			p->Next = L3;
			L3 = p;
			L2 = L2->Next;
		}
	}
	else if (L2 == NULL) {
		while (L1 != NULL) {
			p = (List)malloc(sizeof(List));
			p->Data = L1->Data;
			p->Next = L3;
			L3 = p;
			L1 = L1->Next;
		}
	}
	/*Êä³öL3*/
	if (L3 != NULL) {
		cout << L3->Data;
		L3 = L3->Next;
		while (L3 != NULL) {
			cout << " " << L3->Data;
			L3 = L3->Next;
		}
	}
	else
		cout << "NULL";

	return 0;
}



































