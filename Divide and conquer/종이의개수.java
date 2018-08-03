import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {///1780번 문제

	private static int N;
	private static int arr[][]; 
	static int r[] = new int[3];

	public static void main(String[] args) throws NumberFormatException, IOException {

		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		N = Integer.parseInt(br.readLine());
		arr = new int[N][N];

		for(int i=0;i<N;i++){
			StringTokenizer st = new StringTokenizer(br.readLine());
			for(int j=0;j<N;j++)
				arr[i][j] = Integer.parseInt(st.nextToken());
		}

		divcon(0 ,0, N);

		for(int i=0; i<3; ++i)
			System.out.println(r[i]);

		br.close();
	}

	private static void divcon(int start_x, int start_y,int size) {

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
			size /= 3; //분할

			divcon(start_x,start_y,size); //상단왼쪽
			divcon(start_x+size,start_y,size);//중앙 왼쪽
			divcon(start_x+2*size,start_y,size);//하단 왼쪽

			divcon(start_x,start_y+size,size);//상단 중앙
			divcon(start_x+size,start_y+size,size);//중앙
			divcon(start_x+2*size,start_y+2*size,size);//하단 오른쪽

			divcon(start_x,start_y+2*size,size);//상단 오른쪽
			divcon(start_x+size,start_y+2*size,size);//중앙 오른쪽
			divcon(start_x+2*size,start_y+size,size);//하단 중앙	
		}
		else{
			r[first+1]++;
		}
	}
}
