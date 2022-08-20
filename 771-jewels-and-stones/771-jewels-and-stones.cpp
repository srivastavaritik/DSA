class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
     multiset<char> j,s;
        int c=0;
        for(auto it:jewels)
        {
            j.insert(it);
        }
        for(auto it:stones)
        {
            s.insert(it);
        }
        for(auto it:stones)
        {
            if(j.find(it) != j.end())c++;
        }
        return c;
    }
};