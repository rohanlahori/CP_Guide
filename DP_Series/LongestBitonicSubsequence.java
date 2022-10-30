package dynamicProgramming;

import java.io.*;
import java.util.*;

public class LongestBitonicSubsequence {

	static MyScanner sc = new MyScanner();
	
	public static void main(String[] args) {
		
		out = new PrintWriter(new BufferedOutputStream(System.out));
		
		
			int n =sc.nextInt();
		int a[] = new int[n];
		
			
		for(int i=0; i<n; i++) {
			a[i] = sc.nextInt();
		}
		
		
		Solution s= new Solution();
		
			out.println(s.LongestBitonicSequence(a));
		out.close();

	}
	
	static class Solution
	{
	    public int LongestBitonicSequence(int[] nums)
	    {
	    	int n = nums.length;
	    	
	        int first[] = new int[n];
	        int second[] = new int[n];
	        
	        	first[0] = 1;
	        	second[n-1] = 1;
	        	
	        		for(int i =1; i<n; i++) {
	        			
	        			int max = Integer.MIN_VALUE;
	        			
	        			for(int j = 0; j<i; j++) {
	        				
	        				if(nums[i]>nums[j]) {
	        					max = Math.max(max, first[j]);
	        				}
	        			}
	        			
	        				if(max==Integer.MIN_VALUE) {
	        					first[i] = 1;
	        				}
	        				else {
	        					first[i] = max+1;
	        				}
	        		}
	        		
	        			for(int i = n-2; i>=0; i--) {
	        				
	        				int max = Integer.MIN_VALUE;
	        				
	        					for(int j = n-1; j>i; j--) {
	        						if(nums[i]>nums[j]) {
	        							max = Math.max(max, second[j]);
	        						}
	        					}
	        					
	        						if(max==Integer.MIN_VALUE) {
	        							second[i] =1;
	        						}
	        						else {
	        							second[i] = max+1;
	        						}
	        			}
	        			
	        			
	        			int ans = 0;
	        				for(int i =0; i<n; i++) {
	        					
	        					ans = Math.max(ans, first[i]+second[i]);
	        				}
	        				
	        					return ans-1;
	    }
	}
	
	public static PrintWriter out;

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
