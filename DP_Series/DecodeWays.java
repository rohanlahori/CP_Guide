package dynamicProgramming;

import java.io.*;
import java.util.*;

public class DecodeWays {

	static MyScanner sc = new MyScanner();
	
	public static void main(String[] args) {
		
		Solution s = new Solution();
		
		System.out.println(s.numDecodings("226"));
		
	}
	
	static class Solution {
		
		static int t[] = new int[101];
		{
			Arrays.fill(t, -1);
		}
		
		public int numDecodings(String s) {
	        
			int n = s.length();
			
				int a[] = new int[n];
				
					for(int i =0; i<n; i++) {
						a[i] = s.charAt(i)-'0';
					}
			
					return ways(a,n);
				
	    }
		
		static int ways(int a[] , int n) {
			
			if(t[n]!=-1) {
				return t[n];
			}
			
			if(n==0) {
				return t[0]=1;
			}
			
			
			else {
				if(n>=2) {
				
					if(a[n-1]==0) {
						if(a[n-2]==1 || a[n-2]==2) {
							t[n] = ways(a,n-2);
						}
						else {
							t[n] = 0;
						}
					}
					else {
						
						int temp = a[n-2]*10 + a[n-1];
						
							if(temp>=11 && temp<=26) {
								t[n] = ways(a,n-1)+ways(a,n-2);
							}
							else {
								t[n] = ways(a,n-1);
							}
					}
				}
				else {
					 
					if(a[n-1]==0) {
						t[n] = 0;
					}
					else {
						t[n] = ways(a, n-1);
					}
				}
			}
			
			return t[n];
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
