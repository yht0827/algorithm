#include<cstdio>
#include<cstdlib>
#include<map>
#include<string>

using namespace std;

char str[22];
int N, M;// 1~ 100000
map<string, int> m1;
map<int, string> m2;

int main()
{	
  scanf("%d %d", &N,&M);
	
  for (int i = 1; i <= N; i++) //입력할 포켓몬 갯수
	{	
    scanf("%s",str);
		m1[str] = i;
		m2[i] = str;
    }	

	for (int i = 1; i <= M; i++) //맞춰야할 문제 수
	{	
    scanf("%s",str);
		if (str[0] >= '0' && str[0] <= '9')//숫자 -> 문자
		{ 
    printf("%s\n",m2[atoi(str)].c_str());
      }
		else {	
           printf("%d\n", m1[str]); 
        }//문자 -> 숫자
	 }
	return 0;
}
