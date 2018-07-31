import java.util.ArrayList;
import java.util.Scanner;

public class DFS {

	private static int N;
	private static int[][] arr;
	private static boolean[][] visited;
	private static int cnt=0;
	private static int max;
	private static int result;

	public static void main(String[] args) {

		Scanner sc = new Scanner(System.in);
		N = sc.nextInt();
		arr = new int[N][N];
		
		max = 0;
		result =0;

		for(int i=0;i<N;i++){
			for(int j=0;j<N;j++){
				arr[i][j]= sc.nextInt();
				max=Math.max(max,arr[i][j]);
			}
		}
		for(int n=1;n<=max;n++){
			visited = new boolean[N][N];
			cnt=0;
			for(int i=0;i<N;i++){
				for(int j=0;j<N;j++){
					if(arr[i][j]>=n && visited[i][j]==false){
						flood(i,j,n);
						cnt++;
					}
				}
			}
			result= Math.max(result,cnt);
		}

		System.out.println(result);
	}
	public static void flood(int i, int j,int n) {

		if(arr[i][j]>=n && visited[i][j]==false){
			visited[i][j]=true;
			if(i!=0){//x좌표가 0이아닐때
				flood(i-1,j,n);
			}
			if(j!=0){//y좌표가 0이아닐때
				flood(i,j-1,n);
			}
			if(i!=N-1){//x좌표가 N-1이아닐때
				flood(i+1,j,n);
			}
			if(j!=N-1){//y좌표가 N-1이아닐때
				flood(i,j+1,n);
			}
		}
	}
}
