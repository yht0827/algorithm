import java.io.*;

public class 이친수 {

	public static void main(String[] args) throws IOException {
		// TODO Auto-generated method stub
		
		BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
		
		long dp[] = new long[91];
		
		String str = bf.readLine();
		int num = Integer.parseInt(str);
	
		if(num>0)
		{
			dp[1]=1;
			
			if(num>1)
			{
				dp[2]=1;
			}
			
			for(int i=3;i<=num;i++)
			{
				dp[i]=dp[i-1]+dp[i-2];
			}
		}	
		System.out.println(dp[num]);	
}
}
