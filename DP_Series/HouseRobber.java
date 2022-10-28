package dynamicProgramming;

import java.io.*;
import java.util.*;

public class HouseRobber {

	static MyScanner sc = new MyScanner();
	
	public static void main(String[] args) {
		
		out = new PrintWriter(new BufferedOutputStream(System.out));
		
		int n =sc.nextInt();
		int a[] = new int[n];
		
			for(int i  =0;i<n; i++) {
				a[i] = sc.nextInt();
			}
			
			Solution s = new Solution();
				
				out.println(s.rob(a));
				
		out.close();
	}
	
	static class Solution {
		
		int t[] = new int[101];
		{
			Arrays.fill(t, -1);
		}
		
	    public int rob(int[] a) {
	    	
	    	int n = a.length;
	    	
	    		
	    	if(n==1) {
	    		return a[0];
	    	}
	    	
	    		if(n==2) {
	    			return Math.max(a[0], a[1]);
	    		}
	        
	    	return steal(a, a.length);
	    		
	    }
	    
	    public int steal(int a[], int n) {
	    	
	    	if(n==0) {
	    		return 0;
	    	}
	    	
	    	if(t[n]!=-1) {
	    		return t[n];
	    		
	    	}
	    	
	    	t[1]= a[0];
	    	t[2] = Math.max(a[0], a[1]);
	    	
	    		for(int i =3; i<=n; i++) {
	    			t[i] = Math.max(a[i-1]+steal(a, i-2), steal(a, i-1));
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
