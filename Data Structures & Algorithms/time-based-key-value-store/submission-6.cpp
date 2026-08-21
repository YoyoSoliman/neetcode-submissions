class TimeMap {
private:
    unordered_map<string,vector<pair<int,string>>> timeBasedKey;

public:
    TimeMap() {}
    
    void set(string key, string value, int timestamp) {
        timeBasedKey[key].push_back({timestamp,value});
    }
    
    string get(string key, int timestamp) {
        
        if (timeBasedKey.find(key) == timeBasedKey.end()) {
            return "";
        }
        int l = 0;
        int r = timeBasedKey[key].size()-1;
        string res = "";

        while (l <= r) {
            int mid = l + (r-l)/2;

            if (timeBasedKey[key][mid].first <= timestamp) {
                res = timeBasedKey[key][mid].second;
                l = mid + 1;
            } else {
                r = mid-1;
            }

        }

        return res;
    }
};
