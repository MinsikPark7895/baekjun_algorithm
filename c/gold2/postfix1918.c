#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* postfix(int n, char* buffer, int index, int* sign, char* parentheses) {
	if (index >= n) {
		buffer[index] = '\0';
		return buffer;
	}

	
	if (buffer[index] == '+' || buffer[index] == '-' || buffer[index] == '*' || buffer[index] == '/') {
			
	}
	else if (buffer[index] == '(') {

	}
	else if (buffer[index] == ')') {

	}
	else {

	}
	postfix(n, buffer, index + 1, sign, parentheses);
	

}

int main(void) {

	char* str = NULL;
	size_t size = 0;

	getline(&str, &size, stdin);

	// 괄호를 담을 스택 
	char* stack = NULL;
	int* stack_idx = NULL;

	char* sign;  // 연산 기호들을 담을 배열
	char* letter;  // 문자를 담을 배열

	
	char* result;

	result = postfix(size, stack, 0, stack_idx, stack);


	free(str);


	return 0;
}