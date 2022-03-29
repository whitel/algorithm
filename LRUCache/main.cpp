#include<bits/stdc++.h>
#include<sys/time.h>
using namespace std;

#define DEBUG

struct DLinkedNode {
    int key, value;
    DLinkedNode *prev;
    DLinkedNode *next;
    DLinkedNode() : key(0), value(0), prev(nullptr), next(nullptr) {};
    DLinkedNode(int key, int value) : key(key), value(value), prev(nullptr), next(nullptr) {};
};

class LRUCache {
private:
    unordered_map<int, DLinkedNode*> cache;
    DLinkedNode *head;
    DLinkedNode *tail;
    int size;
    int capacity;
public:
    LRUCache(int _capacity) : capacity(_capacity), size(0) {
        head = new DLinkedNode();
        tail = new DLinkedNode();
        head->next = tail;
        tail->prev = head;
    }

    int get(int key) {
        if(!cache.count(key)) {
            cout << -1 << endl;
            return -1;
        }
        DLinkedNode *node = cache[key];
        moveToHead(node);
        cout << node->value << endl;
        return node->value;
    }

    void put(int key, int value) {
        if(!cache.count(key)) {
            DLinkedNode *node = new DLinkedNode(key, value);
            cache[key] = node;
            addToHead(node);
            size++;
            if(size > capacity) {
                DLinkedNode *removed = removeTail();
                cache.erase(removed->key);
                delete removed;
                size--;
            }
        } else {
            DLinkedNode *node = cache[key];
            node->value = value;
            moveToHead(node);
        }
    }

    void moveToHead(DLinkedNode *node) {
        removeNode(node);
        addToHead(node);
    }

    void removeNode(DLinkedNode *node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
        // delete node;
    }

    void addToHead(DLinkedNode *node) {
        node->prev = head;
        node->next = head->next;
        head->next->prev = node;
        head->next = node;
    }

    DLinkedNode* removeTail() {
        DLinkedNode *node = tail->prev;
        removeNode(node);
        return node;
    }

};

int main() {
#ifdef DEBUG
    freopen("inputdata", "r", stdin);
    cout << "===========INPUT=============" << endl;
    system("cat inputdata");
    cout << endl;
    cout << "===========OUTPUT============" << endl;
#endif

    LRUCache lru(2);
    lru.put(1, 1);
    lru.put(2, 2);
    lru.get(1);
    lru.put(3, 3);
    lru.get(2);
    lru.put(4, 4);
    lru.get(1);
    lru.get(3);
    lru.get(4);

#ifdef DEBUG
    cout << "============END==============" << endl;
#endif
    return 0;
}

