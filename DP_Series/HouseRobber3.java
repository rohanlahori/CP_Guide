package dynamicProgramming;

import java.io.*;
import java.util.*;


public class HouseRobber3 {

	 static class TreeNode {
		      int val;
		      TreeNode left;
		      TreeNode right;
		      TreeNode() {}
		      TreeNode(int val) { this.val = val; }
		      TreeNode(int val, TreeNode left, TreeNode right) {
		          this.val = val;
		          this.left = left;
		          this.right = right;
		      }
		  }
	 
	 static MyScanner sc = new MyScanner();
	 
	public static void main(String[] args) {
		
		TreeNode root = createTree();
		
		Solution s = new Solution();
		
			System.out.println(s.rob(root));
		
	}
	
	static class Solution {
		
		
	    public int rob(TreeNode root) {
	     
	    	
	    	int ans[] = new int[2];
	    	ans = robWisely(root);
	    	
	    	return Math.max(ans[0], ans[1]);
	    }
	    
	    static int[] robWisely(TreeNode root) {
	    	
	    	if(root==null) {
	    		int a[] = new int[2];
	    		return a;
	    	}
	    	
	    	int left[] = robWisely(root.left);
	    	int right[] = robWisely(root.right);
	    	
	    	int ThisNode[] = new int[2];
	    	
	    	// 0th index : Taking this node's data;
	    	// 1st index : Not taking.
	    	
	    	ThisNode[0] = root.val + left[1]+right[1];
	    	
	    	// Since I have not included the root node 
	    	// I have choice of Taking the max from left by taking the left or not taking it. Same for right.
	    	
	    	ThisNode[1] = Math.max(left[0], left[1])+Math.max(right[0], right[1]);
	    	
	    	
	    	return ThisNode;
	    }
	    
	    
	}
	
static TreeNode createTree() {
		
		TreeNode root ;
		
		System.out.println("Enter data ");
		int data = sc.nextInt();
		
		root = new TreeNode(data);
		
			if(data==-1) {
				return null;
			}
			
			System.out.println("Enter data for the left of "+data);
			root.left = createTree();
			
			System.out.println("Enter data for the right of "+data);
			
				root.right = createTree();
				
				return root;
			
	}
	
	
	public static class MyScanner {
	    BufferedReader br;
	    StringTokenizer st;
	
	    public MyScanner() {
	        br = new BufferedReader(new InputStreamReader(System.in));
	    }
	
	    String next() {
	        while (st == null || !st.hasMoreElements()) {
	            try {
	                st = new StringTokenizer(br.readLine());
	            } catch (IOException e) {
	                e.printStackTrace();
	            }
	        }
	        return st.nextToken();
	    }
	
	    int nextInt() {
	        return Integer.parseInt(next());
	    }
	
	    long nextLong() {
	        return Long.parseLong(next());
	    }
	
	    double nextDouble() {
	        return Double.parseDouble(next());
	    }
	
	    String nextLine() {
	        String str = "";
	        try {
	            str = br.readLine();
	        } catch (IOException e) {
	            e.printStackTrace();
	        }
	        return str;
	    }
	}


}
