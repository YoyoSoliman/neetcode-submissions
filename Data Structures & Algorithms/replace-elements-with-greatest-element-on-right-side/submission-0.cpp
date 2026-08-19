class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {

        vector<int> res(arr.size(),0);

        res[res.size()-1] = -1;
        int m = arr[arr.size()-1];

        for (int i = arr.size()-2;i >=0;i--) {
            m = max(m,arr[i+1]);
            res[i] = m;
        }

        return res;
    }
};