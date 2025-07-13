package gold5;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;

public class AlphaCentauri1011 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int tc = Integer.parseInt(br.readLine());

        for (int i = 0; i < tc; i++) {
            String[] line = br.readLine().split(" ");
            int start = Integer.parseInt(line[0]);
            int end = Integer.parseInt(line[1]);

            int distance = end - start;
            int max = (int) Math.sqrt(distance);

            if (max * max == distance) {
                System.out.println(max * 2 - 1);   //  n^2 일 경우 2*n - 1
            } else if (distance <= max * max + max) {
                System.out.println(max * 2);       //  n^2 < d <= n^2 + n 일 경우 2n번
            } else {
                System.out.println(max * 2 + 1);   //  n^2 + n < d <= (n + 1)^2 일 경우 2n + 1 필요
            }
        }
    }
}
