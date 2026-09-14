#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Node{
public:
    int key;
    int val;
    int cnt;
    Node* next;
    Node* prev;

    Node(int k, int value){
        key  = k;
        val  = value;
        cnt  = 1; 
        next = prev = nullptr;
    }
};

class List{
public:
    int size;
    Node* head;
    Node* tail;

    List(){
        head = new Node(0, 0);
        tail = new Node(0, 0);

        head->next = tail;
        tail->prev = head;

        size = 0;
    }

    void addFront(Node* node){
        Node* nextNode = head->next;

        node->next = nextNode;
        nextNode->prev = node;

        head->next = node;
        node->prev = head;

        size++; // NOTE
    }
   
    void deleteNode(Node* node){
        Node* nextNode = node->next;
        Node* prevNode = node->prev;

        nextNode->prev = prevNode;
        prevNode->next = nextNode;

        size--; // NOTE
    }
};

class LFUCache{
private:
    unordered_map<int, Node*> keyNodeMap;
    unordered_map<int, List*> freqListMap;

    int maxCacheSize;
    int minFreq;
    int curSize;

public:
    LFUCache(int capacity){
        maxCacheSize = capacity;
        minFreq = 0;
        curSize = 0;
    }

    void updateFreqListMap(Node* node){
        keyNodeMap.erase(node->key);

        freqListMap[node->cnt]->deleteNode(node);

        if(node->cnt == minFreq && 
           freqListMap[node->cnt]->size == 0){ // NOTE: list size should be Zero
            minFreq++;
        }

        node->cnt++;

        List* nextHigherFreqList;

        if(freqListMap.find(node->cnt) != freqListMap.end()){
            nextHigherFreqList = freqListMap[node->cnt];
        }
        else nextHigherFreqList = new List();
        
        nextHigherFreqList->addFront(node);

        freqListMap[node->cnt] = nextHigherFreqList;
        keyNodeMap[node->key]  = node;
    }

    int get(int key){
        if(keyNodeMap.find(key) != keyNodeMap.end()){
            Node* node = keyNodeMap[key];
            int val = node->val;
            updateFreqListMap(node);

            return val;
        }

        return -1;
    }

    void put(int key, int value){
        if(!maxCacheSize) return;

        if(keyNodeMap.find(key) != keyNodeMap.end()){
            Node* node = keyNodeMap[key];
            node->val  = value;

            updateFreqListMap(node);
        }
        else{
            if(curSize == maxCacheSize){
                List* list = freqListMap[minFreq];

                keyNodeMap.erase(list->tail->prev->key);
                freqListMap[minFreq]->deleteNode(list->tail->prev);

                curSize--;
            }

            curSize++;

            minFreq = 1; // node->cnt will also be 1
            List* list;

            if(freqListMap.find(minFreq) != freqListMap.end()){
                list = freqListMap[minFreq];
            }
            else list = new List();

            Node* newNode = new Node(key, value);

            list->addFront(newNode);

            keyNodeMap[newNode->key] = newNode;

            freqListMap[minFreq] = list;
        }
    }

};

// Technique:
// Hash Map + Doubly Linked Lists (Frequency Buckets)

// Approach:
// Maintain a node for every key containing:
// - Key
// - Value
// - Access Frequency
//
// Use:
//
// keyNodeMap
//
// to locate nodes in O(1).
//
// Use:
//
// freqListMap
//
// where each frequency maps to a doubly linked list
// storing all nodes having that frequency.
//
// Each list maintains recency order:
// - Most Recently Used (MRU) near head
// - Least Recently Used (LRU) near tail
//
// get(key):
// - Return -1 if key is absent.
// - Otherwise, increase its frequency.
// - Move the node from its current
//   frequency list to the next higher
//   frequency list.
// - Return the node value.
//
// put(key, value):
// - If key already exists,
//   update its value and frequency.
// - Otherwise:
//   - Evict the least frequently used node
//     when the cache is full.
//   - If multiple nodes have the same
//     minimum frequency, remove the LRU node.
//   - Insert the new node into the
//     frequency-1 list.
// - Update minFreq accordingly.
//
// The combination of hash maps and
// frequency lists enables O(1)
// insertion, deletion, update,
// and frequency promotion.

// TC:
// get() : O(1)
// put() : O(1)

// SC: O(C)
// C => Cache capacity
// Node storage + Hash Maps +
// Frequency Lists

// Verdict: Optimal

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */


int main(){
    // Main Function placeholder for testing
    return 0;
}