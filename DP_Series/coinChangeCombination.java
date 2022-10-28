package dynamicProgramming;

import java.io.*;
import java.util.*;

// https://www.pepcoding.com/resources/online-java-foundation/dynamic-programming-and-greedy/coin-change-combination-official/ojquestion

public class coinChangeCombination {

	public static void main(String[] args) {
		
		Scanner sc = new Scanner(System.in);
		
		int n = sc.nextInt();
		int a[] =new int[n];
		
		for(int i = 0; i<n; i++) {
			a[i]= sc.nextInt();
		}
		
		int k = sc.nextInt();
		
		int t[][] = new int[n+1][k+1];
		
		for(int i = 0; i<=n; i++) {
			t[i][0] = 1;
		}
		for(int i = 1; i<=k; i++) {
			t[0][i] = 0;
		}
		
		for(int i =1; i<=n; i++) {
			for(int j = 1; j<=k; j++) {
				if(j>=a[i-1]) {
					t[i][j] = t[i-1][j]+t[i][j-a[i-1]];
				}
				else {
					t[i][j] = t[i-1][j];
				}
			}
		}
		
		System.out.println(t[n][k]);

	}

}
