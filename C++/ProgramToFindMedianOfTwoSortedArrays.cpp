#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        double ans;
        // Merge nums1 and nums2 into a single vector nums3
        vector<int> nums3(nums1.size() + nums2.size());
        merge(nums1.begin(), nums1.end(), nums2.begin(), nums2.end(), nums3.begin());
        
        // Calculate the size of the merged array
        int n = nums3.size();
        
        // If the size is even, calculate the average of the two middle numbers
        if (n % 2 == 0) {
            int mid1 = n / 2;
            ans = (nums3[mid1] + nums3[mid1 - 1]) / 2.0;
        }
        // If the size is odd, pick the middle element
        else {
            ans = nums3[n / 2];
        }
        
        return ans;
    }
};

int main() {
    int m, n;
    
    // Input size for nums1 and nums2
    cout << "Enter size of nums1: ";
    cin >> m;
    vector<int> nums1(m);
    
    cout << "Enter elements of nums1 (sorted): ";
    for (int i = 0; i < m; i++) {
        cin >> nums1[i];
    }
    
    cout << "Enter size of nums2: ";
    cin >> n;
    vector<int> nums2(n);
    
    cout << "Enter elements of nums2 (sorted): ";
    for (int i = 0; i < n; i++) {
        cin >> nums2[i];
    }
    
    Solution sol;
    double median = sol.findMedianSortedArrays(nums1, nums2);
    
    // Output the median
    cout << "Median of the two sorted arrays: " << median << endl;
    
    return 0;
}
