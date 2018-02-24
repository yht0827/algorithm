#include<cstdio>
#include<algorithm>
#include<queue>
#include<iostream>
#include<vector>

using namespace std;

int N,M;
int a, b;
int x, y;
vector<vector<int> > arr;

void bfs(int a,int b)
{
	vector<bool> visited(N+1, false); // 방문 여부를 저장하는 배열
	queue<int> Q;
	Q.push(a);
	visited[a] = true;
	// 탐색 시작
	int level = 0;
	while (!Q.empty()) {
		int qSize = Q.size();
		for (int i = 0; i<qSize; i++) {
			int curr = Q.front();
			Q.pop();

			if (b == curr)
			{	printf("%d\n", level);
				return;
			}

			for (int next: arr[curr]) {
				if (!visited[next]) {
					visited[next] = true;
					Q.push(next);
				}
			}
		}
		level++;
	}
	//탐색을 못하였을 때
	printf("-1\n");
	return;
};

int main()
{
	scanf("%d", &N);
	arr.resize(N+1);
	
	scanf("%d %d", &a, &b);//촌 수를 구해야할 번호

	scanf("%d", &M);//부모 자식 관계 갯수

	for (int i = 1; i <= M; i++)
	{
		scanf("%d %d", &x, &y);//x가 부모 y가 자식
		arr[x].push_back(y);
		arr[y].push_back(x);
	}

	bfs(a,b);	

	return 0;
}
