#include<cstdio>
#include<algorithm>
#define MAX 100001
int arr[MAX], sum = 0;
using namespace std;

int solve(int s, int e)
{
	if (s == e) return arr[s];
	int mid = (s + e) / 2;

	sum = max(solve(s, mid), solve(mid + 1, e));

	int w = 1, h = arr[mid], l = mid, r = mid;

	while (r - l< e - s) {
		int p = l>s ? min(h, arr[l - 1]) : -1; // 왼쪽으로 확장했을 경우의 높이
		int q = r<e ? min(h, arr[r + 1]) : -1; // 오른쪽으로 확장했을 경우의 높이
		if (p >= q) {
			h = p;
			l--;
		}
		else {
			h = q;
			r++;
		}
		sum = max(sum, ++w*h);
	}
	return sum;
}
int main()
{
	int N;
	scanf("%d", &N);

	for (int i = 1; i <= N; i++)
		scanf("%d", &arr[i]);

	printf("%d\n", solve(1, N));

	return 0;
}
