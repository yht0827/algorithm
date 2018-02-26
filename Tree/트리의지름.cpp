#include<cstdio>
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
vector<vector<pair<int,int>>> arr; // arr[1][4,100] => 1번과 4번 노드 사이의 가중치 100 표현
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
			for (auto next : arr[curr]) {
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
