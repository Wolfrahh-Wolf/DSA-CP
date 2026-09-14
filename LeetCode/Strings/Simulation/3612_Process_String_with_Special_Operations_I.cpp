#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    string processStr(string s){
        string ans = "";

        for(char ch : s){
            if(ch == '*'){
                if(!ans.empty()) ans.pop_back();
            }    
            else if(ch == '#') ans += ans;
            else if(ch == '%') reverse(ans.begin(), ans.end());
            else ans.push_back(ch); 
        }

        return ans;
    }
};

// Technique:
// Simulation

// TC: O(F)
// F => Length of the final generated string

// SC: O(F)

// Verdict: Optimal

int main(){
    // Main Function placeholder for testing
    return 0;
}