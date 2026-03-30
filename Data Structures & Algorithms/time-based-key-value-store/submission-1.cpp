class TimeMap {
    unordered_map <string, unordered_map<int,string>> ktv;
public:
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        this->ktv[key][timestamp] = value; 
    }
    
    string get(string key, int timestamp) {
        for(int i = timestamp; i>=0; i--){
            auto it = this->ktv[key].find(i);
            //std::cout << it->second;
            if( it != this->ktv[key].end()){
                return it->second; 
            }
            
        }
        return "";
    }
};
