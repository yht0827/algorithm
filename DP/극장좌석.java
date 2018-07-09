import java.util.Scanner;

public class 극장좌석 {

	public static void main(String[] args) {

		Scanner sc = new Scanner(System.in);
		int T = sc.nextInt();//전체 좌석의 개수
		int M = sc.nextInt();//고정석 개수
		int []fix = new int[M+1];
		int hap=0;
		
		if(M==0)//고정석 0개
		{
			hap+= func(T+1,0);
		}
		else{//고정석 1개 이상
		for(int i=0;i<=M;i++)
		{
			if(i==0)//~첫번째 고정석까지의 좌석 개수
			{
				fix[i]= sc.nextInt();
				hap+= func(fix[i],0);
			}
			else if(i<M){// 고정석 간의 좌석 개수
				fix[i]= sc.nextInt();
				hap*= func(fix[i],fix[i-1]);
			}
			else{//마지막 고정석 ~ 마지막 좌석까지 좌석 개수
				hap*= func(T+1,fix[i-1]);
			}
		}
		}
		System.out.println(hap);
	}
	public static int func(int a,int b)
	{
		int N= a-b-1;
		int []dp = new int[41];
		dp[0]=1;
		dp[1]=1;
		
		for(int i=2;i<=N;i++)
		{
			dp[i]= dp[i-1]+dp[i-2];
		}
		return dp[N];		
	}
}
