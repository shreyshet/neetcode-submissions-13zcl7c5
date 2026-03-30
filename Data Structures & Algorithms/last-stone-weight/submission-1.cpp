class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        if (stones.size() < 2) return stones[0];

        priority_queue<int> maxheap;
        
        for(auto i: stones){
            maxheap.push(i);
        }
        
        while (maxheap.size() > 1){
            cout << maxheap.top() << " ";
            int x = maxheap.top();
            maxheap.pop();
            int y = maxheap.top();
            maxheap.pop();
            if (x == y) continue;
            maxheap.push(x-y);
        }
        cout << endl << " size " <<  maxheap.size() << " ";
        if (maxheap.empty()) return 0;
        
        return maxheap.top();
    }
};
