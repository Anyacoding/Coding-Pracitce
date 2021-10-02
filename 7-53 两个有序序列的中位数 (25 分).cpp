#include <iostream>

using namespace std;

int S1[100001], S2[100001], S3[200002];
int infer = 9999999;

int main()
{
	int N;
	int i, j, k;
	cin >> N;
	for (i = 0; i < 100001; i++) {
		S1[i] = S2[i] = S3[i] = infer;
	}
	for (i = 1; i <= N; i++) {
		cin >> S1[i];
	}
	for (i = 1; i <= N; i++) {
		cin >> S2[i];
	}
	i = j = k = 1;
	while (S1[i] != infer && S2[j] != infer) {
		if (S1[i] == S2[j]) {
			S3[k] = S1[i];
			k++;
			S3[k] = S1[i];
			i++;
			j++;
			k++;
		}
		else if (S1[i] > S2[j]) {
			S3[k] = S2[j];
			j++;
			k++;
		}
		else {
			S3[k] = S1[i];
			i++;
			k++;
		}
	}

	if (S1[i] != infer) {
		while (S1[i] != infer) {
			S3[k] = S1[i];
			i++;
			k++;
		}
	}
	else if (S2[j] != infer) {
		while (S2[j] != infer) {
			S3[k] = S2[j];
			j++;
			k++;
		}
	}
	cout << S3[N];
	return 0;
}