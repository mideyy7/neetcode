struct User {
    int userId;
    unordered_set<int> following{};
    unordered_set<int> followers{};
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>> feed;
    User(int userId) : userId(userId) {}

    void follow(int id) {
        following.insert(id);
    }
    void unfollow(int id) {
        following.erase(id);
    }
    void follower(int id) {
        followers.insert(id);
    }
    void unfollower(int id) {
        followers.erase(id);
    }

    const unordered_set<int>& get_followers() const {
        return followers;
    }
    
    void push_feed(int d, int f, int timestamp) {
        feed.push({timestamp, {d, f}});
    }
    vector<int> get_feed() {
        int count = 0;
        vector<pair<int, pair<int, int>>> store;
        vector<int> result;
        while (!feed.empty() && count < 10) {
            pair<int,pair<int, int>> p = feed.top(); feed.pop();
            if (p.second.first == userId || following.find(p.second.first) != following.end()) {
                result.push_back(p.second.second);
                store.push_back(p);
                count++;
            } 
        }
        for (auto s : store) {
            feed.push(s);
        }

        return result;
    }
};



class Twitter {
private:
    unordered_map<int, User*> twt;
    int timestamp{};

public:
    Twitter() {
    }

    User* getOrMake(int is) {
        auto it = twt.find(is);
        if (it == twt.end()) {
            User* n = new User(is);
            twt[is] = n;
        }
        return twt[is];
    }
    
    void postTweet(int userId, int tweetId) {
        User* user = getOrMake(userId);
        user->push_feed(userId, tweetId, timestamp);
        unordered_set<int> followers = user->get_followers();
        for (int c : followers) {
            User* profile = twt[c];
            profile->push_feed(userId, tweetId, timestamp);
        }
        timestamp++;
    }
    
    vector<int> getNewsFeed(int userId) {
        if (twt.find(userId) == twt.end()) return {};
        return twt[userId]->get_feed();
    }
    
    void follow(int followerId, int followeeId) {
        User* user1 = getOrMake(followerId);
        User* user2 = getOrMake(followeeId);
        user1->follow(followeeId);
        user2->follower(followerId);
    }
    
    void unfollow(int followerId, int followeeId) {
        User* user1 = getOrMake(followerId);
        User* user2 = getOrMake(followeeId);
        user1->unfollow(followeeId);
        user2->unfollower(followerId);
        
    }
};
