class RandomizedSet {
public:
vector<int> v;
unordered_map<int, int> m;
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        if(m.find(val)!=m.end())
        return false;

        else
        {
            v.push_back(val);
            m[val] = v.size()-1;
            return true;
        }
    }
    
    bool remove(int val) {
        if(m.find(val)==m.end())
        return false;

        else
        {
            int last = v.back();
            v[m[val]] = last;
            v.pop_back();
            m[last] = m[val];
            m.erase(val);
        }
        return true;
    }
    
    int getRandom() {
        return v[rand()%v.size()];
    }
};