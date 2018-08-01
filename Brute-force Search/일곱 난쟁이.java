import java.util.ArrayList;
import java.util.Collections;
import java.util.Scanner;

public class Main {

	private static int [] arr = new int[9];
	private static int sum;
	private static ArrayList<Integer> list = new ArrayList<Integer>();

	public static void main(String[] args) {

		Scanner sc = new Scanner(System.in);
		int num;
		for(int i=0;i<9;i++){
			num=sc.nextInt();
			arr[i] = num;
		}
		esc: for(int i=0;i<9;i++){
			for(int j=i+1;j<9;j++){
				list.clear();
				sum=0;
				bruteforce(i,j);
				if(sum==100)
				{
					Collections.sort(list);
					break esc;
				}
			}
		}
		for(int a:list){
			System.out.println(a);
		}
	}
	public static void bruteforce(int a, int b) {
		for(int i=0;i<9;i++){
			if(i!=a && i!=b){
				sum+=arr[i];
				list.add(arr[i]);
			}
		}
	}
}	
