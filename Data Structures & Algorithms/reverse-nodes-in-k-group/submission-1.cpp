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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* checklength = head;
        int n = 0;
        while(checklength){
            n++;
            checklength = checklength->next;
        }
        cout << n << " " << endl;

       
        ListNode* cur = head;
        ListNode* dummy = new ListNode(0, head);
        ListNode* lastgrouptail = dummy;
         
        for(int i = 0; i < n/k; i++)
        {   
            ListNode* grouphead = cur;
            ListNode* prev = nullptr;
            ListNode* next = nullptr;
            for(int j =0; j<k; j++)
            {   
                next = cur->next;
                cur->next = prev;
                prev = cur;
                cur = next;
            }
            lastgrouptail->next = prev;
            grouphead->next =cur;
            lastgrouptail = grouphead;
        }
        return dummy->next;
    }
};
