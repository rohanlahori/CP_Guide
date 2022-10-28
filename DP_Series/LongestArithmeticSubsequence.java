package dynamicProgramming;

import java.io.*;
import java.util.*;

public class LongestArithmeticSubsequence {

	//https://leetcode.com/problems/longest-arithmetic-subsequence/submissions/
	public static void main(String[] args) {
		// TODO Auto-generated method stub

		Solution s = new Solution();
		
			int nums[] = {20,1,15,3,10,5,8};
				
				System.out.println(s.longestArithSeqLength(nums));
	}
	
	// Watch  https://www.youtube.com/watch?v=Y3sZ2bsresI
	// I coded his solution.
	
	static class Solution {
		
		public int longestArithSeqLength(int[] nums) {
	        
			int max = Integer.MIN_VALUE;
			
			HashMap<Integer,Integer> t[] = new HashMap[nums.length];
			
			
				for(int i = 0; i<nums.length; i++) {
					
					HashMap<Integer, Integer> current = new HashMap<Integer, Integer>();
					
					t[i] = current;
					
						for(int j  =0; j<i; j++) {
								
							int diff = nums[i]-nums[j];
							
								int val = t[j].getOrDefault(diff,0)+1;
								
								current.put(diff, val);
								max = Math.max(max, val);
								t[i] = current;
						}
				}
				
				return max+1;
	    }
	}

}
