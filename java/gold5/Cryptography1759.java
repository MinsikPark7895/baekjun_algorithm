package gold5;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;

public class Cryptography1759 {
	
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	
	static int L;
	static int C;
	static String[] letters;
	
	public static void main(String args[]) throws IOException {
		
		String[] line = br.readLine().split(" ");
		
		L = Integer.parseInt(line[0]);
		C = Integer.parseInt(line[1]);
		
		letters = br.readLine().split(" ");
		
		Arrays.sort(letters);
		
		findCrypt("", 0);
	}
	
	// 백트래킹 로직
	public static void findCrypt(String pw, int idx) {
		// 암호의 길이가 원하는 길이일 경우
		if(pw.length() == L) {
			if(check(pw)) {
				System.out.println(pw);
			}
			return;
		}
		// 그 외에는 다른 것을 찾음
		for (int i=idx; i < C; i++) {
			findCrypt(pw + letters[i], i + 1);
		}
		
	}
	
	// 최소 1개의 모음과 2개의 자음이 포함되었는지 판별하는 함수
	public static boolean check(String pw) {
		int vowel = 0;   // 모음 개수
		int consonant = 0;    // 자음 개수
		
		// for-each 구문을 통해 판별
		for (char c: pw.toCharArray()) {
			if("aeiou".indexOf(c) >= 0) {
				vowel++;
			}
			else {
				consonant++;
			}
		}
		// 생성된 bool 값 반환
		return vowel >= 1 && consonant >= 2;
	}
}
