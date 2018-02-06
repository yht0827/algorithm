#include<cstdio>

long long pow(int A, int B, int C)
{	long long temp;

	if (B == 0)
	 {return 1;}

	temp = pow(A, B / 2, C);

	if (B % 2 == 0) { return ( temp%C * temp%C); }
	else {return ( (temp%C* temp%C)*A%C);}
}
int main()
{
	int  A, B, C,ans;
	scanf("%d %d %d", &A, &B, &C);
	ans = pow(A, B, C);
	printf("%d\n", ans);
	return 0;
}
