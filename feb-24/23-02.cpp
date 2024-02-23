//https://leetcode.com/problems/cheapest-flights-within-k-stops/?envType=daily-question&envId=2024-02-23

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<pair<int, int>> adj[n];
        for(int i = 0;i<flights.size();i++){
            int from = flights[i][0];
            int to = flights[i][1];
            adj[from].push_back({to, flights[i][2]});
        }
        vector<int> vis(n, INT_MAX);
        priority_queue<pair<int, pair<int, int>>> pq;
        pq.push({k+1, {src, 0}}); // <k, <stop, price>>
        while(!pq.empty()){
            int rem = pq.top().first;
            int curr = pq.top().second.first;
            int price = pq.top().second.second;
            pq.pop();
            if(rem == 0) continue;
            for(pair<int, int> flight:adj[curr]){
                int newPrice = price + flight.second;
                if(newPrice<vis[flight.first]) {
                    vis[flight.first] = newPrice;
                    pq.push({rem-1, {flight.first, vis[flight.first]}});
                }
            }
        }
        if(vis[dst] == INT_MAX) return -1;
        return vis[dst];
    }
};