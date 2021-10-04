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

typedef ListNode* List;
    ListNode* sortList(ListNode* head) {
        return mergesort(head);
    }
private:
    List mergesort(List head) {
        //如果第一或第二个结点是空结点，则不用归并，直接返回
        if (head == NULL || head->next == NULL) {
            return head;
        }
        List fast, slow, fasttp, l, r;//设定快慢指针来找中间结点；
        fast = slow = head;
        fasttp = head->next->next;
        while (fasttp != NULL && fasttp->next != NULL) {
            slow = slow->next;
            fasttp = fasttp->next->next;
        }
        //此时slow->next即为中间结点
        //对右边进行归并
        r = mergesort(slow->next);
        //一个链表结束的标志是nullptr，所以这里进行cut操作，否则会出现一个循环的死
        slow->next = NULL;
        l = mergesort(head);
        //最后将左右两段进行一个合并
        return merge(l, r);
    }

    List merge(List l, List r) {
        List temphead = new ListNode;
        List p = temphead;
        while (l && r) {
            if(l->val <= r->val) {
                p->next = l;
                l = l->next;
            }
            else {
                p->next = r;
                r = r->next;
            }
            p = p->next;
        }
        //当左边有剩余时
        if (l != NULL) {
            p->next = l;
        }
        //当右边有剩余时
        if (r != NULL) {
            p->next = r;
        }
        return temphead->next;
    }
};
