class Solution {
private:
    bool static compare(pair<int, int> &a, pair<int, int> &b) {
        if (a.first == b.first) return a.second < b.second;
        return a.first < b.first;
    }

public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        vector<pair<int, int>> v;
        vector<vector<int>> ans;
        multiset<int, greater<int>> m;

        for (int i = 0; i < buildings.size(); i++) {
            int s = buildings[i][0];
            int e = buildings[i][1];
            int h = buildings[i][2];
            v.push_back({s, -h});
            v.push_back({e, h});
        }

        sort(v.begin(), v.end(), compare);

        int curr = 0;
        m.insert(0);

        for (int i = 0; i < v.size(); i++) {
            int x = v[i].first;
            int h = v[i].second;

            if (h < 0)   m.insert(-h);
            else        m.erase(m.find(h));

            int top = *m.begin();
            if (curr != top) {
                ans.push_back({x, top});
                curr = top;
            }
        }

        return ans;
    }
};