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
    ListNode* n;
    int len = 0;
    Solution(ListNode* head): n(head) {
        while (head != nullptr) {
            ++len;
            head = head->next;
        }
    }
    
    int getRandom() {
        int pos = (rand() % len) + 1;
        ListNode* temp = n;
        while (pos != len && temp != nullptr) {
            temp = temp->next;
            ++pos;
        }
        return temp->val;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */
