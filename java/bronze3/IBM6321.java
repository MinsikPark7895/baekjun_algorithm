import java.util.Scanner;

public class IBM6321 {
	public static void main(String[] args) {
		int testCase;
		Scanner sc = new Scanner(System.in);
		
		testCase = sc.nextInt();
		
		String[] word;
		
		for (int i = 0; i < testCase; i++) {
			System.out.println("String #" + (i+1));
			word = sc.next().split("");
			for (int j = 0; j < word.length; j++) {
				char answer = word[j].charAt(0);
				answer += 1;
				if(answer == 91) {
					answer = 65;
				}
				System.out.print(answer);
			}
			System.out.println();
			System.out.println();
		}
		sc.close();
	}
}
