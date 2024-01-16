// https://leetcode.com/problems/insert-delete-getrandom-o1/description/?envType=daily-question&envId=2024-01-16

class RandomizedSet {
        unordered_set<int> s;

public:
    RandomizedSet() {
    }
    
    bool insert(int val) {
        if(s.find(val) != s.end()) return false;
        s.insert(val);
        return true;
    }
    
    bool remove(int val) {
        auto itr = s.find(val);
        if(itr == s.end()) return false;
        else s.erase(itr);
        return true;
        
    }
    
    int getRandom() {
        return *next(s.begin(),rand()%s.size());
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */