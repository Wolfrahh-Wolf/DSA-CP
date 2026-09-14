#include <iostream>
#include <bits/stdc++.h>
using namespace std;

struct ListNode {
public:
    int data;
    ListNode* prev;
    ListNode* next;

    // Constructors
    ListNode() : data(0), prev(nullptr), next(nullptr) {}
    ListNode(int x) : data(x), prev(nullptr),  next(nullptr) {}
    ListNode(int x, ListNode* prev, ListNode* next) : data(x), prev(prev), next(next) {}
};



int main(){
    // Main Function placeholder for testing
    return 0;
}