#define ll long long
class Solution
{
  public:
    int kvowelwords(int N, int K) {
        
        ll MOD = 1000000007;
        
        ll dp [N+1][K+1] = {0};
        
        for (int i = 0; i <= N; i ++) {
            for (int j = 0; j <= K; j ++) {
                if (!i) dp[i][j] = 1;
                else {
                    dp[i][j] = (dp[i-1][K] * 21) % MOD;
                    if (j)  dp[i][j] = (dp[i][j] + (dp[i-1][j-1] * 5) % MOD) % MOD;
                }
            }
        }
        
        return dp[N][K];
    }
};