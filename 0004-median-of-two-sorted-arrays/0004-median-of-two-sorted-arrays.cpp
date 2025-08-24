class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
       
       // brute force approach
       
        // vector<int> nums3;
        // int n1 = nums1.size(), n2 = nums2.size();
        // int i=0;
        // int j=0;

        // while(i<n1 && j<n2){
        //     if(nums1[i] < nums2[j]) nums3.push_back(nums1[i++]);
        //     else nums3.push_back(nums2[j++]);
        // }
        // while(i<n1){
        //     nums3.push_back(nums1[i++]);
        // }
        // while(j<n2){
        //     nums3.push_back(nums2[j++]);
        // }

        // int size = n1 + n2;

        // if(size % 2 == 1){
        //     return nums3[size/2];
        // }
        // else{
        //     return ((double)((double)nums3[size/2] + (double)nums3[(size/2)-1])/2);
        // }


        // better approch with O(1) Space complxity

        int n1 = nums1.size(), n2 = nums2.size();
        int i=0;
        int j=0;
        int n = n1 + n2;

        int ind2 = n/2;
        int ind1 = ind2 - 1;
        int count = 0;
        int ind1el = -1, ind2el = -1;

        while(i<n1 && j<n2){
            if(nums1[i] < nums2[j]){
            if(count == ind1) ind1el = nums1[i];
            if(count == ind2) ind2el = nums1[i];
            count++;
            i++;
            }
            else{
            if(count == ind1) ind1el = nums2[j];
            if(count == ind2) ind2el = nums2[j];
            count++;
            j++;
            }
        }

        while(i<n1){
            if(count == ind1) ind1el = nums1[i];
            if(count == ind2) ind2el = nums1[i];
            count++;
            i++;
        }
        while(j<n2){
            if(count == ind1) ind1el = nums2[j];
            if(count == ind2) ind2el = nums2[j];
            count++;
            j++;
        }

        if(n % 2 == 1){
            return ind2el;
        }

        else{
            return ((double)((double)ind1el + (double)ind2el)/2.0);
        }

    }
};