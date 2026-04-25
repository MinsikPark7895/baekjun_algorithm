import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int[] score = new int[8];
        for (int i = 0; i < 8; i++) {
            score[i] = Integer.parseInt(br.readLine().trim());
        }

        // 0..7 인덱스를 유지하고, 점수 기준 내림차순으로 정렬
        Integer[] order = new Integer[8];
        for (int i = 0; i < 8; i++) order[i] = i;
        Arrays.sort(order, (a, b) -> Integer.compare(score[b], score[a]));

        int sum = 0;
        int[] picked = new int[5];
        for (int i = 0; i < 5; i++) {
            sum += score[order[i]];
            picked[i] = order[i] + 1; // 문제 번호는 1-based
        }

        Arrays.sort(picked); // 번호 오름차순

        StringBuilder sb = new StringBuilder();
        sb.append(sum).append('\n');
        for (int i = 0; i < 5; i++) {
            if (i > 0) sb.append(' ');
            sb.append(picked[i]);
        }
        System.out.println(sb.toString());
    }
}
