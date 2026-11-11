class Solution {
public:
    vector<int> sums;
    bool possible = false;
    void dfs(int index,vector<int>& nums,int target) {
        if (index < 0) {
            unordered_set<int> s;
            for (int n : sums) {
                s.insert(n);
            }

            if (s.size() == 1) {
                possible = true;
            }
            return;
        }


        if (possible) {
            return;
        }

        for (int i = 0; i < sums.size();i++) {
            if (sums[i] + nums[index] > target) {
                continue;
            }
            sums[i]+=nums[index];
            dfs(index-1,nums,target);
            sums[i]-=nums[index];

            // If this bucket was empty and it didn't work, stop trying other empty buckets!
            if (sums[i] == 0) {
                break; 
            }
        }

    }
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());

        sums.assign(k,0);
        int t = 0;

        for (int i : nums) {
            t+=i;
        }

        if (t % k != 0) {
            return false;
        }

        if (nums.back() > t / k) return false;

        dfs(nums.size()-1,nums,t /k);
        return possible;
    }
};