#include <iostream>
const int MAXSIZE = 1001;
using namespace std;
int N, M;
int Heap[MAXSIZE];

void HeapInsert(int Heap[], int x, int i)
{
	int temp = x;
	if (Heap[i / 2] < x) 
		Heap[i] = x;
	if (Heap[i / 2] > x) {
		Heap[i] = Heap[i / 2];
		Heap[i / 2] = x;
		HeapInsert(Heap, x, i / 2);
	}
}

void BuildHeap()
{
	int i, x;
	for (i = 0; i < MAXSIZE; i++) {
		Heap[i] = -20000;
	}
	for (i = 1; i <= N; i++) {
		cin >> x;
		HeapInsert(Heap, x, i);
	}
}

void BackHome(int i)
{
	int flag = 1;
	while (i) {
		if (flag) {
			cout << Heap[i];
			flag = 0;
			i = i / 2;
		}
		else {
			cout << " " << Heap[i];
			i = i / 2;
		}
	}
	cout << endl;
}

int main()
{    
	int child;
	cin >> N >> M;
	if (N) {
		BuildHeap();
	

	do {
		cin >> child;
		BackHome(child);
		M--;
	} while (M);
	
	}



	return 0;
}