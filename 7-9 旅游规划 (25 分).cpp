#include <iostream>
const int Maxsize = 1000;
const int infer = 99999;
using namespace std;
int N, M, S, D;
int Graph[Maxsize][Maxsize];
int Cost[Maxsize][Maxsize];



int main()
{
	int i, j, k;
	int x, y, len, dollar;
	cin >> N >> M >> S >> D;
	for (i = 0; i < Maxsize; i++)
		for (j = 0; j < Maxsize; j++) {
			if (i == j)
				Graph[i][j] = 0;
			else
				Graph[i][j] = infer;
			Cost[i][j] = infer;
		}

	if (N) {
		for (i = 1; i <= M; i++) {
			cin >> x >> y >> len >> dollar;
			Graph[x][y] = Graph[y][x] = len;
			Cost[x][y] = Cost[y][x] = dollar;
		}
		//Floyd
		for (k = 0; k < N; k++) 
			for (i = 0; i < N; i++)
				for (j = 0; j < N; j++) {
			if (Graph[i][j] > Graph[i][k] + Graph[k][j] || (Graph[i][j] == Graph[i][k] + Graph[k][j] && Cost[i][j] > Cost[i][k] + Cost[k][j])) {
				Graph[i][j] = Graph[i][k] + Graph[k][j];
				Cost[i][j] = Cost[i][k] + Cost[k][j];
			}
		}

		
		cout << Graph[S][D] << " " << Cost[S][D] << endl;
	}

	return 0;
}