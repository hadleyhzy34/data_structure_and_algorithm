//
//  355_design_twitter.cpp
//  leetcode_hashtable
//
//  Created by Hadley on 20.08.20.
//  Copyright © 2020 Hadley. All rights reserved.
//

#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <stack>
#include <cstring>
#include <queue>
#include <functional>
#include <numeric>
#include <map>
using namespace std;

class Twitter {
public:
    /** Initialize your data structure here. */
    Twitter() {
        
    }
    
    /** Compose a new tweet. */
    void postTweet(int userId, int tweetId) {
        dq.push_front(make_pair(userId, tweetId));
    }
    
    /** Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent. */
    vector<int> getNewsFeed(int userId) {
        vector<int>res;
        fap[userId].push_back(userId);
        for(auto it=dq.begin();it!=dq.end();it++){
            vector<int> flist=fap[userId];
            if(find(flist.begin(), flist.end(),it->first)!=flist.end()){
                res.push_back(it->second);
            }
        }
        return res;
    }
    
    /** Follower follows a followee. If the operation is invalid, it should be a no-op. */
    void follow(int followerId, int followeeId) {
        fap[followerId].push_back(followeeId);
    }
    
    /** Follower unfollows a followee. If the operation is invalid, it should be a no-op. */
    void unfollow(int followerId, int followeeId) {
        fap[followerId].erase(std::remove(fap[followerId].begin(), fap[followerId].end(), followeeId),fap[followerId].end());
    }
private:
    //userID->tweetID
    unordered_map<int, vector<int>>map;
    //follower->followee
    unordered_map<int, vector<int>>fap;
    //time-sequence tweets, pair first to be userid, pair second to be tweetid
    deque<pair<int, int>>dq;
    
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */
