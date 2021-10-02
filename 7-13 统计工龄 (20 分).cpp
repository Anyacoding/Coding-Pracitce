#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	int N, a[100001] = { 0 }, number[100001] = { 0 };
	int i, temp, k = 0;
	cin >> N;
	for (i = 0; i < N; i++) {
		cin >> a[i];
	}
	sort(a, a + N);
	temp = a[0];
	for (i = 0; i < N; i++) {
		if (a[i] == temp)
			number[a[i]]++;
		else {
			cout << temp << ":" << number[temp] << endl;
			temp = a[i];
			number[a[i]]++;
		}
	}
	cout << temp << ":" << number[temp] << endl;

	return 0;
}