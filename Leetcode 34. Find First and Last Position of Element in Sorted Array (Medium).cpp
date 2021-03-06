//方法一： 暴力解法捏，时间复杂度O(1),虽然能通过但不合题意
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        //初始化ans数组
        vector<int> ans(2, -1);
        bool flag1 = true, flag2 = true;
        int l = 0, r = nums.size() - 1;
        while (l <= r && (flag1 || flag2)) {
            if (nums[l] == target) {
                ans[0] = l;
                flag1 = false;
            }
            else if (nums[l] != target) {
                ++l;
            }
            if (nums[r] == target) {
                ans[1] = r;
                flag2 = false;
            }
            else if (nums[r] != target) {
                --r;
            }
        }
        return ans;
    }
};

方法二：二分查找法(二分查找好多细节，以后再也不敢看不起二分查找了呜呜)
class Solution {
public:
int findLastPosition(const vector<int>& nums, const int target)
{
    int l = 0, r = nums.size() - 1;
    
    while (l < r) {
        //这里是个大坑，不这样写就是死循环呜呜，保证当只有两个数取mid时，mid能取到右边的数，不然无法退出循环
        int mid = (l + r) / 2 + 1;
        if (nums[mid] < target) {
            //targrt可能在区间[mid + 1, right]中
            l = mid + 1;
        } else if (nums[mid] == target) {
            //在当前位置的右手边还可能有target，故继续在[mid, right]中查找
            l = mid;
        } else {
            //nums[mid] > target
            //targrt可能在区间[left, mid - 1]中
            r = mid - 1;
        }
    }
    //退出循环时保证l == r
    //因为findFirstPosition已经帮我们判断nums中是否有target了，所以这里不用判断
    return l;
}

int findFirstPosition(const vector<int>& nums, const int target)
{
    int l = 0, r = nums.size() - 1;
    while (l < r) {
        int mid = (l + r) / 2;
        if (nums[mid] < target) {
            //targrt可能在区间[mid + 1, right]中
            l = mid + 1;
        } else if (nums[mid] == target) {
            //在当前位置的左手边还可能有target，故继续在[left, mid]中查找
            r = mid;
        } else {
            //nums[mid] > target
            //targrt可能在区间[left, mid - 1]中
            r = mid - 1;
        }
    }
    //退出循环时保证l == r
    //但有可能在nums中其实根本没有target，故需要验证
    if (nums[l] != target) {
        return -1;
    } else {
        //存在target，好耶
        return l;
    }
}

    vector<int> searchRange(vector<int>& nums, int target) {
        int lenth = nums.size();
        if (lenth == 0) {
            return vector<int> {-1, -1};
        }
        int FirstPosition = findFirstPosition(nums, target);
        if (FirstPosition == -1) {
            return vector<int> {-1, -1};
        }
        int LastPosition = findLastPosition(nums, target);
        return vector<int> {FirstPosition, LastPosition};
    }
    
};

