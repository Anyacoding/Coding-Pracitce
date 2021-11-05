class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();
        vector<int> target(m + n);
        merge(nums1.begin(), nums1.end(), nums2.begin(), nums2.end(), target.begin());
        int l = 0, r = target.size() - 1;
        int mid = (l + r) / 2;
        if ((m + n) % 2 == 0) {
            //偶数序列
            return (double)(target[mid] + target[mid + 1]) / 2;
        } else {
            //奇数序列
            return target[mid];
        }
    }
};
