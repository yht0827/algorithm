#include<cstdio>

int arr[1000001];
int N, M;

int tree()
{
	int lo=1, hi= 1000000000;
	
	while (lo+1<hi)
	{
		int mid = (lo + hi) / 2;

		long long sum = 0;

		for(int i=1;i<=N;i++)
			if (arr[i] > mid) sum += arr[i] - mid;

		if (sum >= M) lo = mid;
		else hi = mid;

	}

	return lo;

}
int main()
{
	scanf("%d %d", &N, &M);

	for (int i = 1; i <= N; i++)
		scanf("%d", &arr[i]);

	printf("%d\n",tree());

	return 0;
}
