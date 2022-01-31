class Solution {
public:
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
        vector <pair<int, int>> engg;
        for (int i = 0; i < n; i ++)
            engg.push_back({efficiency[i], speed[i]});
        
        sort (rbegin(engg), rend(engg));
        
        long totalspeed = 0, performance;
        long maxperformance = INT_MIN;
        
        priority_queue <int, vector <int>, greater<int>> pq;
        for (auto x: engg) {
            long e = x.first, s = x.second;
            
            pq.push(s);
            totalspeed += s;
            
            if (pq.size() > k) {
                totalspeed -= pq.top();
                pq.pop();
            }
            
            performance = totalspeed * e;
            maxperformance = max (maxperformance, performance);
        }
        
        return maxperformance % 1000000007;
    }
};