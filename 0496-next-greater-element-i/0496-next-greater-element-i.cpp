class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        for(int i = 0; i < nums1.size(); i++){
            int index;
            for(int j = 0; j < nums2.size(); j++){
                if(nums1[i] == nums2[j]){
                    index = j;
                    break;
                }
            }
            int maxValue = -1; 
            for(int j = index + 1; j < nums2.size(); j++){
                if(nums2[j] > nums2[index]){
                    maxValue = nums2[j];
                    break;
                }
            }
            nums1[i] = maxValue;
        }
        return nums1;
    }
};