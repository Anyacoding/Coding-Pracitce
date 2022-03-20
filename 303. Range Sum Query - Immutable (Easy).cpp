法一：前缀和预处理
class NumArray {
public:
    vector<int> sum;
    NumArray(vector<int>& nums): sum(nums.size(), 0) {
        for (int i = 0; i < nums.size(); ++i) {
            if (i == 0) sum[i] = nums[i];
            else sum[i] = sum[i - 1] + nums[i];
        }
    }
    
    int sumRange(int left, int right) {
        if (left == 0) return sum[right];
        return sum[right] - sum[left - 1];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */
