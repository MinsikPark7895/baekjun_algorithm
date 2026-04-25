package silver5;

import java.util.*;

public class Polyomino1343 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc = new Scanner(System.in);
		String s = sc.next();
		sc.close();
		
		String res = "";
		
		res = Polyomino(s);
		
		System.out.println(res);
	}
	
	private static String Polyomino(String s) {
		String ans = "";
		String A = "AAAA";
		String B = "BB";
		
		s = s.replaceAll("XXXX", A);
		ans = s.replaceAll("XX", B);
		
		if (ans.contains("X")) {
			ans = "-1";
		}
		
		return ans;
	}

}
