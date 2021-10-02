#include <iostream>
#include <algorithm>

using namespace std;
int N;
int a[100001] = { 0 };

int main()
{
	int i;
	cin >> N;
	for (i = 0; i < N; i++) {
		cin >> a[i];
	}
	sort(a, a + N);
	cout << a[0];
	for (i = 1; i < N; i++) {
		cout << " " << a[i];
	}
	return 0;
}