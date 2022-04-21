class MyHashSet {
public:
    int sz;
    vector<list<int>> hashTable;
    MyHashSet() {
        sz = 100;
        hashTable = vector<list<int>>(sz);
    }
    
    void add(int key) {
        int hashVal = key % sz;
        hashTable[hashVal].push_back(key);
    }
    
    void remove(int key) {
        int hashVal = key % sz;
        hashTable[hashVal].remove(key);
    }
    
    bool contains(int key) {
        int hashVal = key % sz;
        return find(hashTable[hashVal].begin(), hashTable[hashVal].end(), key) != hashTable[hashVal].end();
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */