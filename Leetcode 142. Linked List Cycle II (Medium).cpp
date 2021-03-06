/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 typedef ListNode * List;
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        bool flag = true;
        //定义快慢指针
        List fast, slow;
        fast = head;
        slow = head;
        //快指针走两步，慢指针每次走一步
        while (fast != nullptr && fast->next != nullptr) {
           fast = fast->next->next;
           slow = slow->next;
           if (fast == slow) {
               flag = false;
               break;
           }     
        }
        //flag = true,说明没有找到环
        if (flag) {
            return nullptr;
        }
        else {
            slow = head;
            while (fast != slow) {
                fast = fast->next;
                slow = slow->next;
            }
        }
        return slow;
    }
};

