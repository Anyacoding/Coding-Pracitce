#include <iostream>
#include <map>
#include <string>
using namespace std;


int main()
{
	int N;
	int i, flag = -1;
	char state;
	string QQnumber, code;
	cin >> N;
	map<string, string> m;
	for (i = 1; i <= N; i++) {
		cin >> state >> QQnumber >> code;
		if (state == 'N') {
			flag = m.count(QQnumber);
			if (flag == 1) {
				cout << "ERROR: Exist" << endl;
			}
			else {
				m[QQnumber] = code;
				cout << "New: OK" << endl;
			}
		}
		if (state == 'L') {
			flag = m.count(QQnumber);
			if (flag == 0) {
				cout << "ERROR: Not Exist" << endl;
			}
			else {
				if (code == m[QQnumber])
					cout << "Login: OK" << endl;
				else
					cout << "ERROR: Wrong PW" << endl;
			}
		}
	}

	cout << m.find("shit") << endl;
	return 0;
}