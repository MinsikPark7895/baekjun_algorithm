package silver5;

import java.util.Scanner;

public class Croatia2941 {
	public static boolean contains(String[] arr, String target) {
		for (String s : arr) {
			if (s.equals(target)) {
				return true;
			}	
		}
		return false;
	}
	
	
	public static void main(String args[]) {
		Scanner sc = new Scanner(System.in);
		
		String crypt = sc.nextLine();
		
		String[] croatian = {"c=", "c-", "d-", "lj", "nj", "s=", "z="};
		
		int idx = 0;
		int cnt = 0;
		
		while (idx < crypt.length()) {
//			현재 남은 문자 개수가 3 이상이고 이게 dz= 일 때
			if (idx + 3 <= crypt.length() && crypt.substring(idx, idx+3).equals("dz=")) {
				idx = idx + 3;
			}
			
			else if (idx + 2 <= crypt.length() && contains(croatian, crypt.substring(idx, idx+2))) {
				idx = idx + 2;
			} else {
				idx++;
			}
			cnt++;
//			System.out.println(crypt.substring(idx, crypt.length()));
		}
		
		System.out.println(cnt);
		
		sc.close();
		
	}
}
