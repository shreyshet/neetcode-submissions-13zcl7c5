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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        ListNode* dummy = new ListNode();
        ListNode* cur = dummy;
        int carry = 0;
        int val = 0;
 
        while(l1 or l2 or carry){
            int a = (l1)?l1->val:0;
            int b = (l2)?l2->val:0;
            val = (a + b + carry)%10;
            carry = (a + b + carry)/10;
            cur->next = new ListNode(val);
            cur = cur->next;
            l1 = (l1)?(l1->next):nullptr;
            l2 = (l2)?(l2->next):nullptr;
        }
        ListNode* ret = dummy->next;
        delete dummy;

        
        return ret;
    }
};
