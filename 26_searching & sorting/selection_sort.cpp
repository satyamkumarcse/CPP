// Assume the first element is the minimum

// Scan the rest of the array to find the true minimum

// Swap once, at the end of the pass

// Now j scans the rest:
// [64,25,12,22,11]
// Compare 64 and 25 → 25 is smaller → update min (but NO swap)

// Compare 25 and 12 → 12 is smaller → update min

// Compare 12 and 22 → 12 still smaller

// Compare 12 and 11 → 11 is smaller → update min


class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        int n = nums.size();

        for (int i = 0; i < n - 1; i++) {
            int minIdx = i;

            for (int j = i + 1; j < n; j++) {
                if (nums[j] < nums[minIdx]) {
                    minIdx = j;
                }
            }

            swap(nums[i], nums[minIdx]);
        }

        return nums;
    }
};





#include <stdio.h>

int main(){
    
    int arr[12];
    int sum=0;

    int min = -99999;
    int max = 99999;
    int arrmonth[12];
    for(int i=0;i<12;i++){

        scanf("%d",&arr[i]);
        if(arr[i]<0){
            printf("Invalid input");
            return 0;
        }
        else{
             sum+=arr[i];
            
        }
        
        if(arr[i]>min){
            min = arr[i];
        }
        
        if(arr[i]<max){
            max=arr[i];
        }
       
        
    }
    
    for(int i=1;i<=12;i++){
        arrmonth[i-1]=i;
        
    }
    printf("Total rainfall : %d\n",sum);
    printf("Average rainfall : %d\n",sum/12);

    
    for(int i=0;i<12;i++){
        
        
        if(max!=arr[i]){
            continue;
        }
        else{
            printf("lowest rainfall month : %d\n",arrmonth[i]);
        }
        
    }
    
      for(int i=0;i<12;i++){
        
        
    
      if(min!=arr[i]){
            continue;
        }
    
    else{
            printf("Highest rainfall month : %d\n",arrmonth[i]);
        }
        
      }
    
    return 0;
}
