#include <iostream>

using namespace std;

typedef struct Node *PtrToNode;

struct Node {
	int Data; // 存储数据
	PtrToNode Next;  //下一节点
};

typedef PtrToNode List;

List read()
{
	int temp;
	List L = NULL, p;
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
	List L1, L2, L3, p;
	L1 = read();
	L2 = read();
	L3 = NULL;
	
	while (L1 != NULL && L2 != NULL) {
		if (L1->Data == L2->Data) {
			p = (List)malloc(sizeof(List));
			p->Data = L1->Data;
			p->Next = L3;
			L3 = p;
			L1 = L1->Next;
			L2 = L2->Next;
		}
		else if (L1->Data > L2->Data) {
			L1 = L1->Next;
		}
		else {
			L2 = L2->Next;
		}
	}

	/*输出L3*/
	if (L3 == NULL)
		cout << "NULL";
	else {
		
		cout << L3->Data;
		L3 = L3->Next;
		
		while (L3 != NULL) {
			cout << " " << L3->Data;
			L3 = L3->Next;
		}
	}
	return 0;
}