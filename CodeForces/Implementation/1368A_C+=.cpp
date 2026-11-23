#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main(){
    int t; cin >> t;

    while(t--){
        long long a, b, n;
        cin >> a >> b >> n;

        if(a > b) swap(a, b);

        int ans = 0;

        while(b <= n){
            a += b;
            swap(a, b);
            ans++;
        }

        cout << ans << endl;
    }

    return 0;
}

// Technique:
// Greedy

// Approach:
// Keep a <= b by swapping when necessary.
// Add the smaller value to the larger value
// until either variable exceeds n.

// TC: O(log N)
// Values grow at least as fast as Fibonacci numbers.

// SC: O(1)

// Verdict: Optimal