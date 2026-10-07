class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        //has temp and index
        stack<pair<int,int>> t;
        vector<int> res(temperatures.size(),0);
        for (int i = 0 ; i < temperatures.size();i++) {

            while (!t.empty() && temperatures[i] > t.top().first) {
                res[t.top().second] = i - t.top().second;
                t.pop();
            }

            t.push({temperatures[i],i});

        }

        return res;


    }
};
