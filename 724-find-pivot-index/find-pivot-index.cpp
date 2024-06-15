class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        for(int i = 0; i < n; i++){
            sum = sum +nums[i];
        }
        int cs = 0;
        for (int x = 0; x < n ; x++){
             int ls = cs;
             int rs = sum - cs- nums[x];
             cs += nums[x];
             // Check if the current index is the pivot index
            if (ls == rs) {
                return x;
            } 
            // Update the current sum
            
        }
   // Return -1 if no pivot index is found
        return -1;
    }
};