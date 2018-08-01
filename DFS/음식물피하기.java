import java.util.Scanner;

public class Main {

	private static int N;
	private static int M;
	private static int K;
	private static int [][] arr;
	private static boolean[][] visited;
	private static int cnt;
	private static int max=0;

	public static void main(String[] args) {

		Scanner sc = new Scanner(System.in);
		N = sc.nextInt();
		M = sc.nextInt();
		K = sc.nextInt();
		arr = new int[N+1][M+1];
		visited = new boolean[N+1][M+1];
		
		for(int i=0;i<K;i++){
			int a = sc.nextInt();
			int b = sc.nextInt();
			arr[a][b]=1;
		}
	for(int i=1;i<=N;i++){
			for(int j=1;j<=M;j++){
						if(arr[i][j]==1 && visited[i][j]==false){
							cnt=0;
							flood(i,j);
						}
						max = cnt>=max?cnt:max;
					}
			}
		System.out.println(max);
		}
	private static void flood(int i, int j) {
		if(arr[i][j]==1 && visited[i][j]==false){
			cnt++;
			visited[i][j]=true;
			if(i!=1){
				flood(i-1,j);
			}
			if(j!=1){
				flood(i,j-1);
			}
			if(i!=N){
				flood(i+1,j);
			}
			if(j!=M){
				flood(i,j+1);
			}
	}
	}
}	
