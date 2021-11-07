class Solution {
public:
    int quickSelect(int i, int j, vector<int>& nums) {
        int l = i;
        int r = j;
        while (l < r) {
            //当碰到nums[r]的值大于基准值nums[i]停下
            while (l < r && nums[r] <= nums[i]) {
                --r;
            }
            //当碰到nums[l]的值小于基准值nums[i]停下
            while (l < r && nums[l] >= nums[i]) {
                ++l;
            }
            if (l < r) {
            int temp = nums[r];
            nums[r] = nums[l];
            nums[l] = temp;
            }
        }
        //此时l == r
        int temp = nums[i];
            nums[i] = nums[l];
            nums[l] = temp;
        return l;
    }
    int findKthLargest(vector<int>& nums, int k) {
        //题目的意思是降序排列的第k个元素
        //等价于升序排列的倒数第k个元素
        //我这里选择的让数组降序排列，所以target = k - 1
        int l = 0, r = nums.size() - 1, target = k - 1;
        while (l < r) {
            int mid = quickSelect(l, r, nums);
            if (mid == target) {
                return nums[mid];
            }
            else if (mid > target) {
                r = mid - 1;
            }
            else {
                //mid < target
                l = mid + 1;
            }
        }
        return nums[l];
    }
};
