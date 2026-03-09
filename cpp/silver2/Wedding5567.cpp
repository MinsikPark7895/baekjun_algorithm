#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int n, m;

    // 동기 수(n)와 리스트 길이(m) 입력
    if (scanf("%d", &n) != 1) return 0;
    if (scanf("%d", &m) != 1) return 0;

    // 2차원 배열(friends) 동적 할당 및 0으로 초기화 (calloc 사용)
    int **friends = (int **)malloc((n + 1) * sizeof(int *));
    for (int i = 0; i <= n; i++) {
        friends[i] = (int *)calloc((n + 1), sizeof(int)); 
    }
    
    // 방문 배열(visited) 동적 할당 및 0으로 초기화
    int *visited = (int *)calloc((n + 1), sizeof(int));

    // 양방향 간선 연결
    for (int i = 0; i < m; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        friends[a][b] = 1;
        friends[b][a] = 1;
    }

    // 간단한 배열 기반 큐 구현 (최대 n+1 크기)
    int *q = (int *)malloc((n + 1) * sizeof(int));
    int front = 0, rear = 0;

    // 시작 노드(1) 삽입
    q[rear++] = 1; // C++의 q.push(1)
    visited[1] = 1;
    
    int result = 0;
    int cur = 0;

    // 큐가 비어있지 않은 동안 (front < rear)
    while (front < rear) {
        cur = q[front++]; // C++의 q.front() 후 q.pop()

        if (visited[cur] >= 3) {
            break;
        }

        for (int i = 1; i <= n; i++) {
            if (friends[cur][i] == 1 && visited[i] == 0) {
                visited[i] = visited[cur] + 1;
                result += 1;
                q[rear++] = i; // C++의 q.push(i)
            }
        }
    }

    // 결과 출력
    printf("%d\n", result);

    // 사용이 끝난 동적 메모리 반드시 해제 (Memory Leak 방지)
    free(q);
    free(visited);
    for (int i = 0; i <= n; i++) {
        free(friends[i]);
    }
    free(friends);

    return 0;
}