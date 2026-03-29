class Twitter {

    int time;
    unordered_map<int, unordered_set<int>> follows;  //user ans whom all he follows
    unordered_map<int, vector<pair<int,int>>> tweets; 
public:
    Twitter() {
        time = 0;
        
    }
    
    void postTweet(int userId, int tweetId) {
        tweets[userId].push_back({time++, tweetId});
    }



    
    vector<int> getNewsFeed(int userId) {
        vector<int> res;

        priority_queue<vector<int>> pq;
        // {time, tweetId, userId, index}

        // include self
        follows[userId].insert(userId);

        for (int user : follows[userId]) {  //insert latest tweet of all followers
            if (tweets[user].size() > 0) {
                int idx = tweets[user].size() - 1;
                auto [t, id] = tweets[user][idx];
                pq.push({t, id, user, idx});
            }
        }

        while (!pq.empty() && res.size() < 10) {
            auto top = pq.top(); pq.pop();

            int t = top[0];
            int id = top[1];
            int user = top[2];
            int idx = top[3];

            res.push_back(id);

            if (idx > 0) {  //latest second last tweet push 
                auto [nt, nid] = tweets[user][idx - 1];
                pq.push({nt, nid, user, idx - 1});
            }
        }

        return res;

        
    }
    








    void follow(int followerId, int followeeId) {
        if (followerId != followeeId)
            follows[followerId].insert(followeeId);
        
    }
    
    void unfollow(int followerId, int followeeId) {
        follows[followerId].erase(followeeId);
        
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