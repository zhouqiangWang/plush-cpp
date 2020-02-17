#include <iostream>
#include "bits/stdc++.h"

using namespace std;

class Node {
public:
    Node* pre; Node* next;
    int key, val, cnt;

    Node(int key, int value) {
        this->key = key;
        val = value;
        cnt = 1;
    }
};
class DLList {
    Node* head; Node* tail;
    int cnt;
public:
    DLList() {
        head = new Node(0, 0);
        tail = new Node(0, 0);
        head->next = tail;
        tail->pre = head;
        cnt = 0;
    }
    
    void add(Node* node) {
        cnt++;
        node->next = head->next;
        node->pre = head;
        head->next->pre = node;
        head->next = node;
    }
    Node* remove(Node* node) {
        cnt--;
        node->pre->next = node->next;
        node->next->pre = node->pre;
        
        return node;
    }
    void pullToHead(Node* node) {
        remove(node);
        add(node);
    }
    Node* popTail() {
        return remove(tail->pre);
    }
    int size() {
        return cnt;
    }
};
class LFUCache {
    unordered_map<int, Node*> cache;
    unordered_map<int, DLList*> count_list;
    int capacity;
    int min;
public:
    LFUCache(int capacity) {
        this->capacity = capacity;
        min = 1;
    }
    
    int get(int key) {
        if (cache.count(key) == 0) {
            return -1;
        }
        int c = cache[key]->cnt;
        cache[key]->cnt = c + 1;
        
        count_list[c]->remove(cache[key]);
        if (count_list[min]->size() == 0) {
            min++;
        }
        if (count_list.count(c + 1) == 0) {
            count_list[c+1] = new DLList();
        }
        count_list[c+1]->add(cache[key]);
        
        return cache[key]->val;
    }
    
    void put(int key, int value) {
        int cur = get(key);
        if (cur != -1) {
            cache[key]->val = value;
            return;
        }
        
        if (cache.size() >= capacity) {
            Node* last = count_list[min]->popTail();
            cache.erase(last->key);
        }
        
        Node* newNode = new Node(key, value);
        if (count_list.count(1) == 0) {
            count_list[1] = new DLList();
        }
        count_list[1]->add(newNode);
        min = 1;
        cache[key] = newNode;
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 * 
 * ["LFUCache","put","put","put","put","get"]
        [[2],[3,1],[2,1],[2,2],[4,4],[2]]
 */



int main() {
    LFUCache* obj = new LFUCache(2);
    obj->put(3, 1);
    obj->put(2, 1);
    obj->put(2, 2);
    obj->put(4, 4);
    cout<< obj->get(2) <<endl;

    return 0;
}