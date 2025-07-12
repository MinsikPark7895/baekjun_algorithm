package bronze4;

import java.util.Scanner;

public class Alphabet10808 {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		String word = sc.nextLine();
		
		int[] arr = new int[26];
		
		for (int i = 0; i < word.length(); i++) {
			char c = word.charAt(i);
			arr[c-97]++;
			
		}
		for (int j = 0; j < 26; j++) {
			System.out.print(arr[j] + " ");
		}
	}
}
