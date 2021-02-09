//using dsu

class Solution {
public:
    
    int *super_parent;
    
    int find_parent(int ele){
        
        if(super_parent[ele] == ele)return ele;
        
        super_parent[ele] = find_parent(super_parent[ele]);
        
        return super_parent[ele]; 
    }
    
    void make_union(int a , int b){
        
        int parent1 = find_parent(a);
        int parent2 = find_parent(b);
        
        if(parent1 != parent2){
            
            super_parent[parent1] = parent2;
        }
    }
    
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        
        int n = s.size();
        
        super_parent = new int[n];
        
        for(int i=  0 ;i<n; i++){
            
            super_parent[i] = i;
        }
        
        
        for(int i =  0 ; i< pairs.size() ; i++){
            
            int val1 = pairs[i][0] , val2 = pairs[i][1];
            
            
            make_union(val1 , val2);
        }
        
        unordered_map<int , vector<int>>mp;
        
        
        for(int i=  0 ;i<n ; i++){
            
            mp[find_parent(i)].push_back(i);
        }
        
        for(auto &curr_vec : mp){
            
            string temp;
            
            for(auto &x : curr_vec.second){
                temp += s[x];
            }
            
            sort(temp.begin() , temp.end());
            int ptr = 0;
            for(auto &x : curr_vec.second){
                
                s[x] = temp[ptr++];
            }
        }
        
        return s;
        
    }
};
