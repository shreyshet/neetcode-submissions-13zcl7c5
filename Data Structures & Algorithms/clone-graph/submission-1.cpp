/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
     Node* cloneGraph(Node* node) {
        if (!node) return nullptr;

        // Map: Key = Original Node, Value = Its Deep Copy
        unordered_map<Node*, Node*> oldToNew;

        // 1. Create the first clone and store it in the map
        oldToNew[node] = new Node(node->val);

        stack<Node*> st;
        st.push(node);

        while (!st.empty()) {
            Node* curr = st.top();
            st.pop();

            // 2. Iterate through original neighbors
            for (Node* neighbor : curr->neighbors) {
                // If we haven't cloned this neighbor yet:
                if (oldToNew.find(neighbor) == oldToNew.end()) {
                    // Create the clone and add to map
                    oldToNew[neighbor] = new Node(neighbor->val);
                    // Push original to stack to process its neighbors later
                    st.push(neighbor);
                }
                
                // 3. Link the CLONED version of curr to the CLONED version of neighbor
                // (This builds the edges in the new graph)
                oldToNew[curr]->neighbors.push_back(oldToNew[neighbor]);
            }
        }

        return oldToNew[node];
    }
};
