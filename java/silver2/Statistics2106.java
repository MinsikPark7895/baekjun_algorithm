package silver2;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;

public class Statistics2106 {

	public static void main(String args[]) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		int N = Integer.parseInt(br.readLine());
		int[] count = new int[8001];
		
		int sum = 0;
		int max = Integer.MIN_VALUE;
		int min = Integer.MAX_VALUE;
		
		for(int i = 0; i < N; i++) {
			int num = Integer.parseInt(br.readLine());
			sum += num;
			count[num + 4000]++;
			
			if(num > max) {
				max = num;
			}
			if(num < min) {
				min = num;
			}
		}
		
		System.out.println(Math.round((double) sum / N));
		
		int midCount = 0;
		int midNum = 0;
		for(int i = min + 4000; i <= max + 4000; i++) {
			midCount += count[i];
			if(midCount >= (N + 1) / 2) {
				midNum = i - 4000;
				break;
			}
		}
		
		System.out.println(midNum);
		
		int modeMax = 0;
		for(int i = 0; i < 8001; i++) {
			if(count[i] > modeMax) {
				modeMax = count[i];
			}
		}
		
		int mode = 0;
		boolean isSecond = false;
		for(int i = 0; i < 8001; i++) {
			if(count[i] == modeMax) {
				if(!isSecond) {
					mode = i - 4000;
					isSecond = true;
				}
				else {
					mode = i - 4000;
					break;
				}
			}
		}
		
		System.out.println(mode);
		
		System.out.println(max - min);
	}
	
}
