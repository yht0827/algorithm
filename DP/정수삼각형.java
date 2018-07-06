import java.util.*;

public class 정수삼각형 {
	
	static int [][]dp = new int[501][501];

	public static void main(String[] args) {

		Scanner sc = new Scanner(System.in);
		
		int size= sc.nextInt();
		int max=0;
		
		for(int i=1;i<=size;i++)
		{
			for(int j=1;j<=i;j++)
			{
				dp[i][j]=sc.nextInt();
			}
		}
		//양 쪽 맨 끝 합
		for(int i=2;i<=size;i++)
		{
			dp[i][1]+=dp[i-1][1];
			dp[i][i]+=dp[i-1][i-1];
		}
		for(int i=3;i<=size;i++)
		{
			for(int j=2;j<i;j++)
			{
				dp[i][j]+=Math.max(dp[i-1][j-1],dp[i-1][j]);
			}
			
		}
		for(int i=1;i<=size;i++)
		{
			max= Math.max(dp[size][i],max);
		}
		System.out.println(max);
	}
}
