class TimeMap {
public:
    unordered_map<string,vector<pair<int,string>>> key_values;
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
       key_values[key].push_back({timestamp,value}); 
    }
    
    string get(string key, int timestamp) {
        vector<pair<int,string>>& arr = key_values[key];

        int l = 0;
        int r = arr.size()-1;
        string b = "";

        while (l <= r) {
            int mid = l + ((r-l)/2);

            if (arr[mid].first == timestamp) {
                return arr[mid].second;
            }

            if (arr[mid].first < timestamp) {
                b = arr[mid].second;
                l = mid+1;
            } else {
                r = mid-1;
            }
        }

        return b;
    }
};
