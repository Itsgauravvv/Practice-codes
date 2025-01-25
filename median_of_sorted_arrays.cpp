#include <iostream>
#include <vector>
#include <limits> 
using namespace std;
// Function to find the median of two sorted arrays
double findMedianSortedArrays(vector<int>& a1, vector<int>& a2) {
    // Ensure the smaller array is the first one to minimize binary search complexity
    if (a1.size()>a2.size()) {
        swap(a1, a2);
    }
    int len1,len2,total, half,low,high;
    len1 = a1.size();
    len2 = a2.size();
    total = len1+len2;
    half = total/2;
    low = 0; 
    high = len1; // Binary search range for the smaller array

    while (low <= high) {
        int mid1 = (low+high)/2; // Partition index for a1
        int mid2 = half - mid1;      // Partition index for a2

        // Handle out-of-bound cases for the partitions
        int left1 = (mid1 > 0) ? a1[mid1 - 1] : numeric_limits<int>::min();
        int right1 = (mid1 < len1) ? a1[mid1] : numeric_limits<int>::max();

        int left2 = (mid2 > 0) ? a2[mid2 - 1] : numeric_limits<int>::min();
        int right2 = (mid2 < len2) ? a2[mid2] : numeric_limits<int>::max();

        // Check if we've found the correct partition
        if (left1 <= right2 && left2 <= right1) {
            // Odd total length: return the middle value
            if (total%2==1) {
                return min(right1, right2);
            }
            // Even total length: return the average of the two middle values
            return (max(left1, left2) + min(right1, right2)) / 2.0;
        } else if (left1 > right2) {
            // Partition is too far right in a1, move it left
            high = mid1 - 1;
        } else {
            // Partition is too far left in a1, move it right
            low = mid1 + 1;
        }
    }
    // If we reach this point, inputs were invalid
    throw invalid_argument("Input arrays are not sorted!");
}

int main() {
    // Test case 1
    vector<int> nums1 = {1, 3};
    vector<int> nums2 = {2};
    cout << "The Median is: "<<findMedianSortedArrays(nums1, nums2) << endl;
    // Test case 2
    nums1 = {1, 2};
    nums2 = {3, 4};
    cout << "The Median is: " << findMedianSortedArrays(nums1, nums2) << endl;
    return 0;
}
