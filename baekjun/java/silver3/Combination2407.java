package silver3;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;
import java.util.StringTokenizer;
import java.math.BigInteger;

public class Combination2407 {

	public static void main(String[] args) throws IOException {
		// TODO Auto-generated method stub
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		StringTokenizer st = new StringTokenizer(br.readLine(), " ");
		
		int N = Integer.parseInt(st.nextToken());
		int M = Integer.parseInt(st.nextToken());
		
		BigInteger[] dp = new BigInteger[N + 1];
		
		dp[0] = BigInteger.valueOf(1);
		dp[1] = BigInteger.ONE;
		
		for (int i = 2; i <= N; i++) {
			dp[i] = dp[i - 1].multiply(BigInteger.valueOf(i));
		}
		
		BigInteger answer = dp[N].divide(dp[M]).divide(dp[N - M]);
		
		System.out.println(answer);
		
	}

}
