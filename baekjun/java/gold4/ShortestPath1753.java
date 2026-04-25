package gold4;

import java.io.*;
import java.util.*;

public class ShortestPath1753 {
	static class Node implements Comparable<Node>{
		int toNode;
		int e;
		
		@Override
		public int compareTo(Node o) {
			return this.e -o.e;
		}
		
		public Node(int toNode, int e) {
			this.toNode = toNode;
			this.e = e;
		}
	}
	
	public static void main(String args[]) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		
		int V = Integer.parseInt(st.nextToken());
		int E = Integer.parseInt(st.nextToken());
		int K = Integer.parseInt(br.readLine());
		
		ArrayList<Node>[] graph = new ArrayList[V+1];
		
		int[] djikstra = new int[V + 1];
		
		boolean[] visited = new boolean[V + 1];
		
		for (int i = 0; i <= V; i++) {
			graph[i] = new ArrayList<>();
			djikstra[i] = Integer.MAX_VALUE;
		}
		
		for(int i=1; i <= E; i++) {
			st = new StringTokenizer(br.readLine());
			int u = Integer.parseInt(st.nextToken());
			int v = Integer.parseInt(st.nextToken());
			int w = Integer.parseInt(st.nextToken());
			graph[u].add(new Node(v, w));
		}
		
		PriorityQueue<Node> queue = new PriorityQueue<>();
		
		djikstra[K] = 0;
		queue.offer(new Node(K, 0));
		
		while(!queue.isEmpty()) {
			Node now = queue.poll();
			visited[now.toNode] = true;
			for(Node node : graph[now.toNode]) {
				if(!visited[node.toNode]) {
					if(djikstra[now.toNode] + node.e < djikstra[node.toNode]) {
						djikstra[node.toNode]= djikstra[now.toNode] + node.e;
						queue.offer(new Node(node.toNode, djikstra[node.toNode]));
					}
				}
			}
		}
		
		StringBuilder sb = new StringBuilder();
		for(int i=1; i <= V; i++) {
			if(djikstra[i] == Integer.MAX_VALUE) {
				sb.append("INF\n");
			} else {
				sb.append(djikstra[i]+"\n");
			}
		}
		
		System.out.println(sb);
	}
}
