#include <iostream>
const int Maxsize = 1001;
const int infer = 999999;
using namespace std;
int N, M;
int Graph[Maxsize][Maxsize];
int dis[Maxsize];
int MST[Maxsize]; //��С��������Ա����
int cost = 0;
int number = 1;

/*dis����ĺ���Ϊ��㵽��С�������ľ���*/
void CreatDistArray( )
{
	int i, j;
	//������Ĭ��1Ϊ��ʼ���У���Ȼ����Ҳ����
	for (j = 1; j <= N; j++) {
		dis[j] = Graph[1][j];
	}
}

void Prim( )
{
	int i, j;
	int V, W;
	for (i = 1; i <= N; i++) {
		MST[i] = 0;
	}
	MST[1] = 1; //��1��Ϊ��ʼ�������С������
	while (1) {
		int min = infer, mini = 0;
		for (i = 1; i <= N; i++) {
			if (MST[i] == 0 && dis[i] < min) {
				min = dis[i];
				mini = i;
			}
		}
		if (min == infer)
			break;
		V = mini;
		MST[V] = 1;
		number++;
		/*����������dis���������*/
		for (W = 1; W <= N; W++) {
			if (MST[W] == 0) {
				if (dis[W] > Graph[V][W]) {
					dis[W] = Graph[V][W];
				}

			}
		}
		cost = cost + min;
	}
}

int main( )
{
	int i, j;
	int x, y, w;
	cin >> N >> M;
	for (i = 0; i < Maxsize; i++)
		for (j = 0; j < Maxsize; j++) {
			if (i == j)
				Graph[i][j] = 0;
			else
				Graph[i][j] = infer;
		}
	
	if (N) {
		for (i = 0; i < M; i++) {
			cin >> x >> y >> w;
			Graph[x][y] = Graph[y][x] = w;
		}
		CreatDistArray();
		Prim();
		if (number == N)
			cout << cost << endl;
		else
			cout << "-1" << endl;
	}



	return 0;
}