法1：直接归并两个数组然后找中位数，时间复杂度O(m + n)
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

法2：二分查找法，查找第k位元素，时间复杂度O(log(m + n))
class Solution {
public:
    int getKthNumber(const vector<int>& nums1, const vector<int>& nums2, int k) {
        int m = nums1.size();
        int n = nums2.size();
        int index1 = 0, index2 = 0;
        while (true) {
            //当nums1不够长时有可能会出现这种情况
            //例如nums1[] nums2[1, 2, 3]
            //例如nums1[1,2] nums2[3,4]
            if (index1 == m) {
                return nums2[index2 + k - 1];
            }
            //当nums2不够长时有可能会出现这种情况
            //例如nums1[1, 2, 3] nums2[]
            if (index2 == n) {
                return nums1[index1 + k - 1];
            }
            //当nums1和nums2都足够长时会出现这种情况
            //k是在不断变化的，当k == 1时即可退出循环
            if (k == 1) {
                return min(nums1[index1], nums2[index2]);
            }
            //以下是正常情况
            int newIndex1 = min(index1 + k / 2 - 1, m - 1);
            int newIndex2 = min(index2 + k / 2 - 1, n - 1);
            int val1 = nums1[newIndex1];
            //就是这个地方nums2写成nums1，找半天找不出这个bug
            int val2 = nums2[newIndex2];
            if (val1 <= val2) {
                k = k - (newIndex1 - index1 + 1);
                index1 = newIndex1 + 1;
            } else {
                k = k - (newIndex2 - index2 + 1);
                index2 = newIndex2 + 1;
            }
        }
    }
    
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int totalSize = nums1.size() + nums2.size();
        //如果数组总长为奇数，则中位数在正中间、
        if (totalSize % 2 == 1) {
            //假设有一个函数能返回我指定的任意第k位数字
            //这里的第k位是从1开始数的，是我们日常认知中的的第k位
            return getKthNumber(nums1, nums2, (totalSize + 1) / 2);
        } 
        else {
            //如果数组总长为偶数，则中位数为中间两个数的平均数
            return (getKthNumber(nums1, nums2, totalSize / 2) + getKthNumber(nums1, nums2, totalSize / 2 + 1)) / 2.0;
        }
    }
};
