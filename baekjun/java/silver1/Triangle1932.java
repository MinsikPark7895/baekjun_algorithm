package silver1;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;

public class Triangle1932 {
    static int n;
    static int[][] arr = new int[501][501];

    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        n = Integer.parseInt(br.readLine());

        // 삼각형 입력 받기
        for (int i = 1; i <= n; i++) {
            String[] inputs = br.readLine().split(" ");
            for (int j = 1; j <= i; j++) {
                arr[i][j] = Integer.parseInt(inputs[j - 1]);
            }
        }

        // Bottom-up DP
        for (int i = n - 1; i >= 1; i--) {
            for (int j = 1; j <= i; j++) {
                arr[i][j] += Math.max(arr[i + 1][j], arr[i + 1][j + 1]);
            }
        }

        System.out.println(arr[1][1]);  // 최상단 값이 최대 경로합
    }
}
