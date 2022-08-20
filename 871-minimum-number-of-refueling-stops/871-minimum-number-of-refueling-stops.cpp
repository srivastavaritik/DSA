class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        if(target <= startFuel){
            return 0;
        }
		
        if(stations.size() == 0){
            return -1;
        }
        
        sort(stations.begin(), stations.end());
        
        int currPos = startFuel;
        int stops = 0;
        int i = 0;
		
        priority_queue<int> heap;
		
        while(currPos < target){
            while(i < stations.size() && stations[i][0] <= currPos){
                heap.push(stations[i][1]);
                i++;
            }
            if(!heap.empty()){
                currPos += heap.top();
                heap.pop();
                stops++;
            }
            else{
                return -1;
            }
        }
        return stops;
    }
};