#include <stdio.h>
#define MAX 5
int graph[MAX][MAX] = {{0, 1, 1, 0, 0}, {1, 0, 0, 1, 1}, {1, 0, 0, 0, 0}, {0, 1, 0, 0, 0}, {0, 1, 0, 0, 0}};
int visited[MAX] = {0};

void DFS(int v) {
    printf("%d ", v);
    visited[v] = 1;
    for (int i = 0; i < MAX; i++) if (graph[v][i] && !visited[i]) DFS(i);
}
void BFS(int v) {
    int queue[MAX], front = -1, rear = -1;
    printf("%d ", v); visited[v] = 1; queue[++rear] = v;
    while (front != rear) {
        v = queue[++front];
        for (int i = 0; i < MAX; i++) {
            if (graph[v][i] && !visited[i]) {
                printf("%d ", i); visited[i] = 1; queue[++rear] = i;
            }
        }
    }
}
int main() {
    printf("DFS: "); DFS(0); 
    for (int i = 0; i < MAX; i++) visited[i] = 0;
    printf("\nBFS: "); BFS(0);
    return 0;
}
