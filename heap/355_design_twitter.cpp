class Twitter {
public:
  /** Initialize your data structure here. */
  Twitter() {}

  /** Compose a new tweet. */
  void postTweet(int userId, int tweetId) {
    dq.push_front(make_pair(userId, tweetId));
    // cout<<userId<<" "<<tweetId<<endl;
  }

  /** Retrieve the 10 most recent tweet ids in the user's news feed. Each item
   * in the news feed must be posted by users who the user followed or by the
   * user herself. Tweets must be ordered from most recent to least recent. */
  vector<int> getNewsFeed(int userId) {
    vector<int> res;
    fap[userId].push_back(userId);
    for (auto it = dq.begin(); it != dq.end(); it++) {
      vector<int> flist = fap[userId];
      if (find(flist.begin(), flist.end(), it->first) != flist.end()) {
        res.push_back(it->second);
      }
      if (res.size() == 10)
        break;
    }
    // for(auto x:res){
    //     cout<<x<<" ";
    // }
    // cout<<endl;
    return res;
  }

  /** Follower follows a followee. If the operation is invalid, it should be a
   * no-op. */
  void follow(int followerId, int followeeId) {
    fap[followerId].push_back(followeeId);
    // cout<<followerId<<" "<<followeeId<<endl;
  }

  /** Follower unfollows a followee. If the operation is invalid, it should be a
   * no-op. */
  void unfollow(int followerId, int followeeId) {
    fap[followerId].erase(
        std::remove(fap[followerId].begin(), fap[followerId].end(), followeeId),
        fap[followerId].end());
  }

private:
  // follower->followee
  unordered_map<int, vector<int>> fap;
  // time-sequence tweets, pair first to be userid, pair second to be tweetid
  deque<pair<int, int>> dq;
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */

class Twitter {
public:
  /** Initialize your data structure here. */
  Twitter() { time = 0; }

  /** Compose a new tweet. */
  void postTweet(int userId, int tweetId) {
    t[userId].push_back({time++, tweetId});
  }

  /** Retrieve the 10 most recent tweet ids in the user's news feed. Each item
   * in the news feed must be posted by users who the user followed or by the
   * user herself. Tweets must be ordered from most recent to least recent. */
  vector<int> getNewsFeed(int userId) {
    std::vector<int> res;
    priority_queue<pair<int, int>> pq;

    for (auto x : t[userId]) {
      pq.push(x);
    }
    for (auto user : ftf[userId]) {
      for (auto x : t[user]) {
        pq.push(x);
      }
    }
    while (!pq.empty() && res.size() < 10) {
      res.push_back(pq.top().second);
      pq.pop();
    }
    return res;
  }

  /** Follower follows a followee. If the operation is invalid, it should be a
   * no-op. */
  void follow(int followerId, int followeeId) {
    if (followerId != followeeId) {
      ftf[followerId].insert(followeeId);
    }
  }

  /** Follower unfollows a followee. If the operation is invalid, it should be a
   * no-op. */
  void unfollow(int followerId, int followeeId) {
    if (followerId != followeeId) {
      ftf[followerId].erase(followeeId);
    }
  }

private:
  // follower->followee
  unordered_map<int, set<int>> ftf;
  // tweet states: user id->(time, tweet id)
  unordered_map<int, vector<pair<int, int>>> t;
  // time
  long time;
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */
