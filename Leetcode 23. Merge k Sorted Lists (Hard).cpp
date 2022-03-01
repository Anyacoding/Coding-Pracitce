法一：这里采取的是空间换时间的做法，建立优先队列快速取出最小元素然后组成新的链表
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.size() == 0) return nullptr;
        multiset<int> heap;
        for (auto it : lists) {
            while (it != nullptr) {
                heap.insert(it->val);
                it = it->next;
            }
        }
        if (heap.empty()) return nullptr;
        ListNode* head = new struct ListNode();
        ListNode* ans = head;
        for (auto it = heap.begin(); it != heap.end(); ++it) {
            head->val = *it;
            if (it != --heap.end())
            head->next = new struct ListNode();
            head = head->next;
        }
        return ans;
    }
};
