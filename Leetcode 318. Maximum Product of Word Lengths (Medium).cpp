法一：位运算哈希表映射，妙得很
class Solution {
public:
    int maxProduct(vector<string>& words) {
        int ans = 0;
        unordered_map<int, int> hash;
        for (const auto &word : words) {
            int mask = 0, size = word.size();
            for (const auto &c : word) {
                mask |= 1 << (c - 'a');
            }
            hash[mask] = max(hash[mask], size);
            for (const auto &[h_mask, h_size] : hash) {
                if ((mask & h_mask) == 0) {
                    ans = max(ans, size * h_size);
                }
            }
        }
        return ans;
    }
};
