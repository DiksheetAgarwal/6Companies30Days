class Solution {
public:
    bool subsetSum (vector <int> &ans, int target, int i) {
        if (i == ans.size())    return !target;
        
        int temp = ans[i];
        if (subsetSum (ans, target, i+1)) return 1;
        
        ans[i] = -temp;
        if (subsetSum (ans, target-temp, i+1))    return 1;
        
        ans[i] = temp;
        return false;
    }
    
    vector<int> recoverArray(int n, vector<int>& sums) {
        int mn = INT_MAX;
        for (int &i: sums)  mn = min (mn, i);
        for (int &i: sums)  i -= mn;
        
        multiset <int> s (sums.begin(), sums.end()), temp;
        vector <int> ans;
        for (int i = 0; i < n; i ++) {
            temp.clear();
            
            int second_mn = *next(s.begin());
            ans.push_back(second_mn);
            
            while (s.size()) {
                int first = *s.begin();
                temp.insert(first);
                s.erase(s.begin());
                s.erase(s.find(first + second_mn));
            }
            swap (s,temp);
        }
        
        subsetSum (ans, -mn, 0);
        return ans;
    }
};