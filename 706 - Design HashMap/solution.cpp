class MyHashMap {
public:
    int sz;
    vector<list<pair<int, int>>> hashMap;
    MyHashMap() {
        sz = 100;
        hashMap = vector<list<pair<int, int>>>(sz);
    }
    
    std::list<pair<int, int>>::iterator check(int key) {
        int hashVal = key % sz;
        return std::find_if(hashMap[hashVal].begin(), hashMap[hashVal].end(),
                               [&key](const std::pair<int, int>& element) { 
                                   return element.first == key;
                               });
    }
    
    void put(int key, int value) {
        int hashVal = key % sz;
        auto it = check(key);
        if (it == hashMap[hashVal].end()) hashMap[hashVal].push_back(make_pair(key, value));
        else it->second = value;
    }
    
    int get(int key) {
        int hashVal = key % sz;
        auto it = check(key);
        if (it == hashMap[hashVal].end()) return -1;
        else return it->second;
    }
    
    void remove(int key) {
        int hashVal = key % sz;
        auto it = check(key);
        if (it != hashMap[hashVal].end()) hashMap[hashVal].erase(it);
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */