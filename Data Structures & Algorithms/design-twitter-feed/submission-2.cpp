class Twitter {
public:
    unordered_map<int,unordered_set<int>> followers;
    unordered_map<int,vector<vector<int>>> userPosts;
    int count;
    Twitter() {
        count = 0;
    }
    
    void postTweet(int userId, int tweetId) {
        userPosts[userId].push_back({count,tweetId,userId});
        count++;
    }
    
    vector<int> getNewsFeed(int userId) {
        priority_queue<pair<vector<int>,int>> maxH;
        vector<int> res;

        if (!userPosts[userId].empty()) {
            maxH.push({userPosts[userId].back(),userPosts[userId].size() - 1});
        }

        if (followers.find(userId) != followers.end()) {
            for (int user : followers.at(userId)) {
                if (!userPosts[user].empty()){
                    maxH.push({userPosts[user].back(),userPosts[user].size() - 1});
                }
            }
        }

        while (!maxH.empty() && res.size() < 10) {
            int tweetIndex = maxH.top().second;
            vector<int> tweetInfo = maxH.top().first;
            maxH.pop();
            res.push_back(tweetInfo[1]);
            if (tweetIndex - 1 >= 0) {
                maxH.push({userPosts[tweetInfo[2]][tweetIndex - 1],tweetIndex-1});
            }

        }

        return res;

    }
    
    void follow(int followerId, int followeeId) {
        followers[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        followers[followerId].erase(followeeId);
    }
};
