#include<iostream>
#include<algorithm>
#include<cstdio>
#define MAX 100

using namespace std;

int main()
{
	int N, happy[21], joy[21], BAG[MAX];
	fill(BAG, BAG + 100, 0);

	cin >> N;//�λ�

	for (int i = 1; i <= N; i++)
		cin >> happy[i];//ü��

	for (int i = 1; i <= N; i++)
		cin >> joy[i];//���	

	for (int i = 1; i <= N; i++)
		for (int j =99; j>=happy[i]; j--)
		{
				BAG[j] = max(BAG[j], BAG[j - happy[i]] + joy[i]);
		}

	printf("%d\n", BAG[99]);

	return 0;
}