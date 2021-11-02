//法一：暴力搜索法时间复杂度O(N)，显然不是最优解
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

//方法二：二分查找法 时间复杂度O(logn)最优解
class Solution {
public:
    bool search(vector<int>& nums, int target) {
        if (nums.size() == 0) {
            return false;
        }
        int start = 0, end = nums.size() - 1;
        while (start <= end) {
            int mid = (start + end) / 2;
            if (nums[mid] == target) {
                return true;
            }
            //左右区间至少有一个区间递增，遇到特殊情况判断不了，就首尾都改变一下位置
            //例如 nums=[3,1,2,3,3,3,3](已旋转过) 就判断不了是左区间递增还是右区间递增
            if (nums[mid] == nums[start] && nums[mid] == nums[end]) {
                ++start;
                --end;
            } else if (nums[mid] >= nums[start]) {
                //左区间递增
                if (nums[start] <= target && target < nums[mid]) {
                    //target可能在[start, mid - 1]区间中
                    end = mid - 1;
                } else {
                    //target可能在[mid + 1, end]区间中
                    start = mid + 1;
                }

            } else {
                //右区间递增
                if (nums[end] >= target && target > nums[mid]) {
                    //target可能在[mid + 1, end]区间中
                    start = mid + 1;
                } else {
                    //target可能在[start, mid - 1]区间中
                    end = mid - 1;
                }
            }
        }
        return false;
    }
};
