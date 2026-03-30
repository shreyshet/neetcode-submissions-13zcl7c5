class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> ret;
        unordered_map<int, int> um;
        for(auto i: nums){
            um[i]++;
        }
        // 2. Copy elements to a vector of pairs
    vector<pair<int, int>> vec(um.begin(), um.end());

    // 3. Sort the vector using a lambda function to compare by the 'value' (second element)
    sort(vec.begin(), vec.end(), [](const pair<int, int>& a, 
                                        const pair<int, int>& b) {
        return a.second > b.second; // Sort in descending order by value
    });

    // Output the sorted results
    // cout << "Sorted by value (descending):" << std::endl;
    // for (const auto& pair : vec) {
    //    cout << pair.first << ": " << pair.second << std::endl;
    // }

    for(int i =0; i< k; i++){
        ret.push_back(vec[i].first);
    }
    return ret;

    }
};