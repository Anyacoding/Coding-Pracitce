class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        //独立数出现之前，奇偶位数上出现的都是同样的数
        //独立数出现之后，偶奇位数上出现的都是同样的数
        //独立数一定在某个奇数位置上
        if (nums.size() == 1) {
            return nums[0];
        }
        int l = 0, r = nums.size() - 1;
        while (l < r) {
            int mid = (l + r) / 2;
            if (nums[mid] == nums[mid - 1]) {
                if ((mid + 1) % 2 == 0) {
                    //说明独立数出现在mid之后
                    l = mid + 1;
                } else if ((mid + 1) % 2 != 0) {
                    //说明独立数出现在mid之前
                    r = mid - 2;
                }
            } else if (nums[mid] == nums[mid + 1]) {
                if ((mid + 1) % 2 != 0) {
                    //说明独立数出现在mid之后
                    l = mid + 2;
                } else if ((mid + 1) % 2 == 0) {
                    //说明独立数出现在mid之前
                    r = mid - 1;
                }
            } else {
                //前后都没有匹配的数，当前即为独立数
                return nums[mid];
            }
        }
        return nums[l];
    }
};
