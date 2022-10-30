package dynamicProgramming;

import java.io.*;
import java.util.*;

public class LongestIncreasingSubsequence {

	static MyScanner sc = new MyScanner();
	
	public static void main(String[] args) {
		
		out = new PrintWriter(new BufferedOutputStream(System.out));
		
		
		int n = sc.nextInt();
		int a[] = new int[n];
		
			for(int i = 0; i<n; i++) {
				a[i] =sc.nextInt();
			}
			
				Solution s = new Solution();
				
				//out.println();
					out.println(s.MaxLIS(a));
			out.close();

	}

	static class Solution {
		
	    public int lengthOfLIS(int[] a) {
	        
	    	int t[] = new int[a.length];
	    	
	    		t[0] = 1;
	    		
	    			for(int i =1; i<a.length; i++) {
	    				int max = Integer.MIN_VALUE;
	    				
	    					for(int j = 0; j<i; j++) {
	    						if(a[i]>a[j]) {
	    							max = Math.max(max, t[j]);
	    						}
	    					}
	    					
	    						if(max==Integer.MIN_VALUE) {
	    							t[i] = 1;
	    						}
	    						else {
	    							t[i] = max+1;
	    						}
	    			}
	    			
	    			int ans = Integer.MIN_VALUE;
	    			
	    				for(int i = 0; i<t.length; i++) {
	    					ans = Math.max(ans, t[i]);
	    				}
	    				
	    					return ans;
	    }
	    
	    
	    // using n*log(n) approach
	    
	    	public int MaxLIS(int a[]) {
	    		
	    		
	    		ArrayList<Integer> al = new ArrayList<>();
	    		
	    		al.add(a[0]);
	    		
	    			for(int i = 1; i<a.length; i++) {
	    				
	    				if(a[i]>al.get(al.size()-1)) {
	    					al.add(a[i]);
	    				}
	    				else {
	    					int ind = Collections.binarySearch(al, a[i]);
	    					
	    						if(ind<0) {
	    							al.set(Math.abs(ind)-1, a[i]);
	    						}
	    				}
	    			}
	    			
	    			return al.size();
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
