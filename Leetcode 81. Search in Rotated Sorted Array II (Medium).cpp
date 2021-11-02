class Solution {
public:
    bool search(vector<int>& nums, int target) {
        if (nums.size() == 0) {
            return false;
        }
        int left = 0, right = nums.size() - 1;
        while (left <= right) {
            if (nums[left] == target) {
                return true;
            } else if (nums[left] != target) {
                ++left;
            }
            if (nums[right] == target) {
                return true;
            } else if (nums[right] != target) {
                --right;
            }
        }
        return false;
    }
};
