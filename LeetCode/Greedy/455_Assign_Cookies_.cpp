#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findContentChildren(vector<int>& Student, vector<int>& Cookie){
        sort(Student.begin(), Student.end());
        sort(Cookie.begin(), Cookie.end());

        int l = 0;
        int r = 0;

        int n = Student.size();
        int m = Cookie.size();

        while(l < n && r < m){
            if(Student[l] <= Cookie[r]) l++;
            
            r++;
        }

        return l;
    }
};

// Technique:
// Greedy
// Sorting
// Two Pointers

// Approach:
// Sort both the students and
// cookies in ascending order.
//
// Traverse both arrays using two
// pointers. If the current cookie
// can satisfy the current student's
// greed factor, assign it and move
// to the next student.
//
// Always move to the next cookie,
// ensuring each cookie is used at
// most once. The number of students
// satisfied is the final answer.

// TC: O(N log N + M log M)

// SC: O(1)

// Verdict: Optimal

int main(){
    // Main Function placeholder for testing
    return 0;
}