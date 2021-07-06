class Solution {
public:
    void sortColors(vector<int>& arr){
     //dutch algorithm
        int n = arr.size();
        int low = 0 , mid = 0  ,high = n - 1;
        while(mid <= high){
            if(arr[mid] == 0){
            /*in this case we move the mid pointer because the only possible value of low ptr is 0 or 1
            (bcoz we would have swapped any 2 which came before)
            -> If value of low is 0 , then that means thatfor sure low = mid ,hence both are
                needed to be moved simulataneously (otherwise low will go ahead of mid and 
                this will destroy the concept of low and mid(where mid was supposed to be ahead of low)
                and otherwise also it doesn't make sense to keep mid there because it has been delt)
            -> In all other cases the value of low will be 1(you can dry run). Now we know that in case
                where mid is 1 , we move the mid ptr by 1, so here also after swapping the mid becomes 1
                hence we should move by 1 at this place only.
            */
                swap(arr[mid++] , arr[low++]);
            }
            else if(arr[mid] == 1){
                mid++;
            }
            
            else if(arr[mid] == 2){
                /*
                ->In this case we don't move the mid pointer as we don;t know what is there currently in 
                the high pointer(we haven't delt with that part yet)
                ->So it is better to keep mid there only because there is a possibilty of all three numbers
                  currently for this place which will be dealt in the next iteration acc to value which
                  mid gets this time.
                */
                swap(arr[mid] , arr[high--]);
            }
        }
        
    }
};
