#define pb emplace_back

//problem link:-https://leetcode.com/problems/burst-balloons/

class Solution {
public:
    int maxCoins(vector<int>& nums) {
            
            // we will use 3 pointer approach
            
            //left right and p(the current balloon)
            
            //first make a new array which have 1 on left and right
            
            vector<int> arr;
            int n = nums.size();
            arr.pb(1);
            
            for(int num : nums){
                    
                    arr.pb(num);
            }
            
            arr.pb(1);
            
            //now padding is done
            
            vector<vector<int>> dp(arr.size() , vector<int> ( arr.size()));
            
            for(int left = n ; left>=1 ; left--){
                    
                    for(int right = left ; right <=n ; right++){
                            
                            
                            if(left == right){
                                    
                                    dp[left][right] = arr[left]*arr[left + 1]*arr[left -1];
                                    
                                    continue;
                            }
                            
                            
                            // p is left
                            
                            dp[left][right] = dp[left + 1][right] + arr[left]*arr[left - 1]*arr[right + 1];
                            
                            //p is right
                            
                            dp[left][right] = max(dp[left][right] , dp[left][right - 1] + arr[right]*arr[right + 1]*arr[left - 1]);
                            
                            //left<p<right
                            for(int p = left + 1 ; p<right ; p++){
                                    
                                    dp[left][right] = max(dp[left][right] , dp[left][p-1] + dp[p + 1][right] + arr[p]*arr[right + 1]*arr[left-  1]);
                                    
                            }
                            
                            
                    }
            }
            return dp[1][n];
            
        
        
    }
};
