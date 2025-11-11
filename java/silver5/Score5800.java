package silver5;

import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.Collections;
import java.util.StringTokenizer;

public class Score5800 {

	public static void main(String[] args) throws IOException {
		// TODO Auto-generated method stub
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
			
		int tc = Integer.parseInt(br.readLine());
		
		StringBuilder sb = new StringBuilder();
		
		for (int i = 0; i < tc; i++) {
			StringTokenizer st = new StringTokenizer(br.readLine());
			int N = Integer.parseInt(st.nextToken());
			Integer[] arr = new Integer[N];
			
			for (int j = 0; j < N; j++) {
				arr[j] = Integer.parseInt(st.nextToken());
			}
			
			Arrays.sort(arr, Collections.reverseOrder());
			
			int max = arr[0];
			int min = arr[N - 1];
			int gap = Integer.MIN_VALUE;
			for (int j = 0; j < arr.length - 1; j++) {
				gap = Math.max(gap, Math.abs(arr[j] - arr[j+1]));
			}
			sb.append("Class ").append(i + 1).append('\n');
			sb.append("Max " + max + ", ").append("Min " + min + ", ").append("Largest gap " + gap + '\n');
		}
		System.out.println(sb);
	}

}
