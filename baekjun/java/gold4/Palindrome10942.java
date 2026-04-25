package gold4;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Palindrome10942 {
	
	

	public static void main(String[] args) throws IOException {
		
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		int N = Integer.parseInt(br.readLine());
		
		int[] arr = new int[N + 1];
		
		java.util.StringTokenizer st = new StringTokenizer(br.readLine());
		for (int i = 1; i <= N; i++) {
			arr[i] = Integer.parseInt(st.nextToken());
		}
		
		int[] oddDP = new int[N + 1];
		int[] evenDP = new int[N + 1];
		
		for (int i = 0; i <= N; i++) {
			int radius = 0;
			// 홀수 길이 계산
			while(i - radius >= 1 && i + radius <= N && arr[i - radius] == arr[i + radius]) {
				radius++;
			}
			
			oddDP[i] = radius - 1; // 마지막에 조건이 깨지는 조건이 1 추가된 거임
			
			radius = 0;
			// 짝수 길이 계산
			while(i - radius >= 1 && i + 1 + radius <= N && arr[i - radius] == arr[i + 1 + radius]) {
				radius++;
			}
			evenDP[i] = radius - 1;
		}
		
		int M = Integer.parseInt(br.readLine());
		StringBuilder sb = new StringBuilder();
		
		for (int i = 0; i < M; i++) {
			st = new StringTokenizer(br.readLine());
			int start = Integer.parseInt(st.nextToken());
			int end = Integer.parseInt(st.nextToken());
			
			int length = end - start + 1;
			int center = (start + end) / 2;
			
			if (length % 2 == 1) {
				int curRadius = (length - 1) / 2;
				if (curRadius <= oddDP[center]) {
					sb.append("1\n");
				} else {
					sb.append("0\n");
				}
			} else {
				int curRadius = length / 2 - 1;
				if (curRadius <= evenDP[center]) {
					sb.append("1\n");
				} else {
					sb.append("0\n");
				}
			}
		}
		
		System.out.println(sb.toString());
	}

}
