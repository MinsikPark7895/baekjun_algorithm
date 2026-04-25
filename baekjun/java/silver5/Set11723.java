package silver5;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;

public class Set11723 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int M = Integer.parseInt(br.readLine());
        int bitSet = 0;

        StringBuilder sb = new StringBuilder();

        for (int i = 0; i < M; i++) {
            String[] input = br.readLine().split(" ");
            String cmd = input[0];

            if (cmd.equals("add")) {
                int x = Integer.parseInt(input[1]);
                bitSet |= (1 << x);
            } else if (cmd.equals("remove")) {
                int x = Integer.parseInt(input[1]);
                bitSet &= ~(1 << x);
            } else if (cmd.equals("check")) {
                int x = Integer.parseInt(input[1]);
                sb.append((bitSet & (1 << x)) != 0 ? 1 : 0).append("\n");
            } else if (cmd.equals("toggle")) {
                int x = Integer.parseInt(input[1]);
                bitSet ^= (1 << x);
            } else if (cmd.equals("all")) {
                bitSet = (1 << 21) - 1; // 1~20까지 비트 켜기
            } else if (cmd.equals("empty")) {
                bitSet = 0;
            }
        }

        System.out.print(sb);
    }
}
