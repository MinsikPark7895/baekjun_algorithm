package silver2;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Deque;
import java.util.ArrayList;

public class LinkedNodes11724 {
    static boolean[] visited;
    static ArrayList<Integer>[] graph;

    public static void dfs(int node) {
        visited[node] = true;

        for (int next : graph[node]) {
            if (!visited[next]) {
                dfs(next);
            }
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        String[] nm = br.readLine().split(" ");
        int n = Integer.parseInt(nm[0]); // 정점의 수
        int m = Integer.parseInt(nm[1]); // 간선의 수

        graph = new ArrayList[n + 1];
        visited = new boolean[n + 1];

        // 인접 리스트 초기화
        for (int i = 1; i <= n; i++) {
            graph[i] = new ArrayList<>();
        }

        // 간선 정보 입력
        for (int i = 0; i < m; i++) {
            String[] edge = br.readLine().split(" ");
            int u = Integer.parseInt(edge[0]);
            int v = Integer.parseInt(edge[1]);

            graph[u].add(v);
            graph[v].add(u); // 무방향 그래프
        }

        int count = 0; // 연결 요소 개수

        for (int i = 1; i <= n; i++) {
            if (!visited[i]) {
                dfs(i);
                count++;
            }
        }

        System.out.println(count);
    }
}