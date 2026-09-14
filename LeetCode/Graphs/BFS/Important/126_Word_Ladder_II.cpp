#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution{
private:
    void dfs(string word, string &beginWord, unordered_map<string, int> &mpp, 
             vector<vector<string>> &ans, vector<string> &seq){

        if(word == beginWord){
            reverse(seq.begin(), seq.end());
            ans.push_back(seq);
            reverse(seq.begin(), seq.end());

            return;
        }

        int step = mpp[word];

        for(int i = 0; i < beginWord.size(); i++){
            char original = word[i];

            for(char ch = 'a'; ch <= 'z'; ch++){
                word[i] = ch;

                if(mpp.find(word) != mpp.end() && mpp[word] + 1 == step){
                    seq.push_back(word);
                    dfs(word, beginWord, mpp, ans, seq);
                    seq.pop_back();
                }
            }

            word[i] = original;
        }
    }

public:
    vector<vector<string>> findLadders(string beginWord, string endWord,
                                         vector<string> &wordList) {
        
        int len = beginWord.size();

        unordered_set<string> st(wordList.begin(), wordList.end());
        unordered_map<string, int> mpp;

        vector<vector<string>> ans;
        vector<string> seq;

        queue<string> q;
        q.push(beginWord);
        st.erase(beginWord);

        int steps = 1;
        mpp[beginWord] = steps;

        while(!q.empty()){
            string word = q.front();
            steps = mpp[word];
            q.pop();

            for(int i = 0; i < len; i++){
                char original = word[i];

                for(char ch = 'a'; ch <= 'z'; ch++){                    
                    word[i] = ch;

                    if(st.find(word) != st.end()){
                        q.push(word);
                        mpp[word] = steps + 1;
                        st.erase(word);
                    }
                }

                word[i] = original;
            }
        }

        if(mpp.find(endWord) == mpp.end()) return {};

        seq.push_back(endWord);

        dfs(endWord, beginWord, mpp, ans, seq);

        return ans;
    }
};

// Technique:
// BFS + DFS
// Shortest Path
// Backtracking

// Approach:
// Use BFS to build a shortest-distance
// map from `beginWord` to every reachable
// word.
//
// Generate all possible one-character
// transformations and store their
// shortest level in `mpp`.
//
// After BFS, use DFS from `endWord`
// backwards. At every step, choose a
// word whose distance is exactly one
// less than the current word.
//
// Build each sequence in reverse and
// reverse it when `beginWord` is reached
// to obtain the required transformation
// sequence.

// TC:
// BFS: O(N × L × 26)
// DFS: O(No of ShortestS Sequence × L)

// SC:
// O(N × L)

// Verdict: Optimal

int main(){
    // Main Function placeholder for testing
    return 0;
}