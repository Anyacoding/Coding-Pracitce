#include <iostream>
using namespace std;
int N, M;
int Graph[101][101];
const int infer = 99999;
int main()
{
	int i, j, k;
	int x, y, w;
	cin >> N >> M;
	for (i = 0; i < 101; i++)
		for (j = 0; j < 101; j++) {
			if (i == j)
				Graph[i][j] = 0;
			else
				Graph[i][j] = infer;
		}
	
	for (i = 1; i <= M; i++) {
		cin >> x >> y >> w;
		Graph[x][y] = w;
		Graph[y][x] = w;
	}

	//FloydËã·¨
	for (k = 1; k <= N; k++)
		for (i = 1; i <= N; i++)
			for (j = 1; j <= N; j++) {
				if (Graph[i][j] > Graph[i][k] + Graph[k][j])
					Graph[i][j] = Graph[i][k] + Graph[k][j];
			}
	int max, min = infer, mini;
	
	for (i = 1; i <= N; i++) {
		max = 0;
		for (j = 1; j <= N; j++) {
			if (Graph[i][j] > max) {
				max = Graph[i][j];
			}
		}

		if (min > max) {
			min = max;
			mini = i;
		}

	}

	if (min == infer)
		cout << "0" << endl;
	else
	cout << mini << " " << min << endl;


	return 0;
}
