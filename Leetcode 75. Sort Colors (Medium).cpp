class Solution {
public:
    void quickSort(vector<int>& nums, int l, int r) {
        if (l > r) return;
        int i = l;
        int j = r;
        while (i < j) {
            //右边的哨兵移动，直到找到一个小于temp的值停下
            while (i < j && nums[j] >= nums[l])
            --j;
            //左边的哨兵移动，直到找到一个大于temp的值停下
            while (i < j && nums[i] <= nums[l])
            ++i;
            if (i < j) {
                int mid;
                mid = nums[i];
                nums[i] = nums[j];
                nums[j] = mid;
            }
        }
        //此时i == j
        int temp;
        temp = nums[l];
        nums[l] = nums[i];
        nums[i] = temp;
        //对左边进行快排
        //注意，这里l不能替换为0,同理r不能替换为nums.size() - 1，这样不符合递归并导致Stack-verflow，仔细想一想就能知道为什么
        quickSort(nums, l, i - 1);
        //对右边进行快排
        quickSort(nums, i + 1, r);
    }
    void sortColors(vector<int>& nums) {
        quickSort(nums, 0, nums.size() - 1);
    }
};
