class LRUCache {
    unordered_map<int,pair<int,list<int>::iterator>> um;
    list<int> dll;
    int cap;
public:
    LRUCache(int capacity) {
        cap = capacity;
    }
    
    int get(int key) {        
        if (um.find(key) == um.end()) return -1;
        // Move accessed key to the back (Most Recently Used)
        dll.splice(dll.end(), dll, um[key].second);
        return um[key].first;
    }
    
    void put(int key, int value) {
        if (um.find(key) != um.end()) {
            // Update value and move to back
            dll.splice(dll.end(), dll, um[key].second);
            um[key].first = value;
            return;
        }
        if (dll.size() == cap) {
            // Evict the Least Recently Used (front of list)
            um.erase(dll.front());
            dll.pop_front();
        }
        dll.push_back(key);
        um[key] = {value, --dll.end()};
    }
};
