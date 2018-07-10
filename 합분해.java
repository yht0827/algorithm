import java.io.*;
import java.util.*;

public class 합분해 {

	public static void main(String[] args) throws IOException {

		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());

		int N = Integer.parseInt(st.nextToken());
		int K = Integer.parseInt(st.nextToken());
		int [][]dp = new int[K+1][N+1];

		for(int i=0;i<=N;i++){
			dp[1][i]=1;
		}
		for(int i=2;i<=K;i++){
			for(int j=0;j<=N;j++){
				for(int n=0;n<=j;n++){
					dp[i][j]=(dp[i][j]+dp[i-1][j-n])%1000000000;
				}
			}
		}
		System.out.println(dp[K][N]);
	}
}
