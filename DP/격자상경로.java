import java.io.*;
import java.util.*;

public class 격자상경로 {

	public static void main(String[] args) throws IOException {

		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());

		int N = Integer.parseInt(st.nextToken());
		int M = Integer.parseInt(st.nextToken());
		int K = Integer.parseInt(st.nextToken());
		int cnt = 0;
		int x = 0;
		int y = 0;
		int [][]dp = new int[N+1][M+1];
		dp[1][1]=1;

		if(K>0){
			esc:for(int i=1;i<=N;i++){
				for(int j=1;j<=M;j++){
					cnt++;
					if(cnt == K)
					{
						x=i;
						y=j;
						break esc;
					}
				}
			}
		}
		else{
			x=1;
			y=1;
		}
		for(int i=1;i<=x;i++){
			for(int j=1;j<=y;j++){
				if(i==1 && j==1){
					continue;
				}
				dp[i][j] = dp[i-1][j]+dp[i][j-1];
			}
		}
		int num= dp[x][y];
		dp[x][y]=1;

		for(int i=x;i<=N;i++){
			for(int j=y;j<=M;j++){
				if(i==x && j==y){
					continue;
				}
				dp[i][j]=dp[i-1][j]+dp[i][j-1];
			}
		}
		num *= dp[N][M];
		System.out.println(num);
	}
}
