class Twitter {
public:

    std::unordered_map<int,std::unordered_set<int>> whoUserFollows;
    std::unordered_map<int,std::vector<std::pair<int,int>>> userTweets;
    int count = 0;
    
    Twitter() {
    }
    
    void postTweet(int userId, int tweetId) {
        userTweets[userId].push_back({count,tweetId});
        count++;

    }
    
    vector<int> getNewsFeed(int userId) {
        whoUserFollows[userId].insert(userId);
        vector<int> res;

        using Element = std::tuple<int, int, int, int>;
        std::priority_queue<Element> maxHeap;

        for (int followeeId : whoUserFollows[userId]) {
            if (userTweets.contains(followeeId)){
                int index = userTweets[followeeId].size() - 1;
                int c = userTweets[followeeId][index].first;
                int tid = userTweets[followeeId][index].second;

                maxHeap.emplace(c,tid,followeeId,index);

            }
        }

        while (!maxHeap.empty() && res.size() < 10) {
            auto[c,tid,followeeId,index] = maxHeap.top();
            maxHeap.pop();

            res.push_back(tid);
            if (index > 0) {
                int nextc = userTweets[followeeId][index-1].first;
                int nexttid = userTweets[followeeId][index-1].second;
                maxHeap.emplace(nextc,nexttid,followeeId,index-1);
            }
        }

        return res;
    }
    
    void follow(int followerId, int followeeId) {  
        whoUserFollows[followerId].insert(followeeId);

    }
    
    void unfollow(int followerId, int followeeId) {
        if (whoUserFollows[followerId].contains(followeeId)) {
            whoUserFollows[followerId].erase(followeeId);
        }
    }
};
