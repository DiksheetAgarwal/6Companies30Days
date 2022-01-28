#include<bits/stdc++.h>
using namespace std;
const int MAX_DIGITS = 5;

int missingNumber(const string& str);

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string str;
        cin>>str;
        cout << missingNumber(str)<<endl;
    }
	return 0;
}
// } Driver Code Ends


/* You are required to complete this function
which return the required missing number
if present else return -1*/
int missingNumber(const string& str)
{
    // Code here
    string str1="";
    if(str[0]=='0')
        str1=str.substr(1,str.length()-1);
    else
        str1=str;
    // str="";
    vector<vector<int>>v;
    for(int i=1;i<=6;i++)
    {
        vector<int>vec;
        v.push_back(vec);
    }
    for(int i=1;i<=6;i++)
    {
        int window=i;
        for(int j=0;j<str1.length();)
        {
            string s=str1.substr(j,window);
            j+=window;
            int num=stoi(s);
            if(num%10==8 && j<str1.length() && ((str1.substr(j,window).length()==1&&str1.substr(j,window)[0]!='9') ||(str1.substr(j,window)[0]=='1' && str1.substr(j,window)[1]=='0')))
                window++;
            if((int)log10(num+1)>(int)log10(num))
                window++;
            // int num=stoi(s);
            v[i-1].push_back(num);
        }
    }
    int count=0,flag=0;
    // for(int i=0;i<6;i++)
    // {
    //     for(int j=0;j<v[i].size();j++)
    //         cout<<v[i][j]<<" ";
    //     cout<<endl;
    // }
    for(int i=0;i<6;i++)
    {
        vector<int>vec;
        vec=v[i];
        int c=0;
        int num=0;
        int flag=0;
        for(int i=0;i<vec.size()-1;i++)
        {
            if(vec[i]+1==vec[i+1])
                continue;
            else if(vec[i]+2==vec[i+1]){
                num=vec[i]+1;
                c++;
            }
            else{
                flag=1;
            }
        }
        if(c==1 && flag!=1)
            return num;
    }
    return -1;
}