package dynamicProgramming;

import java.io.*;
import java.util.*;


// On LeetCode this question is named as Wiggle Subsequence;

public class LongestAlternatingSubsequence {

	public static void main(String[] args) {
		
		Solution s = new Solution();
		
		int nums[] = {1,2,3,4,5,6,7,8,9};
		
		System.out.println(s.AlternatingaMaxLength(nums));
	}
	
	static class Solution
	{
	    public int AlternatingaMaxLength(int[] nums)
	    {
	        
	    	int min = 1;
	    	int max = 1;
	    	
	    		for(int i =1; i<nums.length; i++) {
	    			
	    			if(nums[i]>nums[i-1]) {
	    				max = min+1;
	    			}
	    			else if(nums[i]<nums[i-1]){
	    				min = max+1;
	    			}
	    		}
	    		
	    		return Math.max(min, max);
	    }
	}

}
