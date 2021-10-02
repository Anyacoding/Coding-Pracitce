#include <iostream>

using namespace std;

int queue[100001];

int main()
{
	int K, number, head = 1, tail = 1, count = 0;
	cin >> K;
	while (1) {
		cin >> number;
		if (number < 0) {
			queue[tail] = number;
			tail++;
			break;
		}
		else {
			queue[tail] = number;
			tail++;
			count++;
		}
	}
	tail = head + K;
	
	if (tail > count + 1) {
		cout << "NULL";
		return 0;
	}
	
	while (1) {
		if (queue[tail] >= 0) {
			head++;
			tail++;
		}
		else {
			cout << queue[head];
			break;
		}
	}

	return 0;
}