import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {//1992

	private static int N;
	private static int[][] arr;

	public static void main(String[] args) throws NumberFormatException, IOException {


		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

		N = Integer.parseInt(br.readLine());
		arr = new int[N][N];

		for(int i=0;i<N;i++){
			String readline = br.readLine();
			for(int j=0;j<N;j++){
				arr[i][j] = readline.charAt(j)-48;
			}
		}
		condiv(0,0,N);
		br.close();
	}
	public static void condiv(int start_x,int start_y,int size) {

		int first = arr[start_x][start_y];
		boolean flag =false;

		esc:  for(int i=start_x;i<start_x+size;i++){
			for(int j=start_y;j<start_y+size;j++){
				if(first!=arr[i][j]){
					flag = true;
					break esc;
				}
			}
		}
		if(flag){
			size/=2;
			System.out.print("(");
			condiv(start_x,start_y,size);//왼쪽 위 00~33
			condiv(start_x,start_y+size,size);//오른쪽 위 04~37
			condiv(start_x+size,start_y,size);//왼쪽 아래 40~73
			condiv(start_x+size,start_y+size,size);//오른쪽 아래 44~77
			System.out.print(")");
		}
		else{
			System.out.print(arr[start_x][start_y]);
		}
	}
}
