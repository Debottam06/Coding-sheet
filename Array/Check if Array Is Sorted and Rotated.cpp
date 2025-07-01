#include <vector>

using namespace std;
/*
Time Complexity : O(n)
Space Complexity : O(1)

Approach :
1)Just compare the element with its next element
2)In roated and sorted array this above condition will hold exactly once or zero time (in case array is already sorted in ascending order)
3) so in case if holding true more than once then not sorted and rotated
*/
class Solution {
public:
    bool check(vector<int>& nums) {
        int count = 0;
        for(int i=0;i<nums.size();i++){
            if(nums[i] > nums[(i+1)%nums.size()])count++;
        }
        if(count<=1) return true;
        return false;
    }
};        
