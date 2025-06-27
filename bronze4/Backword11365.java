package bronze4;

import java.util.Scanner;

public class Backword11365 {
	public static void main(String[] args) {
		String sentence;
		Scanner sc = new Scanner(System.in);
		
		while(true) {
			sentence = sc.nextLine();
			if (sentence.equals("END")) {
				break;
			}
			for (int i = 0; i < sentence.length(); i++) {
				System.out.print(sentence.charAt(sentence.length() - 1 - i));
			}
			System.out.println();
		}
	}
}
