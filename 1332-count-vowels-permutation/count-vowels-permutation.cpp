class Solution {
public:
    int countVowelPermutation(int n) {
        constexpr int MOD = 1e9 + 7;
        // Create a 2D vector to store the counts of strings
        std::vector<std::vector<long long>> dp(n + 1, std::vector<long long>(5, 0));
        
        // Base case: strings of length 1
        for (int i = 0; i < 5; ++i) {
            dp[1][i] = 1;
        }
        
        // Fill the dp array
        for (int i = 2; i <= n; ++i) {
            dp[i][0] = (dp[i - 1][1] + dp[i - 1][2] + dp[i - 1][4]) % MOD; // 'a' can be followed by 'e' or 'i' or 'u'
            dp[i][1] = (dp[i - 1][0] + dp[i - 1][2]) % MOD; // 'e' can be followed by 'a' or 'i'
            dp[i][2] = (dp[i - 1][1] + dp[i - 1][3]) % MOD; // 'i' can be followed by 'e' or 'o'
            dp[i][3] = dp[i - 1][2]; // 'o' can only be followed by 'i'
            dp[i][4] = (dp[i - 1][2] + dp[i - 1][3]) % MOD; // 'u' can be followed by 'i' or 'a'
        }
        
        // Calculate the total count of strings
        long long count = 0;
        for (int i = 0; i < 5; ++i) {
            count = (count + dp[n][i]) % MOD;
        }
        
        return static_cast<int>(count);
    }
};