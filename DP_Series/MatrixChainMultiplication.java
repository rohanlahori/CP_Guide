package dynamicProgramming;

import java.io.*;
import java.util.*;

public class MatrixChainMultiplication {

	// Time complexity of MCM = O(n^2)
	// Space : O(n^2)
	
	public static void main(String[] args) {
		
		
		Solution s = new Solution();
		
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int a[] = new int[n];
		
		for(int i = 0; i<n; i++) {
			a[i] = sc.nextInt();
		}
		System.out.println(s.matrixMultiplication(a.length,a));
	}
	
	static class Solution{
		
		
		static int t[][] = new int[1001][1001];
		{
			for(int e[] :  t) {
				Arrays.fill(e, -1);
			}
		}
	    static int matrixMultiplication(int N, int arr[])
	    {
	        return solve(arr,1,N-1);
	    }
	    
	    static int solve(int a[] , int i , int j) {
	    	
	    	
	    	if(i>=j) {
	    		return 0;
	    	}
	    	
	    	if(t[i][j]!=-1) {
	    		return t[i][j];
	    	}
	    	
	    	int min = Integer.MAX_VALUE;
	    	
	    	
	    	
	    	for(int k = i; k<=j-1; k++) {
	    		
	    		int temp1 = solve(a, i, k);
	    		int temp2 = solve(a,k+1,j);
	    		int theMatrixFormed = a[i-1]*a[k]*a[j];
	    		
	    		
	    		min = Math.min(min, temp1+temp2+theMatrixFormed);
	    	}
	    	
	    	return t[i][j]= min;
	    }
	}

}
