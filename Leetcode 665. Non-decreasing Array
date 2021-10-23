class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        int mark = -1;
        //数组个数小于两个一定可以
        if (nums.size() < 3) {
            return true;
        }
        //修改机会，只能使用一次
       bool flag = nums[0] <= nums[1] ? true : false;
       //遇到不符合非递减数列的情况，即nums[i] > nums[i + 1]时，有两种修改方案
       //1.缩小nums[i]的值，但有可能会破坏之前已经排好的非递减序列
       //2.放大nums[i + 1]的值，可能会导致之后的数列原来不是递减的序列变为递减的序列，引起误差
       //具体采取那种方案需要综合考虑前后两个数，即瞻前顾后
       for (int i = 1; i < nums.size() - 1; i++) {
           if (nums[i] > nums[i + 1]) {
               if (flag) {
                   if (nums[i + 1] >= nums[i - 1]) {
                       nums[i] = nums[i + 1];
                   }
                   else if (nums[i + 1] < nums[i - 1]) {
                       nums[i + 1] = nums[i];
                   }
                   flag = false;
               }
               else 
               return false;
           }

       }
       return true;
    }
};
