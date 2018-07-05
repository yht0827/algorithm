import java.util.*;

public class Main {

	static int [] dp = new int[301];
	static int [] stair = new int[301];

	public static void main(String[] args) {
		
		Scanner sc = new Scanner(System.in);

		int n = sc.nextInt(); //계단 횟수입력

		for(int i=1;i<=n;i++)
		{
			stair[i] = sc.nextInt(); //계단 점수입력
		}

		dp[0] = 0;
		dp[1] = stair[1];
		dp[2] = Math.max(stair[1]+stair[2],stair[0]+stair[2]);
		
		for(int i=3;i<=n;i++)
		{
			dp[i]= Math.max(stair[i]+stair[i-1]+dp[i-3], dp[i-2]+stair[i]);			
		}
		
		System.out.println(dp[n]);
	}
}
