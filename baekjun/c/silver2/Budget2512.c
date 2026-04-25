#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main(void) {

	int N;
	scanf("%d", &N);

	int* arr = (int*)malloc(N * sizeof(int));

	for (int i = 0; i < N; i++) {
		scanf("%d", &arr[i]);
	}

	int M;
	scanf("%d", &M);

	// 정렬 (N ^ 2)
	for (int i = 0; i < N; i++) {
		for (int j = i; j < N; j++) {
			if (arr[i] > arr[j]) {
				int temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
	}

	// 누적합 배열
	int* prefix = (int*)malloc(N * sizeof(int));

	prefix[0] = arr[0];
	
	for (int i = 1; i < N; i++) {
		prefix[i] = prefix[i - 1] + arr[i];
	}

	int result = 0;

	for (int i = 0; i < N; i++) {
		// 이전 누적합 확인
		int previous_sum;
		if (i == 0) {
			previous_sum = 0;
		}
		else {
			previous_sum = prefix[i - 1];
		}

		// (이전까지 금액 합) + (현재 도시의 요청액 * 남은 도시)
		int total_needed = previous_sum + arr[i] * (N - i);

		if (total_needed > M) {
			int left_budget = M - previous_sum;
			result = left_budget / (N - i);
			break;
		}
	}

	if (result == 0) {
		result = arr[N - 1];
	}

	printf("%d\n", result);

	free(prefix);
	free(arr);

	return 0;
}