import java.util.Scanner;
import java.util.Stack;

public class Main {

	static Stack<Integer> s = new Stack<Integer>();

	public static void main(String[] args) {

		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int a[] = new int[n+2];

		for(int i=1;i<=n;i++){ 
			a[i] = sc.nextInt();
		}
		int ans = 0;
		s.push(0);
		for(int i=1;i<=n+1;i++){
			while(!s.isEmpty() && a[i]<a[s.peek()]){
				int height=a[s.peek()];
				s.pop();
				int width = i-s.peek()-1;

				ans = max(ans, width*height);
			}
			s.push(i);
		}
		System.out.println(ans);
	}
	public static int max(int a,int b){
		return a>b?a:b;
	}
}
