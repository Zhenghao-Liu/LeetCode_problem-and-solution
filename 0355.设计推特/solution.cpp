//注意有关注自己，取消关注自己没有关注的人等奇怪的测试案例
class Twitter {
    unordered_map<int,unordered_set<int>> following;
    unordered_map<int,vector<pair<int,int>>> posting;
    int time;
public:
    /** Initialize your data structure here. */
    Twitter() {
        following.clear();
        posting.clear();
        time=0;
    }
    
    /** Compose a new tweet. */
    void postTweet(int userId, int tweetId) {
        if (following.find(userId)==following.end())
            following.insert({userId,{}});
        posting[userId].push_back(make_pair(tweetId,time));
        ++time;
    }
    
    /** Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent. */
    vector<int> getNewsFeed(int userId) {
        if (following.find(userId)==following.end())
            return {};
        vector<pair<int,int>> all_tweet;
        if (posting.find(userId)!=posting.end())
            for (pair<int,int> &i:posting.at(userId))
                all_tweet.push_back(i);
        for (int i:following.at(userId))
            if (posting.find(i)!=posting.end())
                for (pair<int,int> &j:posting.at(i))
                    all_tweet.push_back(j);
        sort(all_tweet.begin(),all_tweet.end(),[](const pair<int,int> &A,const pair<int,int> &B){
            return A.second>B.second;
        });
        vector<int> ans;
        ans.reserve(10);
        int all_tweet_size=all_tweet.size();
        for (int i=0;i<all_tweet_size && i<10;++i)
            ans.push_back(all_tweet.at(i).first);
        return ans;
    }
    
    /** Follower follows a followee. If the operation is invalid, it should be a no-op. */
    void follow(int followerId, int followeeId) {
        if (followerId==followeeId)
            return;
        following[followerId].insert(followeeId);
        if (following.find(followeeId)==following.end())
            following.insert({followeeId,{}});
    }
    
    /** Follower unfollows a followee. If the operation is invalid, it should be a no-op. */
    void unfollow(int followerId, int followeeId) {
        if (following.find(followerId)==following.end())
            return;
        auto p=following.at(followerId).find(followeeId);
        if (p!=following.at(followerId).end())
            following.at(followerId).erase(p);
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
