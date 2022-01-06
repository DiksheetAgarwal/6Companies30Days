class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        int a = str1.length();
        int b = str2.length();
        
        int x = __gcd(a,b);
        
        string ans = str1.substr(0,x);
        
        string temp1 ="";
        for(int i=0;i<a/x;i++)
            temp1+= ans;
        string temp2 ="";
        
        for(int i=0;i<b/x;i++)
            temp2 += ans;
        
        if(temp1 == str1 && temp2 == str2)
            return ans;
        
         
         return "";
    }
};