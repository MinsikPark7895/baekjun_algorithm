package silver4;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;

public class ATM11399 {
	public static void main(String args[]) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		int N = Integer.parseInt(br.readLine());
		String[] arr = br.readLine().split(" ");
		
		int[] time = new int[N];
		for(int i = 0; i<N; i++) {
			time[i] = Integer.parseInt(arr[i]);
		}
		
		Arrays.sort(time);
		
		int result = 0;
		int sum = 0;
		
		for(int i = 0; i < N; i++) {
			sum += time[i];
			result += sum;
		}
		
		System.out.println(result);
	}
}
