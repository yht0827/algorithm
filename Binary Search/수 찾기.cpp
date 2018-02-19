#include<cstdio>
#include<algorithm>

int arr[100001],N,M,num;
using namespace std;

int solve(int a)
{
	int lo = 1, hi = N;
	
	while (hi-lo>1)
	{
		int mid = (lo + hi)/2;
		
		if(a>arr[mid])
		{
			lo=mid;
		}
		else if(a<arr[mid]){
			hi = mid;
		}
		else if(a==arr[mid]){// mid = a
			return 1;
		}

	}

	return 0;
}

int main()
{
	scanf("%d", &N);

	for (int i = 1; i <=N; i++)
		scanf("%d", &arr[i]);

	sort(arr+1,arr+(N+1));

	scanf("%d", &M);

	for (int i = 1; i <= M; i++)
	{
		scanf("%d",&num);
		printf("%d\n",solve(num));
	}

	return 0;
}


///////////////////////////////////////////////////
/* binary_search STL을 이용해서 구현

#include<cstdio>
#include<algorithm>

int arr[100001],N,M,num;
using namespace std;

int main()
{
	bool ans;

	scanf("%d", &N);

	for (int i = 1; i <=N; i++)
		scanf("%d", &arr[i]);

	sort(arr+1,arr+(N+1));

	scanf("%d", &M);

	for (int i = 1; i <= M; i++)
	{
		scanf("%d",&num);
		
		ans = binary_search(arr+1, arr+(N+1), num);
	
		if (ans == true)
			printf("1\n");
		else
			printf("0\n");
		
	}

	return 0;
}

*/
///////////////////////////////////////////////

