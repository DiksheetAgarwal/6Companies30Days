class Solution {
public:
    int divide(int dividend, int divisor) {
        if(dividend == INT_MIN && divisor == -1) return INT_MAX;
        
        
        
        int a = labs(dividend), b = labs(divisor);
        // if(dividend == INT_MIN) a= INT_MAX+1;
        
        int ans=0;
        while (a >= b) {
            long temp = b, m = 1;
            while (temp << 1 <= a) {
                temp <<= 1;
                m <<= 1;
            }
            a -= temp;
            ans += m;
        }
        
            return (dividend>0) == (divisor>0)? ans: -ans;
        
    }
};