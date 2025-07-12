package silver5;

import java.util.Scanner;

public class Paper2563 {
	public static void main(String args[]) {
		Scanner sc = new Scanner(System.in);
			
		int papers = sc.nextInt();  // 색종이 숫자
		
		int xAxis;  // 들어올 x 좌표
		int yAxis;  // 들어올 y 좌표
		
		boolean[][] arr = new boolean[101][101];  // 도화지
		
		int area = 0;  // 현재 색종이로 덮은 영역
		
		for (int i = 0; i < papers; i++) {
			xAxis = sc.nextInt();
			yAxis = sc.nextInt();
			
			// 들어오는 값들을 하나의 셀마다 변환
			for(int j = xAxis; j < xAxis + 10; j++) {
				for (int k = yAxis; k < yAxis + 10; k++) {
					if (!arr[j][k]) {
						arr[j][k] = true;
						area++;
					}
				}
			}
		}
		System.out.println(area);
		
		
	}
}
