#include<cstdio>
#include<algorithm>
using namespace std;
int N, C;
int arr[200001];

void solve(int C)
{
	int left=arr[1], right=arr[N],wifi=0;

	while (left <= right)
	{
		int mid = (left + right) / 2;
		int count = 1;//기본 arr[1]번에는 설치를 전제조건
		int start = arr[1];
		
		for (int i = 2; i <= N; i++)
		{
			if (arr[i] - start >= mid)
			{
				start = arr[i];//거리를 만족하면 위치 값 바꿔줌 
				count++;
			}
		}
		if(count<C) //조건보다 설치 개수가 더 적을때(R의 거리를 줄여서 mid값을 줄여줌) 
		{ right = mid - 1; }
		else { //조건보다 설치 갯수가 더많을 때(L을 오른쪽으로 이동시켜서 mid값을 늘려줌)
			if(mid>wifi)wifi = mid;

			left = mid + 1;
		}
	}
	printf("%d\n", wifi);
}

int main()
{
	scanf("%d %d", &N, &C);

	for (int i = 1; i <= N; i++)
		scanf("%d", &arr[i]);

	sort(arr + 1, arr + N + 1);
	solve(C);

	return 0;
}
