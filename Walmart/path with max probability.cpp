class Solution {
public:

    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        vector<unordered_map<int, double>> graph(n);
        for(int i = 0; i < edges.size(); ++i) {
            graph[edges[i][0]][edges[i][1]] = succProb[i];
            graph[edges[i][1]][edges[i][0]] = succProb[i];
        }
        vector<double> ps(n, 0.0); 
        ps[start] = 1.0;
        
        queue<int> q;
        q.push(start);
        double res = 0;
        while(!q.empty()) {
            int nd = q.front();
            q.pop();
            for(auto& it: graph[nd]) {
                int next = it.first;
                double pro = it.second;
                if(ps[nd] * pro > ps[next]) {
                    q.push(next);
                    ps[next] = ps[nd] * pro;
                }
            }
        }
        
        return ps[end];
    }

};