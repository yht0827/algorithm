import java.util.Scanner;

public class Main {

	private static int N;
	private static int sum;
	private static boolean flag;

	public static void main(String[] args) {

		Scanner sc = new Scanner(System.in);
		N = sc.nextInt();
		for(int i=1;i<N;i++){
			sum=0;
			if(N==brute(i)){
				System.out.println(i);
				flag=true;
				break;
			}
		}
		if(!flag){
			System.out.println(0);
		}
	}
	public static int brute(int num){
		sum=num;
		do{
			sum+=num%10;
			num=num/10;
		}while(num>0);

		return sum;
	}
}
