class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
       
        unordered_map<int, int> m;
        for(auto i: arr)  m[((i%k)+k)%k]++;
        
        
        for(auto i: m){
            if(i.first == 0 && i.second %2 !=0)
                return false;
            else if(!i.first ==0){
                int x = k - i.first;
                if(m[x]!= i.second)
                    return false;
            }
        }
        
        return true;
    }
};