#include <iostream>
#include <algorithm>
const int Maxsize = 3003;
const int infer = 999999;
using namespace std;
int N, M;
int MST[Maxsize] = { 0 };
int number = 0;
int cost = 0;
int father[Maxsize];
struct node {
	int x;
	int y;
	int w;
}e[Maxsize];

bool cmp(node a, node b)
{
	return a.w < b.w;
}

int FindFather(int x)
{       
	//虽然这样也能达到找到祖先的目的，但是没有压缩路径导致效率降低了
	while (father[x] != x) {
		x = father[x];
	}

	return x;
}

void Kuskal( )
{
	int i = 1, j;
	sort(e + 1, e + M + 1, cmp);
	while (1) {
		int min = infer, mini = 0, minj = 0;
		for (; i <= M; i++) {
			if (e[i].w != 0) { 
			//这里其实就是一个简陋的并查集，唯一的不足是找祖先的时候没有进行路径压缩
			int father1 = FindFather(e[i].x);
			int father2 = FindFather(e[i].y);
				if (e[i].w < min && father1 != father2) {
					min = e[i].w;
					father[father1] = father2; 
					e[i].w = 0;
					break;
				}
				
			}
		}
		//发现问题了，这个只能判断近亲，远亲判断不了，还是得并查集
		if (min == infer)
			break;
		
		number++;
		cost = cost + min;
	}
}

int main()
{
	int i, j;
	
	cin >> N >> M;
	for (i = 0; i <= M; i++) {
		e[i].x = 0;
		e[i].y = 0;
		e[i].w = 0;
	}

	if (N) {
		for (i = 1; i <= M; i++) {
			cin >> e[i].x >> e[i].y >> e[i].w;	
		}
		//初始化并查集
		for (i = 1; i <= N; i++) {
			father[i] = i;
		}

		Kuskal( );
		
		if (number == N - 1)
			cout << cost << endl;
		else
			cout << "-1" << endl;
		
		
	}
	return 0;
}
