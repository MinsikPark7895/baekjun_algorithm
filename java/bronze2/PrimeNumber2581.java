package bronze2;

import java.util.Scanner;

public class PrimeNumber2581 {
	public static void main(String[] args) {
		int totalSum, minNum;
		int num1, num2;
		
		Scanner sc = new Scanner(System.in);
		
		totalSum = 0;
		minNum = -1;
		num1 = sc.nextInt();
		num2 = sc.nextInt();
		
		for (int i = num1; i <= num2; i++) {
			if (isPrime(i)) {
				totalSum += i;
				if (minNum == -1) {
					minNum = i;
				}
			}
		}
		if (totalSum != 0) {
			System.out.println(totalSum);
			System.out.println(minNum);
		}
		else {
			System.out.println(-1);
		}
	}
	
	public static boolean isPrime(int n) {
		if (n < 2) {
			return false;
		}
		for (int i = 2; i <= Math.sqrt(n); i++) {
			if(n % i == 0) {
				return false;
			}
		}
		return true;
	}
}
