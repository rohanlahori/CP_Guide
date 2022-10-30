package dynamicProgramming;

import java.io.*;
import java.util.*;

public class LongestCommonSubsequence {

	public static void main(String[] args) {
		// TODO Auto-generated method stub

		System.out.println(lcs("intention","execution"));
	}
	
	static int lcs(String s, String t) {
		
		int ss = s.length();
		int tt = t.length();
		
		int dp[][] = new int[ss+1][tt+1];
		
		
		for(int i = 1; i<=ss; i++) {
			for(int j =1; j<=tt; j++) {
				if(s.charAt(i-1)==t.charAt(j-1)) {
					dp[i][j] = 1+dp[i-1][j-1];
				}
				else {
					dp[i][j] = Math.max(dp[i-1][j], dp[i][j-1]);
				}
			}
		}
		
		return dp[ss][tt];
	}

}
