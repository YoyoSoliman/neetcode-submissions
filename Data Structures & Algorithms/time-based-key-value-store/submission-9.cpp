class TimeMap {
public:
    //Unordered_map will point id's to a vector of pairs that include the time and the value 
    unordered_map<string,vector<pair<int,string>>> m;

    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        m[key].push_back({timestamp,value});
    }
    
    string get(string key, int timestamp) {
        int l = 0;
        int r = m[key].size() - 1;
        string res = "";
        while (l <= r) {
            int mid = l + ((r-l)/2);

            if (m[key][mid].first <= timestamp) {
                res = m[key][mid].second;
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }

        return res;
    }
};
