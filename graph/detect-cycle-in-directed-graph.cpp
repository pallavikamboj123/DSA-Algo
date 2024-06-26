//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    bool dfs(int node, vector<int>& visited, vector<int> adj[]) {
        visited[node] = 2;

        for(auto nbr:adj[node]) {

            if(visited[nbr] == 2) return true;

            if(!visited[nbr]) {
                if(dfs(nbr, visited, adj)) return true;
            }

        }

        visited[node] = 1;

        return false;
    }
    bool isCyclic(int V, vector<int> adj[]) {
        vector<int> visited;

        for(int i = 0; i < V; i++) visited.push_back(0);

        for(int i = 0; i < V; i++) {
            if(!visited[i]) {
                if(dfs(i, visited, adj)) return true;
            }
        }

        return false;

    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}

// } Driver Code Ends