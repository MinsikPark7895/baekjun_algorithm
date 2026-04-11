#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void postfix(char* str, int index, char* stack, int* top) {
	// 종료 조건 : 문자열의 끝 또는 getline이 포함시킨 '\n'일 경우
	if (str[index] == '\n' || str[index] == '\0') {
		while (*top >= 0) {
		    printf("%c", stack[(*top)--]);
		}
		return ;
	}

    char c = str[index];
	
	if (c >= 'A' && c <= 'Z') {
		printf("%c", c);
	}
	else if (c == '(') {
        stack[++(*top)] = c;
	}
	else if (c == '*' || c == '/') {
        while (*top >= 0 && (stack[*top] == '*' || stack[*top] == '/')){
            printf("%c", stack[(*top)--]);
        }
        stack[++(*top)] = c;
	}
	else if (c == '+' || c == '-') {
        while (*top >= 0 && stack[*top] != '(') {
            printf("%c", stack[(*top)--]);
        }
        stack[++(*top)] = c;
	}
	else if (c == ')') {
	    while(*top >= 0 && stack[*top] != '(') {
	        printf("%c", stack[(*top)--]);
	    }
	    if (*top >= 0) {
	        (*top)--;
	    }
	}
	postfix(str, index + 1, stack, top);
	

}

int main(void) {

	char* str = NULL;
	size_t size = 0;

	if (getline(&str, &size, stdin) == -1) {
	    free(str);
	    return 0;
	};

	// 괄호를 담을 스택 
	int len = strlen(str);
	char* stack = (char*)malloc(len * sizeof(char));

	if (stack == NULL) {
	    free(str);
	    return 1;
	}

    int top = -1;

	postfix(str, 0, stack, &top);
	printf("\n");


    free(stack);
	free(str);


	return 0;
}