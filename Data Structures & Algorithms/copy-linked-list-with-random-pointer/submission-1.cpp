
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node* curr = head;
        
        unordered_map< Node* , Node*> um;
        um[nullptr] = nullptr;

        while(curr){ 
            Node* temp = new Node(curr->val);
            um[curr] = temp;
            curr = curr->next;
        }

        curr = head;

        while(curr){ 
            Node* temp = um[curr];
            temp->next = um[curr->next];
            temp->random = um[curr->random];
            curr = curr->next;
        }

        return um[head];
    }
};
