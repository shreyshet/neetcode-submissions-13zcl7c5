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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* start = head;
        int i = 0;
        
        while(head){
            i++;
            cout << " " << i << " " << head->val << " "<< endl;
            head = head->next;
        }
        head = start;
        int total = i;
        // i is the number of nodes
        cout << "total nodes : " << total << " " << endl;

        if((total-n) == 0){
            return start->next;
        }

        i = 0;
        for(int i = 0; i<(total-1);i++){
            if((i+1)==(total-n)){
                head->next = (head->next->next);
                break;
            }
            head = head->next;
        }
        //cout << " remove " << head->next->val;
        
        
        //cout << "Remove node after this : "<< i << " "<< endl;
        
        return start;
    }
};
