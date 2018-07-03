import java.io.*;

public class LCS {
	
	static int dp[][] = new int[1001][1001];
	
	public static void main(String[] agrs) throws IOException {
		
		BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));

		String str1 = bf.readLine();
		String str2 = bf.readLine();

		for(int i=1;i<=str1.length();i++)
		{
			for(int j=1;j<=str2.length();j++)
			{
				if(str1.charAt(i-1)==str2.charAt(j-1)) //문자 하나 비교
				{
					dp[i][j]=dp[i-1][j-1]+1;
				}
				else{	
					dp[i][j]= Math.max(dp[i-1][j],dp[i][j-1]);
				}
			}			
		}
			System.out.println(dp[str1.length()][str2.length()]);
	}
}
