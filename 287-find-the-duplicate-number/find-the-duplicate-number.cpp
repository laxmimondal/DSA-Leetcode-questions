class Solution {
public:
    int findDuplicate(vector<int>& nums) {
 int left = 0;
        int right = nums.size() - 1;
      
        // Use binary search to find the duplicate
        while (left < right) {
            // Find the midpoint of the current search range
            int mid = left + (right - left) / 2;

            // Count how many numbers are less than or equal to 'mid'
            int count = 0;
            for (int num : nums) {
                if (num <= mid) {
                    count++;
                }
            }

            // If the count is more than 'mid', then the duplicate is in the left half
            if (count > mid) {
                right = mid; // Search in the left half
            } else {
                left = mid + 1; // Search in the right half
            }
        }

        // 'left' is the duplicate number
        return left;
    }
};