package dynamicProgramming;

import java.io.*;
import java.util.*;

public class CountPalindromicSubsequences {

	public static void main(String[] args) {

		Solution s = new Solution();
		
		String str = "abcdabcdabcdabcdabcdabcdabcdabcddcbadcbadcbadcbadcbadcbadcbadcba";
		System.out.println(s.countPS(str));
	}
	
	static class Solution
	{
		static long mod = (long)(1e9 + 7);
		static long t[][] = new long[1001][1001];
		{
			for(int i = 0; i<1001; i++) {
				for(int j= 0; j<1001; j++) {
					t[i][j] = -1;
				}
			}
		}
		
	   static long countPS(String str)
	    {
	        
		   return countfromitoj(str, 0, str.length()-1);
	    }
	   
	   static long countfromitoj(String str,int i , int j) {
		   
		   if(i>j) {
			   return 0;
		   }
		   if(i==j) {
			   return 1;
		   }
		   
		   if(t[i][j]!=-1) {
			   return t[i][j];
		   }
		   
		   if(str.charAt(i)==str.charAt(j)) {
			   return t[i][j]= ((1 + countfromitoj(str,i+1,j)%mod+countfromitoj(str, i, j-1)%mod)%mod - (countfromitoj(str, i+1, j-1)%mod) + mod)%mod;
		   }
		   else {
			   return t[i][j]=((countfromitoj(str,i+1,j)%mod+countfromitoj(str, i, j-1)%mod)%mod - (countfromitoj(str, i+1, j-1)%mod) + mod)%mod;
		   }
	   }
	}

}
