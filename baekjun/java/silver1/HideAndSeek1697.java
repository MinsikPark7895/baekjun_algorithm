package silver1;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;

public class HideAndSeek1697 {
	static int N;   // 시작점
	static int K;   // 끝점
	
	static int visited[] = new int[100001];  // BFS를 위한 visited 
	
	public static void main(String args[]) throws IOException{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		String input = br.readLine();
		String[] inputs = input.split(" ");
		
		N = Integer.valueOf(inputs[0]);
		K = Integer.valueOf(inputs[1]);
		
		int result = bfs(N);
		System.out.println(result);
	}
	
	private static int bfs(int node) {
		Queue<Integer> queue = new LinkedList<Integer>();  // BFS에 사용될 큐
		queue.add(node);
		int index = node;   // 최초 위치
		int n = 0;          // 움직임 수
		visited[index] = 1;    //  최초의 위치에 방문 설정
		while(queue.isEmpty() == false) {
			n = queue.remove();
			
			if(n==K) {
				return visited[n] - 1;
			}
			if(n-1 >= 0 && visited[n-1] == 0) {
				visited[n-1] = visited[n] + 1; // 방문한적 없고 범위 내에 있으면 해당 위치에 움직임 수 표시
				queue.add(n-1);
			}
			if(n+1 <= 100000 && visited[n+1] == 0) {
				visited[n+1] = visited[n]+1;
				queue.add(n+1);
			}
			if(2*n <= 100000 && visited[2*n] == 0) {
				visited[2*n] = visited[n] + 1;
				queue.add(2*n);
			}
		}
		return -1;
	}
}
