class KthLargest {
    std::priority_queue<int, std::vector<int>, std::greater<int>> minHeap;
    int kval;
public:
    KthLargest(int k, vector<int>& nums) : kval(k) {
        for (auto n: nums){
            add(n);
        }
    }
    
    int add(int val) {
        minHeap.push(val);
        
        // Ensure heap size never exceeds K
        if (minHeap.size() > kval) {
            minHeap.pop();
        }
        return minHeap.empty() ? -1 : minHeap.top();
    }
};
