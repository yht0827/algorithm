import java.io.*;
import java.util.*;

public class 암호코드 {

	public static void main(String[] args) throws IOException {

		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st  = new StringTokenizer(br.readLine());
		String str = st.nextToken();
		int len = str.length(); 
		int []arr = new int[len+1];
		int []dp = new int[len+1];
		dp[0]=1;
		dp[1]=1;

		for(int i=1;i<=len;i++){
			arr[i]= str.charAt(i-1)-48;
		}
		if(arr[1] == 0){ //맨처음이 0일경우
			dp[1]=0;
		}
		else{
			for(int i=2;i<=len;i++){
				if(arr[i]==0 && arr[i-1]==0)// 숫자가 중간에 00일경우 -> 0
				{
					break;
				}
				if(arr[i-1]== 2 || arr[i-1]== 1){//1,2
					if(arr[i-1]==2 && arr[i]>6){//27~29
						dp[i]=dp[i-1];
					}
					else if(arr[i]==0){
						if(arr[i-2]<=2 && arr[i-1]>=1){//110같은 특수 케이스
							dp[i]=dp[i-2];
						}
						else{
							dp[i]=dp[i-1];
						}
					} 
					else{
						dp[i]=(dp[i-1]+dp[i-2])%1000000;//10~26
					}
				}
				else{
					dp[i]=dp[i-1];
				}
			}
		}
		System.out.println(dp[len]);
	}
}
