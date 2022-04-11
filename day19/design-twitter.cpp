class Twitter {
    unordered_map<int,unordered_set<int>>followerMap;  
    vector<pair<int,int>> posts;
public:
    Twitter() {
        
    }
    
    void postTweet(int userId, int tweetId) {
       posts.push_back({userId, tweetId});
        followerMap[userId].insert(userId);
    }
    
    vector<int> getNewsFeed(int userId) {
       vector<int> ret;
        for(int i = posts.size() - 1; i >= 0 && ret.size() < 10; i--) {
            pair<int,int> post = posts[i];
            if (followerMap[userId].count(post.first)) ret.push_back(post.second);
        }
        return ret;
    }
    
    void follow(int followerId, int followeeId) {
        followerMap[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        followerMap[followerId].erase(followeeId);
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */