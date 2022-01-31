class Solution {
  public:
    int LIS(vector <int> &a) {
        int n = a.size();
        
        vector <int> res;
        for (int i = 0; i < n; i ++) {
            auto id = lower_bound(res.begin(), res.end(), a[i]);
            if (id == res.end())    res.push_back(a[i]);
            else    *id = a[i];
        }
            
        return res.size();
    }
    
    int minInsAndDel(int A[], int B[], int N, int M) {
        unordered_map <int, int> mp;
        for (int i = 0; i < M; i ++)    mp[B[i]] ++;
        
        vector <int> a;
        for (int i = 0; i < N; i ++)
            if (mp.find(A[i]) != mp.end())    a.push_back(A[i]);
        return N + M - 2 * LIS (a);
    }
};