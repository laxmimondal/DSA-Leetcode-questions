class Solution {
public:
    int connectTwoGroups(std::vector<std::vector<int>>& cost) {
        memo.clear();
        
        // Get sizes of both groups
        size1 = cost.size();
        size2 = cost[0].size();
        
        // Recursively find minimum cost
        return dfs(cost, 0, 0);
    }
    
private:
    std::unordered_map<int, int> memo; // Memoization table
    int size1, size2; // Sizes of the two groups
    
    int dfs(std::vector<std::vector<int>>& cost, int i, int mask) {
        // Check if all points in the first group are connected
        if (i == size1) {
            int result = 0;
            // Check if any point in the second group is not connected
            for (int j = 0; j < size2; ++j) {
                if (!(mask & (1 << j))) {
                    // Find the minimum cost to connect unconnected points in the second group
                    int min_cost = INT_MAX;
                    for (int k = 0; k < size1; ++k) {
                        min_cost = std::min(min_cost, cost[k][j]);
                    }
                    result += min_cost;
                }
            }
            return result;
        }
        
        // Check if this state has been memoized
        int key = (i << 12) | mask;
        if (memo.find(key) != memo.end()) {
            return memo[key];
        }
        
        // Try connecting point i in the first group to each point in the second group
        int min_cost = INT_MAX;
        for (int j = 0; j < size2; ++j) {
            min_cost = std::min(min_cost, cost[i][j] + dfs(cost, i + 1, mask | (1 << j)));
        }
        
        // Memoize the result
        memo[key] = min_cost;
        
        return min_cost;
    }
};