#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    vector<int> asteroidCollision(vector<int> &asteroids){
        stack<int> st;

        for(int ast : asteroids){
            if(ast > 0) st.push(ast);
            else if(ast < 0){
                while(!st.empty() && st.top() > 0 && st.top() < abs(ast)) st.pop();
                if(!st.empty() && st.top() > 0 && st.top() > abs(ast)) continue;
                else if(!st.empty() && st.top() > 0 && st.top() == abs(ast)){
                    st.pop();
                    continue;
                }

                st.push(ast);
            }
        }

        int n = st.size();
        vector<int> ans(n);

        while(n--){
            ans[n] = st.top();
            st.pop();
        }

        return ans;
    }
};

// Technique:
// Monotonic Stack (Simulation)

// Approach:
// Traverse the asteroids one by one.
// Positive asteroids are moving right,
// so push them into the stack.
// When a negative asteroid is encountered,
// collisions are possible only with
// positive asteroids already present in the stack.
// Remove all smaller positive asteroids
// that collide and explode.
// If a larger positive asteroid exists,
// the current asteroid explodes.
// If both asteroids have equal size,
// both explode.
// Otherwise, push the current asteroid
// into the stack.
// Finally, extract the remaining asteroids
// from the stack and return them.

// TC: O(N)
// N => Number of asteroids
// Each asteroid is pushed and popped at most once

// SC: O(N)
// N => Stack storage in the worst case

// Verdict: Optimal

int main(){
    // Main Function placeholder for testing
    return 0;
}