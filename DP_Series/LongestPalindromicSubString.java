package dynamicProgramming;

import java.io.*;
import java.util.*;

public class LongestPalindromicSubString {

	public static void main(String[] args) {
		
		
		Solution s = new Solution();
		
			System.out.println(s.longestPalindrome("ccd"));
		
			
	}
	
	static class Solution {
	    public String longestPalindrome(String s) {
	    	
	        
	    	if(s.length()==2) {
	    		if(s.charAt(0)==s.charAt(1)) {
	    			return s;
	    		}
	    		else {
	    			return s.substring(0,1);
	    		}
	    	}
	    
	    	int max = Integer.MIN_VALUE;
	    	String ans = s.substring(0,1);
	    	
	    	for(int i =0; i<s.length(); i++) {
	    		
	    		int cur = i-1;
	    		int nex = i+1;
	    		
	    			while(cur>=0 && nex<s.length() && s.charAt(cur)==s.charAt(nex)) {
	    				if(((nex-cur)+1)>max) {
	    					max = (nex-cur)+1;
	    					ans = s.substring(cur,nex+1);
	    				}
	    				cur--;
	    				nex++;
	    				
	    			}
	    			
	    			cur = i;
	    			nex= i+1;
	    			
	    			while(cur>=0 && nex<s.length() && s.charAt(cur)==s.charAt(nex)) {
	    				if(((nex-cur)+1)>max) {
	    					max = (nex-cur)+1;
	    					ans = s.substring(cur,nex+1);
	    				}
	    				cur--;
	    				nex++;
	    				
	    			}
	    	}
	    	
	    	return ans;
	    }
	    
	}

}
