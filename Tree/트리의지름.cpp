/////////////////////////BFS로 해결/////////////////////
include<cstdio>
#include<iostream>
#include<vector>
#include<queue>
#include<cstring>

using namespace std;
int N;
int visited[10001];//방문 확인
int sum[10001];//가중치 누적 합
int a, b;// 2개의 노드 입력
int temp;//가중치 입력
vector<vector<pair<int,int>>> arr; // arr[1][{4,100}] => 1번과 4번 노드 사이의 가중치 100 표현
queue<int> q;// 큐

int BFS(int a)
{
	q.push(a);
	visited[a] = 1;
	int max = 0;
	int dis;

	while (!q.empty())
	{
		int qSize = q.size();
		for (int i = 0; i < qSize; i++) {
			int curr = q.front();
			q.pop();
			for (auto next : arr[curr]) {		//auto사용하면 타입을 알아서 설정해줌 
								//next -> next.first , next.second
				if (!visited[next.first]) {
					visited[next.first] = 1;
					q.push(next.first);
					sum[next.first] = sum[curr] + next.second;
				}
					
			}
		}
	}
	for (int i = 1; i <= N; i++)
	{
		if (sum[i]>max)
		{
			max = sum[i];
			dis = i;
		}
	}
	return dis;//가장 큰 배열의 번호 반환
};

int main()
{
	scanf("%d", &N);
	arr.resize(N + 1);
	int big;

	if (N == 1)
	{
		printf("0\n");
		
	}
	else {
		for (int i = 1; i < N; i++)
		{
			scanf("%d %d %d", &a, &b, &temp);
			arr[a].push_back({ b, temp });
			arr[b].push_back({ a,temp });
		}

		memset(visited, 0, sizeof(visited));
		memset(sum, 0, sizeof(sum));
		big = BFS(1);//1에서 가장 멀리 떨어진 노드 찾기

		memset(visited, 0, sizeof(visited));
		memset(sum, 0, sizeof(sum));
		big = BFS(big);//가장 멀리 떨어진 두개 노드 간에 거리

		printf("%d\n", sum[big]);
	}
	
	return 0;
}

///////////////////////DFS로 해결////////////////
/*
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
#define INF 987654321
using namespace std;
int n, x, y, z, u, v, r;
vector<int> dist;
vector<vector<pair<int, int>>> vt;
void dfs(int here, int dis) {
    dist[here] = dis;
    if (dist[here] > r) {
        r = dist[here];
        u = here;
    }
    for (auto next : vt[here]) {
        if (dist[next.first] != INF)continue;
        dfs(next.first, dis + next.second);
    }
}
int main() {
    scanf("%d", &n);
    vt.resize(n + 1);
    for (int i = 0; i < n - 1; i++) {
        scanf("%d%d%d", &x, &y, &z);
        vt[x].push_back({ y,z });
        vt[y].push_back({ x,z });
    }
    dist.assign(n + 1, INF);
    dfs(1, 0);
    v = u, r = 0;
    dist.assign(n + 1, INF);
    dfs(u, 0);    //u와 v에 트리의 지름의 단말노드가 담기게 됨
    printf("%d\n", r);
    return 0;
}
*/



