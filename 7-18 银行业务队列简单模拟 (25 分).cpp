#include <iostream>

using namespace std;

struct node {
	int queue[1001];
	int head = 0;
	int tail = 0;
} Q1, Q2; //��������,Q1ΪA���ڣ�Q2ΪB����

int main()
{
	int N, number, temple, count = 1;
	cin >> N;
	temple = N;
	while (temple != 0) {
		cin >> number;
		if (number % 2 == 0) {
			Q2.queue[Q2.tail] = number;
			Q2.tail++;
		}
		else {
			Q1.queue[Q1.tail] = number;
			Q1.tail++;
		}
		temple--;
	}
	
	temple = N;  

	if (Q1.head != Q1.tail) {
		cout << Q1.queue[Q1.head];
		Q1.head++;
	}
	else {
		cout << Q2.queue[Q2.head];
		Q2.head++;
	}

	temple--;

	while (temple != 0) {
		count++;
		if (count % 3 != 0 && Q1.head != Q1.tail) {
			cout << " " << Q1.queue[Q1.head];
			Q1.head++;
		}
		else {
			cout << " " << Q2.queue[Q2.head];
			Q2.head++;
		}
		temple--;
	}

	return 0;
}