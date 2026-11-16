class Solution {
public:
    string reorganizeString(string s) {
        unordered_map<char,int> charFreq;
        priority_queue<pair<int,char>> max_heap;

        for (char c : s) {
            charFreq[c]++;
        }

        for (const auto& [key,value]: charFreq) {
            max_heap.push({value,key});
        }

        string res = "";
        while (!max_heap.empty()) {
            if (!res.empty() and res.back() == max_heap.top().second) {
                char c = max_heap.top().second;
                int count = max_heap.top().first;
                max_heap.pop();

                if (max_heap.empty()) {
                    break;
                } else {
                    res+=max_heap.top().second;
                    int new_c = max_heap.top().second;
                    int new_count = max_heap.top().first;
                    max_heap.pop();

                    if (new_count > 1) {
                        max_heap.push({new_count-1,new_c});
                    }
                }

                max_heap.push({count,c});
            } else {
                res+=max_heap.top().second;
                int new_c = max_heap.top().second;
                int new_count = max_heap.top().first;
                max_heap.pop();

                if (new_count > 1) {
                    max_heap.push({new_count - 1,new_c});
                }
            }
        }
        if (res.size() != s.size()) {
            return "";
        }
        return res;
    }
};