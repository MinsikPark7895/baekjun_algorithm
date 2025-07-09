package silver1;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class BinaryTree1991 {
	
	static Node head = new Node('A', null, null);
	
	public static void main(String args[]) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		int N = Integer.parseInt(br.readLine());
		
		for(int i = 0; i < N; i++) {
			StringTokenizer st = new StringTokenizer(br.readLine());
			
			char root = st.nextToken().charAt(0);
			char left = st.nextToken().charAt(0);
			char right = st.nextToken().charAt(0);
			
			insertNode(head, root, left, right);
		}
		
		preorder(head);
		System.out.println();
		inorder(head);
		System.out.println();
		postorder(head);
		System.out.println();
		
	}
	
	static class Node{
		char value;
		Node left;
		Node right;
		
		Node(char value, Node left, Node right) {
			this.value = value;
			this.left = left;
			this.right = right;
		}
	}
	
	public static void insertNode(Node temp, char root, char left, char right) {
		
		if (temp.value == root) {
			temp.left = (left == '.' ? null : new Node(left, null, null));
			temp.right = (right == '.' ? null : new Node(right, null, null));
		}
		else {
			if (temp.left != null) {
				insertNode(temp.left, root, left, right);
			}
			if (temp.right != null) {
				insertNode(temp.right, root, left, right);
			}
		}
	}
	
	public static void preorder(Node node) {
		if (node == null ) {
			return;
		}
		System.out.print(node.value);
		preorder(node.left);
		preorder(node.right);
	}
	
	private static void inorder(Node node) {
		if (node == null) {
			return;
		}
		inorder(node.left);
		System.out.print(node.value);
		inorder(node.right);
	}
	
	private static void postorder(Node node) {
		if (node == null) {
			return;
		}
		postorder(node.left);
		postorder(node.right);
		System.out.print(node.value);
	}
}
