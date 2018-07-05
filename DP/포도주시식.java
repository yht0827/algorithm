import java.util.ArrayList;
import java.util.Scanner;

public class 포도주시식 {
	
 	static int[] dp = new int[10001];
 	static int[] wine = new int[10001];
 	
	public static void main(String[] args) {

		Scanner sc = new Scanner(System.in);
		
		int num = sc.nextInt();
				
		for(int i=1;i<=num;i++)
		{
			wine[i]=sc.nextInt();
		}

		dp[0]=0;
		dp[1]=wine[1];
		dp[2]=Math.max(wine[0]+wine[1],wine[1]+wine[2]);
		
		for(int i=3;i<=num;i++)
		{
			dp[i]= Math.max(dp[i-1],Math.max(wine[i]+wine[i-1]+dp[i-3],dp[i-2]+wine[i]));
		}
		System.out.println(dp[num]);
	}
}
