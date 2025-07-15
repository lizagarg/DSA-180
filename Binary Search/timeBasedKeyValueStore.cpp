class TimeMap {
public:
    unordered_map<string, vector<pair<int, string>>> mp;
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        mp[key].push_back({timestamp, value});
    }
    
    string get(string key, int timestamp) {
        string ans;
        auto &v= mp[key]; //got the vector of pairs
        int s=0, e= v.size()-1;

        while(s<=e) {
            int mid= s+(e-s)/2;
            if(v[mid].first <=timestamp) {
                //possible answer
                ans= v[mid].second;
                s=mid+1;
            } else e=mid-1;
        }
        return ans;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */