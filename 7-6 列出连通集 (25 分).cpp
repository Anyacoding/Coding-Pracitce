#include <iostream>
#include<string.h>
const int Maxsize = 20;
using namespace std;
int N, E;
int List[Maxsize][Maxsize];
int visit[Maxsize];

void DFS(int i)
{
	int j;
	visit[i] = 1;
	cout << " " << i;
	for (j = 0; j < N; j++) {
		if (visit[j] == 0 && List[i][j] == 1)
			DFS(j);
	}

}

void BFS(int i)
{
	int numeber, j;
	int Queue[Maxsize];
	int head, tail;
	head = tail = 0;
	Queue[++tail] = i;
	while (head != tail) {
		i = Queue[++head];
		visit[i] = 1;
		cout << " " << i;
		for (j = 0; j < N; j++) {
			if (visit[j] == 0 && List[i][j] == 1) {
				Queue[++tail] = j;
				visit[j] = 1;
			}
		}
	}
	
}

int main()
{
	int i, j;
	int u, v;
	cin >> N >> E;
	for (i = 0; i < N; i++) 
		for (j = 0; j < N; j++) {
			List[i][j] = 0;
		}
	
	if (N) {
		for (i = 0; i < E; i++) {
			cin >> u >> v;
			List[u][v] = List[v][u] = 1;
		}
	

	memset(visit, 0, sizeof(visit));
	for (i = 0; i < N; i++) {
		if (visit[i] == 0) {
			cout << "{";
			DFS(i);
			cout << " }" << endl;
		}
	}

	memset(visit, 0, sizeof(visit));
	for (i = 0; i < N; i++) {
		if (visit[i] == 0) {
			cout << "{";
			BFS(i);
			cout << " }" << endl;
		}
	}

	}
	return 0;
}


//{ 0 1 4 2 7 }
//{ 3 5 }
//{ 6 }
//{ 0 1 2 7 4 }
//{ 3 5 }
//{ 6 }


//{ 0 1 4 2 7 }
//{ 1 0 2 4 7 }
//{ 2 0 1 4 7 }
//{ 3 5 }
//{ 4 1 0 2 7 }
//{ 5 3 }
//{ 6 }
//{ 7 0 1 4 2 }
//{ 0 1 2 7 4 }
//{ 1 0 4 2 7 }
//{ 2 0 4 1 7 }
//{ 3 5 }
//{ 4 1 2 0 7 }
//{ 5 3 }
//{ 6 }
//{ 7 0 1 2 4 }
