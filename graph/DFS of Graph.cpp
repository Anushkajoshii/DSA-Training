//gfg
class Solution {
  public:
    // Function to return a list containing the DFS traversal of the graph.
    void dfs(int node, vector<int> adj[], vector<int> &res, vector<bool> &visited){
        visited[node]=1;
        res.push_back(node);
        for(int i=0; i<adj[node].size(); i++){
            if(!visited[adj [node][i] ]){
                visited[adj [node][i] ]= 1;
                dfs(adj[node][i],adj,res,visited);
            }
        }
    }
    
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        // Code here
        vector<int> res;
        vector<bool> visited(V,0);
        dfs(0,adj,res,visited);
        return res;
    }
};