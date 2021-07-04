class Solution
{
	public:
    //Function to return a list of lists of integers denoting the members 
    //of strongly connected components in the given graph.
    bool* onStack , *visited;
    vector<int>*adjlist;
    int *minVal;
    
    stack<int>s;
    int*store;
    int cnt = 0;
    vector<vector<int>>res;
    void func(int curr ){
        visited[curr] = true;
        onStack[curr] = true;
        
        store[curr] = cnt;
        minVal[curr] = cnt++;
        s.push(curr);
        for(auto neighbor : adjlist[curr]){
            
            
            if(!visited[neighbor]){
                func(neighbor);
            }
             if(onStack[neighbor]){
                minVal[curr] = min(minVal[curr] , minVal[neighbor]);
            }
        }
        
        if(minVal[curr] ==store[curr]){
            vector<int>tmp;
            while(!s.empty() && s.top()!= curr){
                tmp.push_back(s.top());
                onStack[s.top()] = false;
                s.pop();
            }
            
            tmp.push_back(s.top());
            onStack[s.top()] = false;
            s.pop();
            sort(tmp.begin() , tmp.end());
            res.push_back(tmp);
        }
        
    }
    
    vector<vector<int>> tarjans(int V, vector<int> adj[])
    {
        adjlist = adj;
        minVal = new int[V + 1];
        store = new int[V+1];
        
        for(int i = 0 ;i<V ; i++){
            minVal[i] = INT_MAX;
            store[i] = INT_MAX;
        }
        onStack = new bool[V + 1]();
        visited = new bool[V + 1]();
        for(int i = 0 ;i<V ;i++){
            if(!visited[i]){
                func(i );
            }
        }

        
        sort(res.begin() , res.end());
        
        return res;
    }
};
