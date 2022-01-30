class Solution {
public:
    
    bool check(vector<int>weights, int days, int size){
        int cnt =1;
        
        int i =0,n = weights.size();
        int sumtillnow = 0;
        while(i<n){
            if(weights[i]+sumtillnow <= size){
                sumtillnow+=weights[i];
                i++;
            }
            else if(weights[i]>size)  return false;
            else{
                cnt++;
                sumtillnow = weights[i];
                i++;
            }
        }
        
        if(cnt >days)   return false;
        return true;
    }
    
    int shipWithinDays(vector<int>& weights, int days) {
        int sum=0;
        
        int l =1, h = 1000000009;
        int ans = INT_MAX;
        while(l<=h){
            int mid = (l+h)/2;
            if(check(weights, days, mid)){
                // ans = min(ans, mid);
                h = mid-1;
            }
            else l = mid +1;           
        }
        
        return l;
    }
};