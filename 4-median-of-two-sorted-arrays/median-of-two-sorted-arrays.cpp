class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int size1 = nums1.size();
        int size2 = nums2.size(); 
        int i = 0 ;
        int j =0 ;
        int count = 0;
        int idx2 = (size1 + size2) / 2;
        int idx1 = idx2 - 1 ;
        int elem1 = 0,  elem2 = 0;
        bool found = false;
        while( i <= size1 - 1 && j <= size2 - 1){
          
            if(nums1[i] <= nums2[j]) {
                 if(count == idx1 ) elem1 = nums1[i];
                 if(count == idx2) {elem2 = nums1[i]; found = true ; break;}
                  count++;
                  i++;

            }
            else {
                if(count == idx1) elem1 = nums2[j];
                if(count == idx2) {elem2 = nums2[j]; found = true ;break;}
                count++;
                j++;
            }

        }
        if(!found){
            while(i <= size1 - 1){
                 if(count == idx1) elem1 = nums1[i];
                 if(count == idx2){
                 elem2 = nums1[i];
                 found = true ;
                 break;
                }
            count++;
            i++;
            }

            while(j <= size2 - 1){
               if(count == idx1) elem1 = nums2[j];
               if(count == idx2){
               elem2 = nums2[j];
               found = true ;
               break;
            }
            count++;
            j++;
            }
        }

        

        if((size1 + size2) % 2 == 0 ) {return (elem1 + elem2) / 2.0; ;}
        else return elem2;
    }
};