class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        vector<int> vec(n,0);
        queue<int> q;
        for(auto key : rooms[0]) q.push(key);
        vec[0] = 1;

        while(!q.empty()){
            int key = q.front();
            q.pop();
            vec[key] = 1;
            for(auto k : rooms[key])
                if(!vec[k])q.push(k);
        }
        for(int i = 1;i<n;i++){
            if(!vec[i]) return false;
        }
        return true;
    }
};