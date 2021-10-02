#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

int main()
{
	int N;
	int i, j;
	long long PhoneNumber1, PhoneNumber2;
	long long PhoneNumber, number;
	cin >> N;
	map<long long, int> m;
	for (i = 1; i <= N; i++) {
		cin >> PhoneNumber1 >> PhoneNumber2;
		m[PhoneNumber1]++;
		m[PhoneNumber2]++;
	}
	
	long long max = -1;
	int count = 0;
	for (auto it = m.begin(); it != m.end(); it++) {
		if (it->second > max) {
			max = it->second;
			PhoneNumber = it->first;
			number = it->second;
		}
	}
	for (auto it = m.begin(); it != m.end(); it++) {
		if (it->second == max)
			count++;
	}
	if (count == 1)
	cout << PhoneNumber << " " << number;
	else
	cout << PhoneNumber << " " << number << " " << count;
	return 0;
}