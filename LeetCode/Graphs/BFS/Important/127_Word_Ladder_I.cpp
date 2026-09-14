#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        queue<pair<string, int>> q;
        q.push({beginWord, 1});

        unordered_set<string> st(wordList.begin(), wordList.end());

        int m = wordList[0].size();

        st.erase(beginWord);

        while(!q.empty()){
            string word = q.front().first;
            int step = q.front().second;
            q.pop();

            if(word == endWord) return step;

            for(int i = 0; i < m; i++){
                char original = word[i];

                for(char ch = 'a'; ch <= 'z'; ch++){
                    word[i] = ch;

                    if(st.find(word) != st.end()){
                        st.erase(word);
                        q.push({word, step + 1});
                    }
                }

                word[i] = original;
            }
        }

        return 0;
    }
};

// Technique:
// BFS
// Shortest Path
// Hash Set

// Approach:
// Start BFS from `startWord` with
// step count 1.
//
// For every word, change each
// character to all possible letters
// from 'a' to 'z'.
//
// If the transformed word exists
// in the word list, erase it from
// the set and add it to the queue.
// Erasing immediately prevents the
// same word from being processed
// multiple times.
//
// Since BFS explores level by level,
// the first time `targetWord` is
// reached gives the shortest
// transformation sequence.
//
// Return 0 if the target word cannot
// be reached.

// TC: O(N × M × 26)
// N = Number of words
// M = Length of each word

// SC: O(N)

// Verdict: Optimal

int main(){
    // Main Function placeholder for testing
    return 0;
}