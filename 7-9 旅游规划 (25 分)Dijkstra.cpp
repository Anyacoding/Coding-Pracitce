#include <iostream>
#include <cstring>
using namespace std;
const int Maxsize = 501;
const int infer = 99999;
int  N, M, S, D;
int Graph[Maxsize][Maxsize];
int Cost[Maxsize][Maxsize];
int dis[Maxsize], cost[Maxsize];
void CreatDisArray (int i)
{
	int j;
	for (j = 0; j < N; j++) {
		dis[j] = Graph[i][j];
		cost[j] = Cost[i][j];
	}
}

void Dijkstra(int i)
{
	int j;
	int collected[Maxsize];
	int V, W;
	memset(collected, 0, sizeof(collected));
	
	while (1) {
		int min = infer, minj;
		for (j = 0; j < N; j++) {
			if (dis[j] < min && collected[j] == 0) {
				min = dis[j];
				minj = j;
			}
		}
		if (min == infer)
			return ;
		else
		V = minj;
		collected[V] = 1;
		for (W = 0; W < N; W++) {
			if(Graph[V][W] < infer)
			if (dis[W] > dis[V] + Graph[V][W] || (cost[W] > cost[V] + Cost[V][W] && dis[W] == dis[V] + Graph[V][W])) {
				dis[W] = dis[V] + Graph[V][W];
				cost[W] = cost[V] + Cost[V][W];
			}
			if (W == D)
				break;
		}

	}
}




int main()
{
	int i, j;
	int x, y, len, money;
	cin >> N >> M >> S >> D;
	for (i = 0; i < N; i++)
		for (j = 0; j < N; j++) {
			if (i == j)
				Graph[i][j] = 0;
			else
				Graph[i][j] = infer;
			
			Cost[i][j] = infer;
		}
	if (N) {
		for (i = 0; i < M; i++) {
			cin >> x >> y >> len >> money;
			Graph[x][y] = Graph[y][x] = len;
			Cost[x][y] = Cost[y][x] = money;
		}
		CreatDisArray(S);
		Dijkstra(S);
		cout << dis[D] << " " << cost[D] << endl;
	}
	return 0;
}