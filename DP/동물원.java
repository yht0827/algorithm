import java.util.*;

public class 동물원 {
	
	public static void main(String[] args) {
		
		Scanner sc = new Scanner(System.in);
		int Test=sc.nextInt();

		long []left = new long[Test+1];
		long []right = new long[Test+1];
		long []no = new long[Test+1];
		
		left[1]=1;
		right[1]=1;
		no[1]=1;
		
		for(int i=2;i<=Test;i++)
		{
			left[i]=(right[i-1]+no[i-1])%9901;
			right[i]=(left[i-1]+no[i-1])%9901;
			no[i]=(left[i-1]+right[i-1]+no[i-1])%9901;
		}
		System.out.println((left[Test]+right[Test]+no[Test])%9901);
	}
}
