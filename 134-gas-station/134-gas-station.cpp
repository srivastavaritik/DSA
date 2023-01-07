class Solution {
public:
     int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int cost_sum = 0;
        int gas_sum = 0;
        int n = gas.size();
        for(int i = 0; i < n; i++)
        {
            cost_sum += cost[i];
            gas_sum += gas[i];
        }
        if(cost_sum > gas_sum) return -1;
        int ans = 0, curr_gas = 0;
        for(int i = 0;i < n; i++) 
        {
            if(curr_gas  < 0)
            {
                curr_gas = 0;
                ans = i;
            }

            curr_gas += (gas[i]-cost[i]);
        }
        return ans;
    }
};