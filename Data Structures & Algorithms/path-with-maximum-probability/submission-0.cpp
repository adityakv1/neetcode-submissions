class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        vector<vector<pair<int,double>>> edge(n);
        vector<double> prob(n, 0.0);
        for(int i=0;i<edges.size();i++){
            int u =edges[i][0];
            int v=edges[i][1];
            edge[u].push_back({v,succProb[i]});
            edge[v].push_back({u,succProb[i]});
        }
        
        priority_queue<pair<double,int>> pq;
        pq.push({1.0,start_node});
        prob[start_node]=1.0;
        
        while(!pq.empty()){
            int a=pq.top().second;
            double b =pq.top().first;
            pq.pop();
            if(a==end_node){
                return b;
            }
            for(auto it:edge[a]){
                int next=it.first;
                double pro=it.second;
                double cp=b*pro;
                if(cp>prob[next]){
                    prob[next]=cp;
                    pq.push({cp,next});
                }
            }
        }
        return 0.0;
    }
};