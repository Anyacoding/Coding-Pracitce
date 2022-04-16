法一：树状数组，美妙的数据结构

class NumArray {
public:
    vector<int> Bit, _nums;

    int lowBit(int x) {
        return x & -x;
    }

    void add(int index, int value) {
        while (index < Bit.size()) {
            Bit[index] += value;
            index += lowBit(index);
        }
    }

    int getSum(int index) {
        int ans = 0;
        while (index >= 1) {
            ans += Bit[index];
            index -= lowBit(index);
        }
        return ans;
    }

    NumArray(vector<int>& nums): _nums(nums), Bit(nums.size() + 1) {
        for (int i = 0; i < nums.size(); ++i) {
            add(i + 1, nums[i]);
        }
    }
    
    void update(int index, int val) {
        add(index + 1, val - _nums[index]);
        _nums[index] = val;
    }
    
    int sumRange(int left, int right) {
        return getSum(right + 1) - getSum(left);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */
