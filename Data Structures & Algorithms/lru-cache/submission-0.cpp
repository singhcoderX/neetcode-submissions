class LRUCache {
   public:
    list<pair<int, int>> q;
    unordered_map<int, list<pair<int, int>>::iterator> bucket;
    int size;
    LRUCache(int capacity) { this->size = capacity; }

    int get(int key) {
        if (bucket.find(key) == bucket.end()) {
            return -1;
        } else {
            deleteAndUpdateKey(key, bucket[key]->second);
            return bucket[key]->second;
        }
    }

    void put(int key, int value) {
        if (size == q.size()) {
            if (bucket.find(key) == bucket.end()) {
                int localKey = q.front().first;
                q.pop_front();
                bucket.erase(localKey);
            }
        }
        deleteAndUpdateKey(key, value);
    }

    void deleteAndUpdateKey(int key, int value) {
        if (bucket.find(key) != bucket.end()) {
            auto it = bucket[key];
            q.erase(it);
        }
        q.push_back({key, value});
        auto it = q.end();
        it--;
        bucket[key] = it;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
