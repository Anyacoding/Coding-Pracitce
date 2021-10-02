#include <iostream>

using namespace std;

int main( )
{
	int a, b, count = 1;
	while (cin >> a >> b) {
		if (b != 0 && count == 1) {
			cout << a * b << " " << b - 1;
			count++;
		}
		else if (b != 0 && count != 1) {
			cout << " " << a * b << " " << b - 1;
		}
		if (b == 0 && count == 1)
			cout << "0 0";
	}


	return 0;
}