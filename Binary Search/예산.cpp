#include<cstdio>
#include<algorithm>
using namespace std;

int arr[10001];
int N, M;

void buget(int a)
{
	int lo = 1,hi = arr[N]+1,sum,mid;

	while (lo + 1 < hi)
	{
		mid = (lo + hi)/2;
		sum = 0;
		for (int i =1; i<=N; i++)
		{
			if (arr[i] < mid){
				sum += arr[i];
			}
			else {
				sum += mid;
			}
		}
		if (sum < a){		
				lo = mid;
		}
		else if(sum >a){
				hi = mid;
		}
		else {
			printf("%d\n", mid); ////딱 숫자가 떨어지는 경우에만 수행
 				break;
		}
		
		/* 		while문 계속 실행하다가 맨 마지막에 실행		   */
		if (lo + 1 == hi)
		{	
				printf("%d\n",lo);
				break;
		}
	}
}
int main()
{
	scanf("%d", &N);

	for (int i = 1; i <= N; i++)
		scanf("%d",&arr[i]);

	sort(arr + 1, arr + N + 1);

	scanf("%d", &M);//총 예산
	buget(M);

	return 0;
}
