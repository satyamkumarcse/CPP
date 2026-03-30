// Binary Search (brief and clear)
 



class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {

        int l=0;
        int u = nums.size()-1;
        int midval;

       

        while(l<=u){
            midval = l+(u-l)/2;
            if(nums[midval]==target){
                return midval ;
                

            }
            else if(target>nums[midval]){
                l = midval + 1;
            }
            else if(target<nums[midval]){

                u = midval-1;
            }
        }
        return l;     // if target element not found, where it can be inserted to maintain sorted order.


        
    }
};