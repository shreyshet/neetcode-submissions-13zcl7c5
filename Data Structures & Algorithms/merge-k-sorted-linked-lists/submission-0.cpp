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
        ListNode* dummy = new ListNode();
        ListNode* curr = dummy;
        int flag = 1;
        while(flag){
            int val = 1001;
            flag = 0;
            int j = 0;
            for(int i = 0; i < lists.size(); i++){
                if(lists[i]){
                    flag = (1 || flag);
                    //val = min(lists[i]->val,val);
                    cout << lists[i]->val << " ";
                    if(lists[i]->val <= val){
                        val = lists[i]->val;
                        j = i;
                    }
                    
                }
                else{
                    flag = (0 || flag);
                }
                
            }
            if(flag == 1){
                lists[j] = lists[j]->next;
                curr->next = new ListNode(val);
            }
            //cout << endl << " complete 1 round " << endl;
            curr = curr->next;
        }
        ListNode* res = dummy->next;
        delete dummy;
        return res;
    }
};
