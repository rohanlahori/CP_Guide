package dynamicProgramming;

import java.io.*;
import java.util.*;

public class HouseRobber2 {

	static MyScanner sc = new MyScanner();
	
	public static void main(String[] args) {
		
		out = new PrintWriter(new BufferedOutputStream(System.out));
		
		
		int n = sc.nextInt();
		int a[] = new int[n];
		
			for(int i = 0; i<n; i++) {
				a[i] = sc.nextInt();
			}
			
		Solution  s = new Solution();
		
			out.println(s.rob(a));
		
		out.close();

	}
	
	static class Solution {
		
		
		int z[] = new int[101];
		{
			Arrays.fill(z, -1);
		}
		
		int o[] = new int[101];
		{
			Arrays.fill(o, -1);
		}
		
		
	    public int rob(int[] a) {
	     
	    	
	    	int n = a.length;
	    	
	    		if(n==1) {
	    			return a[0];
	    		}
	    		if(n==2) {
	    			return Math.max(a[0], a[1]);
	    		}
	    		if(n==3) {
	    			return Math.max(a[2], Math.max(a[0], a[1]));
	    		}
	    		
	    			int ze = zero(a, n-1);
	    			int on = one(a, n);
	    			
	    				out.println("zero "+ ze +" one "+ on );
	    				
	    					return Math.max(ze, on);
	    			
	    				
	    }
	    
	    public int zero(int a[] , int n) {
	    	
	    		if(n==0) {
	    			return 0;
	    		}
	    		
	    			if(z[n]!=-1) {
	    				return z[n];
	    			}
	    			
	    				z[1] = a[0];
	    				z[2] = Math.max(a[0], a[1]);
	    				
	    					for(int i = 3; i<=n; i++) {
	    						z[i]  = Math.max(a[i-1]+zero(a, i-2), zero(a, i-1));
	    					}
	    					
	    						return z[n];
	    			
	    }
	    public int one(int a[] , int n) {
	    	
	    	if(n==0) {
	    		return 0;
	    	}
	    		if(o[n]!=-1) {
	    			return o[n];
	    		}
	    		
	    			o[1] = a[1];
	    			o[2] = Math.max(a[1], a[2]);
	    			
	    				for(int i =3; i<n; i++) {
	    					o[i] = Math.max(a[i]+ one(a,i-2),one(a, i-1));
	    				}
	    				
	    					return o[n-1];
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
