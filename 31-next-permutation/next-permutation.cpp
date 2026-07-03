/*            0 1 2 3 4 5
eg -> nums = [1 2 3 6 5 4]
      i =         5->4->3->2->1->loop ends
      nums[i-1] = 5->6->3
      nums[i] =   4->5->6

      we are checking nums[i-1] < nums[i] => 3 < 6 => here pivot should be elem 3 at index 2 i.2 i-1 not i ;

*/


class Solution {
public:

    void nextPermutation(vector<int>& nums) {

        //step 1 -> find the pivot element
        int pivot = -1;
        for(int i = nums.size() - 1 ; i > 0 ; i --){
            if(nums[i-1] < nums[i])   
            {
                pivot = i-1;
                break;
            }
        }

        // if no next perm possible , i.e pivot remains at -1
        if(pivot == -1) {reverse(nums.begin() , nums.end()); return;}


        // step 2 - > the rightmost elem > nums[pivot] and swapping both 
        for(int i = nums.size() - 1 ; i > pivot ; i --){
             if(nums[pivot] < nums[i]){ swap(nums[i] , nums[pivot]);
             break;}
        }

        //step 3 -> reverse the elements after pivot or sort them in ascending order
        reverse(nums.begin() + pivot+ 1  , nums.end());
    }
};