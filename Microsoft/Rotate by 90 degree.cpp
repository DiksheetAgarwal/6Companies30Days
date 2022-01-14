//Initial Template for C



#include<stdio.h>

 // } Driver Code Ends
//User function Template for C


void chang(int *x , int *y){
    int temp;
    temp = *y;
    *y = *x;
    *x = temp;
}

void rotate(int n,int a[][n])
{
    //code here
    for(int i=0;i<n;i++){
        for(int j=0;j<n/2;j++){
            chang(&a[i][j], &a[i][n-j-1]);
        }
    }
        
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i>j){
                chang(&a[i][j], &a[j][i]);
            }
        }
    }
}

// { Driver Code Starts.

int main()
{
    int t;
    scanf("%d",&t); 
    while(t--)
    {
        int n;
        scanf("%d",&n);
        int a[n][n];
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
                scanf("%d",&a[i][j]);
        }
        rotate(n,a);
        for (int i = 0; i < n; ++i)
        {
            for(int j=0; j<n; j++)
                printf("%d ",a[i][j]);
            printf("\n");
        }
    }
    return 0;
}

  // } Driver Code Ends