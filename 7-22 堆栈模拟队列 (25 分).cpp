#include <iostream>
#include <string>

using namespace std;

int N1, N2;

struct node {
	int Stack[101];
	int top = 0;
}S1, S2;//S1输入栈，S2输出栈


void Push(int x)
{
	if (S1.top < N1) {
	S1.top++;
	S1.Stack[S1.top] = x;
	}
	else if (S1.top == N1 && S2.top == 0) {
		
		while (S1.top != 0) {
			S2.Stack[++S2.top] = S1.Stack[S1.top];
			S1.top--;
		}
		S1.top++;
		S1.Stack[S1.top] = x;	
	}
	else if (S1.top == N1 && S2.top != 0)
		cout << "ERROR:Full" << endl;
}

void Pop()
{
	if (S2.top > 0) {
		cout << S2.Stack[S2.top] << endl;
		S2.top--;
	}
	else if (S2.top == 0 && S1.top != 0) {
		while (S1.top != 0) {
			S2.Stack[++S2.top] = S1.Stack[S1.top];
			S1.top--;
		}
		cout << S2.Stack[S2.top] << endl;
		S2.top--;
	}
	else
		cout << "ERROR:Empty" << endl;
}

int main( )
{
	int x, y;
	char order;
	int z;
	cin >> x >> y;
	//S1输入栈的容量要小一点
	if (x > y) {
		N1 = y;
		N2 = x;
	}
	else {
		N1 = x;
		N2 = y;
	}
	
	while (1) {
		cin >> order;
		if (order == 'A') {
			cin >> z;
			Push(z);
		}
		if (order == 'D') {
			Pop();
		}
		if (order == 'T')
			break;
	}
	

	return 0;
}
