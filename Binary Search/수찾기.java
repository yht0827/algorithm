import java.util.Arrays;
import java.util.Scanner;

public class Main {//1920번

	private static int []arr;
	private static int []arr2;

	public static void main(String[] args) {

		Scanner sc = new Scanner(System.in);

		int N,M;
		N= sc.nextInt();
		arr = new int[N];
		for(int i=0;i<arr.length;i++){
			arr[i]= sc.nextInt();
		}
		Arrays.sort(arr);

		M = sc.nextInt();
		arr2 = new int[M];
		int result;
		
		for(int i=0;i<arr2.length;i++){
			arr2[i]= sc.nextInt();
			
		result=Arrays.binarySearch(arr,arr2[i]);
		if(result<0){
			
			System.out.println(0);
		}else{
			System.out.println(1);
		}
		}
	}
}
