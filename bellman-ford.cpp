class solution{
	
  public:	
  
  int isNegativeWeightCycle(int n, vector<vector<int>>edges){
	    // Code here
	    
	    vector<long long>dis(n + 1 , INT_MAX);
	    dis[0] = 0;
	    
	    for(int i = 0 ;i<n-1 ; i++){
	        
	        for(int j = 0 ;j<edges.size() ; j++){
	            if(dis[edges[j][0]] + (long long)edges[j][2] <  dis[edges[j][1]]){
	                dis[edges[j][1]] = dis[edges[j][0]] + edges[j][2];
	            }
	        }
	    }
	    for(int j = 0 ;j<edges.size() ; j++){
            if(dis[edges[j][0]] +  (long long)edges[j][2] < dis[edges[j][1]]){
                //it means there is a negative cycle
                return 1;
            }
        }
        
        //if no neg cycle => dis array contains the shortest dis from node 0
        
        return 0;
	    
	}
};
