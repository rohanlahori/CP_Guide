package dynamicProgramming;

import java.io.*;
import java.util.*;

public class _0_1_Knapsack {

	public static void main(String[] args) {
		
		
		
		
		
		Scanner sc = new Scanner(System.in);
		
		int n =  sc.nextInt();
		int W = sc.nextInt();
		int val[] = new int[n];
		int wt[] =  new int[n];
		
			for(int i = 0; i<n; i++) {
				val[i] = sc.nextInt();
			}
			
			for(int i = 0; i<n; i++) {
				wt[i] = sc.nextInt();
			}
		
		
		
		Solution s = new Solution();
		
		//double start = System.currentTimeMillis();
			System.out.println(s.knapSack(W, wt, val, val.length));
		//	double end = System.currentTimeMillis();
			
			//System.out.println("Number of elements : "+val.length);
		//	System.out.println("Time taken : "+(end-start));
	}
	
	static class Solution 
	{ 
		static int t[][] = new int[9000][9000];
		
	    //Function to return max value that can be put in knapsack of capacity W.
		
	    static int knapSack(int W, int wt[], int val[], int n) 
	    { 
	         for(int i = 0; i<9000; i++) {
	        	 t[i][0] = 0;
	        	 t[0][i] = 0;
	         }
	         
	         for(int i =1; i<=n; i++) {
	        	 for(int j = 1; j<=W; j++) {
	        		 
	        		 if(wt[i-1]<=j) {
	        			 t[i][j] = Math.max(t[i-1][j], val[i-1]+t[i-1][j-wt[i-1]]);
	        		 }
	        		 else {
	        			 t[i][j] = t[i-1][j];
	        		 }
	        	 }
	         }
	         
	         	return t[n][W];
	    } 
	}

}
