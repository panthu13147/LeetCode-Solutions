class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        // Ensure nums1 is the SMALLER array
        if (nums1.size() > nums2.size()) {
            swap(nums1, nums2);
        }
        
        int m = nums1.size();
        int n = nums2.size();
        int left = 0, right = m;
        
        while (left <= right) {
            int partitionX = left + (right - left) / 2;
            int partitionY = (m + n + 1) / 2 - partitionX;
            
            int maxLeftX  = (partitionX == 0) ? INT_MIN : nums1[partitionX - 1];
            int minRightX = (partitionX == m) ? INT_MAX : nums1[partitionX];
            
            int maxLeftY  = (partitionY == 0) ? INT_MIN : nums2[partitionY - 1];
            int minRightY = (partitionY == n) ? INT_MAX : nums2[partitionY];
            
            if (maxLeftX <= minRightY && maxLeftY <= minRightX) {
                if ((m + n) % 2 == 1) {
                    return max(maxLeftX, maxLeftY);
                } else {
                    return (max(maxLeftX, maxLeftY) + min(minRightX, minRightY)) / 2.0;
                }
            }
            else if (maxLeftX > minRightY) {
                right = partitionX - 1;   // took too much from nums1's left, back off
            }
            else {
                left = partitionX + 1;    // need more from nums1's left
            }
        }
        return 0.0;  // unreachable if inputs are valid per constraints
    }
};