class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int ans = 0;
        int Max = INT_MIN;
        for (int i = 0; i < arr.size(); ++i) {
            Max = max(Max, arr[i]);
            if (Max == i) ++ans;
        }
        return ans;
    }
};
