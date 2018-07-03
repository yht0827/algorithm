import java.io.*;
import java.util.*;

public class 일로만들기 {

		public static void main(String[] agrs) throws IOException{

			BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
			String a = bf.readLine();
			int num = Integer.parseInt(a);

			int dp[] = new int[num+1];
			Arrays.fill(dp,0);

			for(int i=2;i<=num;i++)
			{
				dp[i]=dp[i-1]+1;

				if(i%3==0)
				{
					dp[i] = Math.min(dp[i/3]+1, dp[i]);
				}
				if(i%2==0)
				{
					dp[i] = Math.min(dp[i/2]+1, dp[i]);
				}
			}

			System.out.println(dp[num]);

		}


	}

