class Solution {
public:
    // Find the pivot index where the array is rotated
    int findPivot(vector<int>& nums) {
        int n = nums.size();
        int start = 0;
        int end = n - 1;

        while (start < end) {
            int mid = start + (end - start) / 2;

            if (nums[mid] > nums[end]) {
                start = mid + 1;
            } else {
                end = mid;
            }
        }

        return start;
    }

    // Binary search implementation
    int binarysearch(vector<int>& arr, int s, int e, int key) {
        int start = s;
        int end = e;

        while (start <= end) {
            int mid = start + (end - start) / 2;
            if (arr[mid] == key) {
                return mid;
            } else if (arr[mid] < key) {
                start = mid + 1;
            } else {
                end = mid - 1;
            }
        }

        return -1;
    }

    // Search function to find the key in a rotated sorted array
    int search(vector<int>& nums, int key) {
        int n = nums.size();
        int pivot = findPivot(nums);

        // If the key is in the right sorted part
        if (key >= nums[pivot] && key <= nums[n - 1]) {
            return binarysearch(nums, pivot, n - 1, key);
        } 
        // If the key is in the left sorted part
        else {
            return binarysearch(nums, 0, pivot - 1, key);
        }
    }
};