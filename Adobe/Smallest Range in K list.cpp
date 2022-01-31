#define p pair <int, pair<int, int>>
class Solution{
    public:
    pair<int,int> findSmallestRange(int arr[][N], int n, int k)
    {
          priority_queue <p, vector <p>, greater <p>> pq;
          int mx = INT_MIN, mn, range = INT_MAX;
          int low, high;
          
          for (int i = 0; i < k; i ++) {
              pq.push({arr[i][0], {i, 0}});
              mx = max (mx, arr[i][0]);
          }
          
          while (1) {
              p temp = pq.top();
              pq.pop();
              
              mn = temp.first;
              if (range > mx - mn) {
                  range = mx - mn;
                  low = mn;
                  high = mx;
              }
              
              int i = temp.second.first;
              int j = temp.second.second;
              
              if (j == n-1) break;
              
              pq.push({arr[i][j+1], {i, j + 1}});
              mx = max (mx, arr[i][j+1]);
          }
          
          return {low, high};
          
    }
};