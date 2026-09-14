#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Node{
public:
    int key;
    int val;
    Node* next;
    Node* prev;

    Node(){
        key  = val  = -1;
        next = prev = nullptr;
    }

    Node(int k, int value){
        key  = k;
        val  = value;
        next = prev = nullptr;
    }
};

class LRUCache{
private:
    unordered_map<int, Node*> mpp;
    int cap;

    Node* head;
    Node* tail;

    void deleteNode(Node* node){
        Node* nextNode = node->next;
        Node* prevNode = node->prev;

        prevNode->next = nextNode;     
        nextNode->prev = prevNode;
    }

    void insertAfterHead(Node* node){
        Node* nextNode = head->next;

        head->next = node;
        node->prev = head;

        node->next = nextNode;
        nextNode->prev = node;
    }

public:
    LRUCache(int capacity) {
        cap = capacity;
        mpp.clear();

        head = new Node();
        tail = new Node();

        head->next = tail;
        tail->prev = head;
    }

    int get(int key_){
        if(mpp.find(key_) == mpp.end()) return -1;

        Node* node = mpp[key_];
        int val = node->val;

        deleteNode(node);

        insertAfterHead(node);

        return val;
    }

    void put(int key_, int value){
        if(mpp.find(key_) != mpp.end()){
            Node* node = mpp[key_];
            node->val = value;

            deleteNode(node);

            insertAfterHead(node);

            return;
        }

        if(mpp.size() == cap){
            Node* node = tail->prev;

            mpp.erase(node->key);

            deleteNode(node);
        }

        Node* newNode = new Node(key_, value);

        mpp[key_] = newNode;

        insertAfterHead(newNode);

        return;
    }
};

// Technique:
// Hash Map + Doubly Linked List

// Approach:
// Use a hash map to provide O(1) access
// to cache entries using their keys.
// Use a doubly linked list to maintain
// the usage order of cache entries.
//
// Most Recently Used (MRU)
// is kept immediately after the head.
//
// Least Recently Used (LRU)
// is kept immediately before the tail.
//
// get(key):
// - Return -1 if the key is not present.
// - Otherwise, move the node to the front
//   of the list and return its value.
//
// put(key, value):
// - If the key already exists,
//   update its value and move it
//   to the front.
// - If the cache is full,
//   remove the LRU node from both
//   the linked list and hash map.
// - Insert the new node at the front.
//
// The doubly linked list enables O(1)
// insertion and deletion of nodes,
// while the hash map enables O(1)
// key lookup.

// TC:
// get() : O(1)
// put() : O(1)

// SC: O(C)
// C => Cache capacity
// Hash map + Doubly Linked List storage

// Verdict: Optimal


/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

int main(){
    // Main Function placeholder for testing
    return 0;
}