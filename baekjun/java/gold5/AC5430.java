package gold5;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;
import java.util.ArrayDeque;

public class AC5430 {
	public static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	public static StringBuilder sb = new StringBuilder();
	
	public static void main(String args[]) throws IOException {

		
		int tc = Integer.parseInt(br.readLine());
		
		ArrayDeque<Integer> deque;
		StringTokenizer st;
		
		for (int i = 0; i < tc; i++) {
			String operation = br.readLine();
			int length = Integer.parseInt(br.readLine());
			
			st = new StringTokenizer(br.readLine(), "[],");
			
			deque = new ArrayDeque<Integer>();
			
			for(int j=0; j<length; j++) {
				deque.add(Integer.parseInt(st.nextToken()));
			}
			
			AC(operation, deque);
		}
		System.out.println(sb);
	}
	
	public static void AC(String command, ArrayDeque<Integer> deque) {
		boolean isRight = true;
		
		// 여기에서 for-each 구문을 써야함
		for(char cmd : command.toCharArray()) {
			if(cmd == 'R') {
				isRight = !isRight;  // 방향을 바꿔줌
				continue;
			}
			
			else if (cmd == 'D' && isRight) {
				if(deque.pollFirst() == null) {
					sb.append("error\n");
					return;
				}
			}
			else {
				if(deque.pollLast() == null) {
					sb.append("error\n");
					return;
				}
			}
			
		}
		
		makePrintString(deque, isRight);
	}
	
	public static void makePrintString(ArrayDeque<Integer> deque, boolean isRight) {
		sb.append('[');
		
		if(deque.size() > 0) { // 출력할 값이 남아 있으면
			// 정방향 
			if(isRight) {
				sb.append(deque.pollFirst()); // 맨 앞의 원소를 넘겨줌
				
				// 그 다음 원소부터 반점을 먼저 넘겨준 후 덱의 원소를 하나씩 뽑아 넘김
				while(!deque.isEmpty()) {
					sb.append(',').append(deque.pollFirst());
				}
			}
			// 역방향
			else {
				sb.append(deque.pollLast());   // 맨 뒤 원소를 넘겨줌
				
				while(!deque.isEmpty()) {
					sb.append(',').append(deque.pollLast());
				}
			}
		}
		
		sb.append(']').append('\n'); // 닫는 대괄호
	}
	
	
}
