#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Twitter {
public:
    unordered_set<int> user[501];
    vector<pair<int,int>> tweet;

    Twitter() {

    }

    void postTweet(int userId, int tweetId) {
        tweet.push_back({tweetId, userId});
    }

    vector<int> getNewsFeed(int userId) {
        int t = tweet.size();
        vector<int> ans;

        for(int i = t - 1; i >= 0 && ans.size() < 10; i--){
            if(tweet[i].second == userId || user[userId].count(tweet[i].second)){
                ans.push_back(tweet[i].first);
            }
        }

        return ans;
    }

    void follow(int followerId, int followeeId) {
        user[followerId].insert(followeeId);
    } 
    void unfollow(int followerId, int followeeId) {
        user[followerId].erase(followeeId);
    } 
};

// Technique:
// Design
// Hashing
// Reverse Traversal

// Approach:
// Store every tweet along with its
// author in chronological order.
//
// Maintain a hash set of followees
// for every user.
//
// While fetching the news feed,
// traverse the tweets in reverse
// chronological order and collect
// tweets posted by the user or any
// of their followees until 10 tweets
// are obtained.
//
// Follow and unfollow operations
// are performed using hash set
// insertion and deletion.

// TC:
// postTweet() : O(1)
// getNewsFeed() : O(T)
//   T = Total No. of tweets
// follow() : O(1)
// unfollow() : O(1)

// SC: O(T + U²)
// T = Total No. of tweets
// U = Maximum No. of users (501)

// Verdict: Accepted

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */

int main(){
    // Main Function placeholder for testing
    return 0;
}