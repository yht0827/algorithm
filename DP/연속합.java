import java.util.Scanner;

public class 연속합 {

	static long [] dp = new long [100001];

	public static void main(String[] args) {

		Scanner sc = new Scanner(System.in); 

		int num = sc.nextInt();

		for(int i=1;i<=num;i++)
		{
			dp[i]=sc.nextInt();
		}
		
		long max= dp[1];
		for(int i=1;i<=num;i++){
			long sum=0;
			for(int j=i;j<=num;j++){
				sum+=dp[j];
				max= Math.max(max,sum);
			}
		}
			System.out.println(max);
	}
}
