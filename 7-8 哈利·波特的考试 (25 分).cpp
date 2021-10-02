#include <iostream>
const int Maxsize = 101;
using namespace std;
int N, M;
int Magic[Maxsize][Maxsize];
int dist[Maxsize];
int animal[Maxsize] = { 0 };

void CreatDistArray(int i)
{
	int j;

	dist[i] = 0;

	for (j = 1; j <= N; j++) {
		if (j != i)
		dist[j] = Magic[i][j];
	}

}

int Dijkstra(int i)
{
	int V, W;
	int j;
	int collected[Maxsize] = { 0 };
	int count = 0;
	int max = 0;
	while (1) {
		int min = -1;
		int minj = -1;
		for (j = 1; j <= N; j++) {
			if (collected[i] == 0 && dist[j] > 0 && dist[j] > min) {
				min = dist[j];
				minj = j;
			}
				
		}
		if (minj != -1)
			V = minj;
		else
			break;
		collected[V] = 1;
		count++;
		for (W = 1; W <= N; W++) {
			if (collected[i] == 0 && dist[W] > 0 && (dist[V] + Magic[V][W]) < dist[W]) {
				dist[W] = dist[V] + Magic[V][W];	
			}
			if (dist[W] > max)
				max = dist[W];
		}
	}
	if (count == N)
		return max;
	else
		return -1;
}


int main()
{
	int i, j;
	int u, v, w;
	int min = 1000;
	int mini;
	cin >> N >> M;
	for (i = 0; i < N; i++)
		for (j = 0; j < N; j++) {
			Magic[i][j] = -1;
			Magic[i][i] = 0;
		}
			
	if (N) {
		for (i = 1; i <= M; i++) {
			cin >> u >> v >> w;
			Magic[u][v] = w;
		}
		
		for (i = 1; i <= N; i++) {
			CreatDistArray(i);
			animal[i] = Dijkstra(i);
			if (animal[i] < min && animal[i] > 0) {
				mini = i;
				min = animal[i];
			}
		}

		if (min == 1000)
			cout << "0" << endl;
		else
			cout << mini << " " << min << endl;

	}



	return 0;
}