import java.util.Scanner;

public class DFS {

	private static  int T;
	private static int M; 
	private static int N; 
	private static int K; 
	private static int[][] arr;
	private static int x;
	private static int y;
	private static int cnt;
	private static boolean[][] visited;

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);		
		T = sc.nextInt();//테스트 케이스
		for(int i=0;i<T;i++){
			M=sc.nextInt();//가로
			N=sc.nextInt();//세로
			K=sc.nextInt();//배추개수
			cnt=0;
			visited = new boolean[M][N];
			arr = new int[M][N];
			for(int j=0;j<K;j++){
				x= sc.nextInt(); //x좌표
				y= sc.nextInt(); //y좌표
				arr[x][y]=1;
			}
			
			for(int k=0;k<M;k++){
				for(int l=0;l<N;l++){
					if(arr[k][l]==1 && visited[k][l]==false){
						cnt++;
						flood(k,l);
					}
				}
			}
			System.out.println(cnt);
		}
	}
	public static void flood(int i,int j){
		if(arr[i][j]==1 && visited[i][j]==false){
			visited[i][j]=true;
			if(i!=0){//x좌표가 0이아닐때
				flood(i-1,j);
			}
			if(j!=0){//y좌표가 0이아닐때
				flood(i,j-1);
			}
			if(i!=M-1){//x좌표가 M-1이아닐때
				flood(i+1,j);
			}
			if(j!=N-1){//y좌표가 N-1이아닐때
				flood(i,j+1);
			}
		}
	}
}
