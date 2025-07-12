package silver2;

import java.util.Scanner;
import java.util.Queue;
import java.util.LinkedList;

public class Cabbage1012 {
	public static void main(String args[]) {
		Scanner sc = new Scanner(System.in);
		
		int tc = sc.nextInt();   // 테스트 케이스의 수
		
		for (int testCase = 0; testCase < tc; testCase++) {
			int M;    // 배추밭의 가로
			int N;    // 배추밭의 세로
			int K;    // 배추의 개수
			
			int cnt = 0;
			
			M = sc.nextInt();
			N = sc.nextInt();
			K = sc.nextInt();
			
			
			
			// 두 배열 초기화
			int[][] array1 = new int[N][M];   // 받는 배열
			boolean[][] array2 = new boolean[N][M];   //  방문 확인 배열
			
			// 두 배열 채우기
			for (int i = 0; i < N; i++) {
				for (int j = 0; j < M; j++) {
					array1[i][j] = 0;
					array2[i][j] = false;
				}
			}
			
			// 배추 위치 특정
			for (int num = 0; num < K; num++) {
				int x = sc.nextInt();
				int y = sc.nextInt();
				
				array1[y][x] = 1;
			}
			
			// 배열을 돌며 BFS 실행
			for (int i = 0; i < N; i++) {
				for (int j = 0; j < M; j++) {
					if (array1[i][j] == 1 && !array2[i][j]) {
						bfs(array1, array2, i, j, N, M); // 여기에서 BFS 실행
						cnt++;
					}
				}
			}
			System.out.println(cnt);
		}
		
		sc.close();
	}
	
	static void bfs(int[][] map, boolean[][] visited, int x, int y, int N, int M) {
		int[] dx = {-1, 0, 1, 0};
		int[] dy = {0, -1, 0, 1};
		
		Queue<int[]> queue = new LinkedList<>();
		queue.offer(new int[] {x, y});
		visited[x][y] = true;
		
		while(!queue.isEmpty()) {
			int[] cur = queue.poll();
			int cx = cur[0];
			int cy = cur[1];
			
			for (int dir = 0; dir < 4; dir++) {
				int nx = cx + dx[dir];
				int ny = cy + dy[dir];
				
				if (nx >= 0 && nx < N && ny >= 0 && ny < M) {
					if (map[nx][ny] == 1 && !visited[nx][ny]) {
						visited[nx][ny] = true;
						queue.offer(new int[] {nx, ny});
					}
				}
			}
		}
	}
}
