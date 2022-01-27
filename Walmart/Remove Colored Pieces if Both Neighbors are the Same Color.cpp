class Solution {
public:
    bool winnerOfGame(string s) {
        int a=0,  b=0 , i=0, n=s.length();
        while(i<n){
          if(i<n-1 && s[i]==s[i+1]){
            char c = s[i];
            int cnt=0;
            while(s[i] == c)
            {
              cnt++;
              i++;
            }
            if(s[i-1] == 'A') a+= (cnt>2)? cnt-2: 0;
            else b+= (cnt>2)? cnt-2: 0;
          }
          else i++;
        }

        if(b>=a) return false;
        return true;
    }
};