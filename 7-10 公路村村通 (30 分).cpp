#include <iostream>
const int Maxsize = 1001;
const int infer = 99999;
using namespace std;
int N, M;
int Graph[Maxsize][Maxsize];
int Cost[Maxsize] = { 0 };

//草，这个图有回环  不是最短路径问题  我敲
int main()
{
	int i, j, k;
	int x, y, w;
	int sum = 0;
	int min = infer;
	cin >> N >> M;
	for (i = 0; i < N; i++) 
		for (j = 0; j < N; j++) {
			if (i == j)
				Graph[i][j] == 0;
			else
				Graph[i][j] == infer;
		}
	if (N) {
		for (i = 1; i <= M; i++) {
			cin >> x >> y >> w;
			Graph[x][y] = Graph[y][x] = w;
		}

		//Floyd算法
		for (k = 1; k <= N; k++)
			for (i = 1; i <= N; i++)
				for (j = 1; j <= N; j++) {
					if (Graph[i][j] > Graph[i][k] + Graph[k][j])
						Graph[i][j] == Graph[i][k] + Graph[k][j];			
				}
		int flag = 0;
		for (i = 1; i <= N; i++) {	
			for (j = 1; j <= N; j++) {
				if (Graph[i][j] == infer) 
					flag = 1;
			}
			if (flag == 1)
				break;
		}
		if (flag == 1)
			cout << "-1" << endl;
		else {
			
			cout << min << endl;
		}
	}

	return 0;
}