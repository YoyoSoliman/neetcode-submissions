class KthLargest {
public:

    priority_queue<int> maxH;
    int k;
    vector<int> nums;

    KthLargest(int k, vector<int>& nums) {
        this->k = k;
        this->nums = nums;
        for (int j = 0; j < nums.size(); j++) {
            maxH.push(nums[j]);
        }
    }
    
    int add(int val) {
        maxH.push(val);

        int largestKth;
        vector<int> add_back; 

        //gets the largestKth
        for (int i = 0; i < k; i++) {
            largestKth = maxH.top();
            add_back.push_back(largestKth);
            maxH.pop();
        }

        for (int i = 0; i < add_back.size();i++) {
            maxH.push(add_back[i]);
        }
        return largestKth;

    }
};
