package gold5;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Z1074 {
    static int result = 0;   // 반환할 결과
    static int r, c;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] parts = br.readLine().split(" ");

        int N = Integer.parseInt(parts[0]);   // 한 변 길이
        r = Integer.parseInt(parts[1]);       // 찾는 행 위치
        c = Integer.parseInt(parts[2]);       // 찾는 열 위치

        int size = 1 << N;  

        backtrack(size, 0, 0);   // 백트래킹 시작

        System.out.println(result);
    }

    static void backtrack(int size, int row, int col) {
        if (size == 1) return;

        int half = size / 2;

        if (r < row + half && c < col + half) { // 1사분면
            backtrack(half, row, col);
        } else if (r < row + half && c >= col + half) { // 2사분면
            result += half * half * 1;
            backtrack(half, row, col + half);
        } else if (r >= row + half && c < col + half) { // 3사분면
            result += half * half * 2;
            backtrack(half, row + half, col);
        } else { // 4사분면
            result += half * half * 3;
            backtrack(half, row + half, col + half);
        }
    }
}
