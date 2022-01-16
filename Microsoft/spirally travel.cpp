#include <bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
class Solution
{   
    public: 
    //Function to return a list of integers denoting spiral traversal of matrix.
    vector<int> spirallyTraverse(vector<vector<int> > a, int r, int c) 
    {
        // code here 
        vector<int> v;
        
        int k=0,l=0;
        while(k<r && l<c){
            for(int i=l;i<c;i++)
                v.push_back(a[k][i]);
            k++;
            for(int i=k;i<r;i++)
                v.push_back(a[i][c-1]);
            c--;
            if(k<r){
            for(int i=c-1;i>=l;i--)
                v.push_back(a[r-1][i]);
            r--;
            }
            if(l<c){
            for(int i=r-1;i>=k;i--)
                v.push_back(a[i][l]);
            l++;
            }
        }
        return v;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin>>t;
    
    while(t--) 
    {
        int r,c;
        cin>>r>>c;
        vector<vector<int> > matrix(r); 

        for(int i=0; i<r; i++)
        {
            matrix[i].assign(c, 0);
            for( int j=0; j<c; j++)
            {
                cin>>matrix[i][j];
            }
        }

        Solution ob;
        vector<int> result = ob.spirallyTraverse(matrix, r, c);
        for (int i = 0; i < result.size(); ++i)
                cout<<result[i]<<" ";
        cout<<endl;
    }
    return 0;
}  // } Driver Code Ends