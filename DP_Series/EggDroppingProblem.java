package dynamicProgramming;

import java.io.*;
import java.util.*;

public class EggDroppingProblem {

	public static void main(String[] args) {
		// TODO Auto-generated method stub

		Solution s = new Solution();
		
		
		System.out.println(s.eggDrop(1, 2));
	}
	

static class Solution 
{
    //Function to find minimum number of attempts needed in 
    //order to find the critical floor.
	
	static int t[][] = new int[202][202];
	{
		for(int i = 0; i<202; i++) {
			for(int j = 0; j<202; j++) {
				t[i][j] = -1;
			}
		}
	}
    static int eggDrop(int n, int k) 
	{
	    // Your code here
    	if(k==0 || k==1) {
    		return k;
    	}
    	
    	if(n==1) {
    		return k;
    	}
    	
    	if(t[n][k]!=-1) {
    		return t[n][k];
    	}
    	
    	int ans = Integer.MAX_VALUE;
    	
    		for(int i = 1; i<=k; i++) {
    			
    			int eggBreaksAtith = eggDrop(n-1,i-1);
    			int eggDosentBreak = eggDrop(n,k-i);
    			
    			int attemptsAtThisFloor = 1 + Math.max(eggBreaksAtith, eggDosentBreak);
    		
    			ans = Math.min(ans, attemptsAtThisFloor);
    		}
    		
    		return t[n][k]=ans;
	}
}

}
