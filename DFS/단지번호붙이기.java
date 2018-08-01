import java.util.ArrayList;
import java.util.Collections;
import java.util.Iterator;
import java.util.Scanner;

public class Danji {

	private static int N;
	private static int [][] arr;
	private static boolean [][] visited;
	private static int danzi;
	private static int cnt;
	private static ArrayList<Integer> list = new ArrayList<Integer>();
	private static String str;
	private static Iterator<Integer> itr;

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		N = sc.nextInt();
		arr = new int[N][N];
		visited = new boolean[N][N];

		for(int i=0;i<N;i++){
			str =sc.next();
			for(int j=0;j<N;j++){
				arr[i][j]=str.charAt(j)-48;
			}
		}
		for(int i=0;i<N;i++){
			for(int j=0;j<N;j++){
				if(arr[i][j]==1 && visited[i][j]==false){
					cnt=0;
					danzi++;
					flood(i,j);
					list.add(cnt);
				}
			}
		}
		Collections.sort(list);
		System.out.println(danzi);

		 itr = list.iterator();
		while(itr.hasNext()){
			System.out.println(itr.next());
		}
	}
	
	public static void flood(int i, int j) {
		if(arr[i][j]==1 && visited[i][j]==false){
			cnt++;
			visited[i][j]=true;
			if(i!=0){
				flood(i-1,j);
			}
			if(j!=0){
				flood(i,j-1);
			}
			if(i!=N-1){
				flood(i+1,j);
			}
			if(j!=N-1){
				flood(i,j+1);
			}
		}
	}
}
