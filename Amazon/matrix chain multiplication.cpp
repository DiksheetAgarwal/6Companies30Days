#include<bits/stdc++.h>
using namespace std; 
 
 int func(int p[], int i,int j, vector<vector<it>> &dp){
        if(i==j)
            return 0;
        int m = INT_MAX;
        if(dp[i][j]) return dp[i][j];
        for(k=i;k<j;k++){
            int count = func(p,i,k,dq)+
                        func(p,k+1,j,dq)+ 
                        a[i-1]*a[k]*a[j];
            if(count<m)
                m = count;
        }
        
        dp[i][j]= m;
        return dp[i][j];
    }
    int matrixChainOrder(int p[], int n){
        vector<vector<int>>dq;
        int min =  func(p,1,n-1,dq)
    }