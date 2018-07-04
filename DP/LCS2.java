import java.io.*;
import java.util.Stack;

public class LCS2 {

	static int dp[][] = new int[1001][1001];

	public static void main(String[] args) throws IOException {
		// TODO Auto-generated method stub

		Stack<Character> stack = new Stack<Character>();
		BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));

		String str1 = bf.readLine();
		String str2 = bf.readLine();
		int a =str1.length();
		int b =str2.length();

		for(int i=1;i<=a;i++)
		{
			for(int j=1;j<=b;j++)
			{
				if(str1.charAt(i-1)==str2.charAt(j-1))
				{
					dp[i][j]=dp[i-1][j-1]+1;
				}
				else{	
					dp[i][j]= Math.max(dp[i-1][j],dp[i][j-1]);
				}
			}			
		}
		System.out.println(dp[a][b]);
		
		while(dp[a][b] !=0)
		{
			if (dp[a][b] == dp[a][b - 1])
				{
				b--;
				}
			else if (dp[a - 1][b] == dp[a][b])
				{
				a--;
				}
			else{
				stack.push(str2.charAt(b-1));
				a--;
				b--;
			}
		}
			while(!stack.isEmpty())
			{
				System.out.print(stack.pop());
			}
	}
}
