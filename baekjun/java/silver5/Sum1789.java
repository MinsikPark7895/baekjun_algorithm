package silver5;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;

public class Sum1789 {

	public static void main(String[] args) throws IOException{
		// TODO Auto-generated method stub
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		long S = Long.parseLong(br.readLine());
		
		int N = 1;
		while(true) {
			if (S >= N) S -= N;
			else break;
			N++;
		}
		
		System.out.println(--N);
		
	}

}
