
class Twitter {
    unordered_map<int, unordered_set<int>> following;
    unordered_map<int, vector<int>> posts;
public:
    Twitter() {}
    
    void postTweet(int userId, int tweetId) {
        posts[userId].push_back(tweetId);
    }

    void get_posts(int user, priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>>& pq) {
        vector<int>& post = posts[user];
        for (int i = 0; i < post.size(); i++) {
            pq.push({i, post[i]});
            if (pq.size() > 10) pq.pop();
        }
    }
    
    vector<int> getNewsFeed(int userId) {
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>>pq;
        get_posts(userId, pq);
        for (int c : following[userId]) {
            get_posts(c, pq);
        }
        vector<int> result(pq.size());
        int n = result.size() - 1;
        while (n >= 0) {
            result[n] = pq.top().second; pq.pop();
            n--;
        }
        return result;    
    }
    
    void follow(int followerId, int followeeId) {
        following[followerId].insert(followeeId);        
    }
    
    void unfollow(int followerId, int followeeId) {
        following[followerId].erase(followeeId);
    }
};
