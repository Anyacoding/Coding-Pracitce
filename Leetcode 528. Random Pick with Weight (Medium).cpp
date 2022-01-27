class Solution {
public:
    vector<int> sum;
    Solution(vector<int>& w): sum(w) {
        //sum前缀和数组
        for (int i = 1; i < w.size(); ++i) {
            sum[i] = sum[i - 1] + w[i];
        }
    }
    
    int pickIndex() {
        int pos = rand() % sum.back();
        return upper_bound(sum.begin(), sum.end(), pos) - sum.begin();
    }
};
