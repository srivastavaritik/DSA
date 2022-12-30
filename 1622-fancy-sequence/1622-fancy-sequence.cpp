class Fancy {
public:
    class Val;
    vector<Val>vals;
    int mod = 1000000007;
    // X, Y is the aggregated mutipler and adder after last append.
    long long X = 1, Y = 0;
    class Val{
        public:
            int fathor;
            int index;
            // Aggregated x,y for oprations happend after (i)th append and before (fathor)th append.
            long long x, y;
            long long val;

            Val(long long val, int index) {
                this->fathor = index;
                this->index = index;
                this->val = val;
                // Beacuse inint fathor is it's self, there opration so x = 1, y = 0 
                x = 1;
                y = 0;
            }
    };
    // join group `son` to group `root` with (x,y) as edge;
    void Union(int son, int root, int x, int y) {
        vals[son].fathor = vals[root].index;
        vals[son].x = x;
        vals[son].y = y;
    }

    // The time complexity for "find" is O(1) in avg, it is same as UnionFind algorithm.
    int find(int current, long long &x, long long &y) {
        // if current node is not the root, search for it's fathor
        Val &v = vals[current]; 
        if(v.index != v.fathor) {
            v.fathor = find(v.fathor, v.x, v.y);
        }
        // Update x and y;
        y = v.x * y + v.y;
        x = v.x * x;
        x %= mod;
        y %= mod;
        return v.fathor; 
    }

    Fancy() {
    }
    
    void append(int val) {
        // For newly append val, create a new group.
        vals.push_back(Val(val, vals.size()));
        if(vals.size() >= 2){
            // merge the second lastest group into lastest group.
            Union(vals.size() - 2, vals.size() - 1, X, Y);
        } 
        X = 1;
        Y = 0;
    }
    
    void addAll(int inc) {
        Y += inc;
    }

    void multAll(int m) {
        Y = (Y * m) % mod;
        X = (X * m) % mod;
    }
    
    int getIndex(int idx) {
        if (idx >= vals.size()) 
            return -1;
        long long x = 1, y = 0;
        
        find(idx, x, y);
        long long ret = vals[idx].val;
        ret = (ret * x + y)%mod;
        ret = (ret * X + Y)%mod;
        return ret;
    }
};
