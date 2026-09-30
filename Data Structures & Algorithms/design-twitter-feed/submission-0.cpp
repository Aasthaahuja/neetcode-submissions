class Twitter {
public:
    unordered_map<int, vector<pair<int, int>>> tweets;
    unordered_map<int, unordered_set<int>> following;
    int timer = 0;
    Twitter() {
        
    }
    
    void postTweet(int userId, int tweetId) {
        timer++;
        tweets[userId].push_back({timer, tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        priority_queue<
            tuple<int, int, int, int>
        > pq;
        following[userId].insert(userId);
        for (int person : following[userId]) {

            if (!tweets[person].empty()) {

                int index = tweets[person].size() - 1;

                auto [time, tweetId] = tweets[person][index];

                pq.push({
                    time,
                    tweetId,
                    person,
                    index
                });
            }
        }

        vector<int> result;
        while (!pq.empty() && result.size() < 10) {

            auto [time, tweetId, person, index] = pq.top();

            pq.pop();

            result.push_back(tweetId);

            // Add next older tweet from same person
            if (index > 0) {

                index--;

                auto [nextTime, nextTweetId] =
                    tweets[person][index];

                pq.push({
                    nextTime,
                    nextTweetId,
                    person,
                    index
                });
            }
        }
        return result;
    }
    
    void follow(int followerId, int followeeId) {
        following[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        if (followerId != followeeId) {
            following[followerId].erase(followeeId);
        }
    }
};
