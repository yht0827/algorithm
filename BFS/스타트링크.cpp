#include<cstdio>
#include<queue>
#include<vector>
#include<algorithm>

using namespace std;
int F, S, G, U, D;

void startlink(int F,int S,int G,int U,int D)
{
	vector<bool> visited(F + 1, false); // 방문 여부를 저장하는 배열
	queue<int> Q;
	Q.push(S);
	visited[S] = true;
	// 탐색 시작
	int level = 0;
	while (!Q.empty()) {
		int qSize = Q.size();
		for (int i = 0; i < qSize; i++) {
			int curr = Q.front();
			Q.pop();

			if (G == curr)
			{
				printf("%d\n", level);
				return;
			}

			if (curr + U <= F && !visited[curr + U])//위로올라가는 경우
			{
				visited[curr + U] = true;
				Q.push(curr + U);
			}
			if (curr - D >0 && !visited[curr - D])//아래로 내려가는 경우
			{
					visited[curr - D] = true;
					Q.push(curr - D);
			}
		}
		level++;
	}
	printf("use the stairs\n");//못 찾을 경우
};

int main()
{

	scanf("%d %d %d %d %d", &F, &S, &G, &U, &D);

	startlink(F,S,G,U,D);

	return 0;
}
