#include <stdio.h>
#define MAX_STUDENT 32005
#define MAX_EDGE 100005

// vector 대신 사용할 링크드 리스트 
typedef struct Node{
    int vertex;
    struct Node* next;
} Node;

Node pool[MAX_EDGE];
int poolCnt = 0;

Node* edgeInfo[MAX_STUDENT];

// 간선 추가 
void addEdge(int a, int b) {
    Node* newNode = &pool[poolCnt++];
    newNode->vertex = b;
    
    newNode->next = edgeInfo[a];
    edgeInfo[a] = newNode;
}


int inDegree[MAX_STUDENT];

int queue[MAX_STUDENT];
int front = 0;
int rear = 0;

void bfs(int n) {
    for(int i = 1; i <= n; i++) {
        if (inDegree[i] == 0) {
            queue[rear++] = i;
        }
    }
    
    while (front < rear) {
        int curr = queue[front++];
        printf("%d ", curr);
        
        
        for (Node* temp = edgeInfo[curr]; temp != NULL; temp = temp->next){
            int nextVertex = temp->vertex;
            
            inDegree[nextVertex]--;
            if(inDegree[nextVertex] == 0){
                queue[rear++] = nextVertex;
            }
        }
    }
    printf("\n");
}

int main()
{
    int N, M;
    scanf("%d %d", &N, &M);
    
    for (int i = 0; i < M; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        
        addEdge(a, b);
        inDegree[b]++;
    }
    
    bfs(N);

    return 0;
}