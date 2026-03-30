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
    void reorderList(ListNode* head) {
        ListNode* i = head;
        //cout << i->val << endl;
        while(i->next and i->next->next){
            ListNode* j = i;
            cout << i->val << endl; 
            while(j->next->next){
                j = j->next;
            }
            ListNode* k = i->next;
            //cout << i->val << " " << j->val << " " << k->val << endl;
            i->next = j->next;
            j->next = nullptr;
            i->next->next = k;
            i = k;
        }
    }
};
