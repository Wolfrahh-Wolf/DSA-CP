#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution{
private:
    int numberOfGasStationsRequired(long double dist, vector<int> &arr){
        int n = arr.size();
        int cnt = 0;

        for(int i = 1; i < n; i++){
            int numberInBetween = (arr[i] - arr[i - 1]) / dist;

            if((arr[i] - arr[i - 1]) == (dist * numberInBetween)){
                numberInBetween--; // NOTE: In case of exact divisibility reduce cnt by 1
            }

            cnt += numberInBetween;
        }

        return cnt;
    }

public:
    long double minimiseMaxDistance(vector<int> &arr, int k){
        int n = arr.size();

        long double low = 0;
        long double high = 0;

        for(int i = 0; i < n - 1; i++){
            high = max(high, (long double)(arr[i + 1] - arr[i]));
        }

        long double diff = 1e-6;

        while(high - low > diff){
            long double mid = (low + high) / 2.0;

            int cnt = numberOfGasStationsRequired(mid, arr);

            if(cnt > k) low = mid;
            else high = mid;
        }

        return high;
    }
};

// Technique:
// Binary Search on Answer

// Approach:
// The answer lies between 0 and the maximum
// distance between two consecutive stations.
// Use Binary Search on the maximum allowed
// distance between adjacent stations.
// For a candidate distance, compute how many
// additional gas stations are required so that
// every segment length becomes at most that distance.
// If more than K stations are needed,
// the distance is too small.
// Otherwise, it is a valid answer.
// Continue until the required precision is reached.

// TC: O(N × log(MaxGap / ε))
// N => Number of gas stations
// MaxGap => Maximum distance between adjacent stations
// ε => Precision (1e-6)

// SC: O(1)

// Verdict: Optimal

int main(){
    // Main Function placeholder for testing
    return 0;
}