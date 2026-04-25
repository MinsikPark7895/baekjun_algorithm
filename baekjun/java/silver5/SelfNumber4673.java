package silver5;

public class SelfNumber4673 {
	
	public static int d(int number) {
		int sum = number;
		
		while(number != 0) {
			sum += (number % 10);
			number = number/10;
		}
		
		return sum;
	}

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		boolean[] arr = new boolean[10001];
		
		for (int i = 0; i < 10001; i++) {
			int n = d(i);
			
			if (n < 10001) {
				arr[n] = true;
			}
		}
		
		StringBuilder sb = new StringBuilder();
		
		for (int i = 0; i < 10001; i++) {
			if (!arr[i]) {
				sb.append(i).append('\n');
			}
		}
		
		System.out.println(sb);
		
	}

}
