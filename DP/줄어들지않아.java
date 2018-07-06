import java.util.*;

public class 줄어들지않아 {
	
	static long [][]dp = new long [65][10];

	public static void main(String[] args) {

		int Testcase;
		int jari;
		long sum1;
		long sum;
		
		Scanner sc = new Scanner(System.in);
		
		Testcase= sc.nextInt();
		
		for(int i=0;i<=9;i++)
		{
			dp[1][i]=1;
			if(i>=1)
			{
				dp[i][0]=1;
			}
			
		}
		for(int i=2;i<=64;i++)
		{
			for(int j=0;j<=9;j++)
			{
				sum1=0;
				for(int k=0;k<=j;k++)
				{
					sum1 +=dp[i-1][k];
				}
				dp[i][j]=sum1;
			}
		}	
	
		for(int i=1;i<=Testcase;i++)
		{
			sum=0;
			jari = sc.nextInt();
			for(int j=0;j<=9;j++){
				sum += dp[jari][j];
			}
			System.out.println(sum);
		}
}
}
