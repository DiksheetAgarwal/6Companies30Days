class Solution {
public:
    int longestMountain(vector<int>& arr) {
        int count=0,i=0;
        int m=0;
        int f=0;
        while(i< arr.size()){
            if(i<arr.size()-1 && arr[i]<arr[i+1]){
                while(i<arr.size()-1 && arr[i]<arr[i+1]){
                    i++;
                    count++;
                    f=1;
                } 
                while(i<arr.size()-1 && arr[i]>arr[i+1]){
                    i++;
                    count++;
                    f=2;
                }
                count++;
                if(f==2)
                m= max(m,count);
                count=0;
            }
            else i++;           
        }
        return m;
    }
};