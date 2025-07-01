//Find the Duplicate Number
#include<bits/stdc++.h>
#include <vector>
using namespace std;

/*
method 1: using hash map

Time and Space Complexity : O(n)

Approach : 
1)You have to take a map data structure
2)Insert all elements of the vector into the map
3)if any of this element occur more than 1 times then return this 
*/
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        map<int,int>mp;
        for(auto i :nums)mp[i]++;
        for(auto it :mp){
            if(it.second>1){
                return it.first;
            }
        }
        return -1;
    }
};        

/*

method 2 : Floyd Cycle detection algorithm

Time Complexity : O(n)
Space Complexity : O(1)

Approach : 
1)Treat the array like a linked list: Each index is a "node" and nums[i] is the "next" pointer.
2)Cycle detection (Phase 1):Use two pointers: slow and fast.
a)slow = nums[slow], fast = nums[nums[fast]]
b)They will meet inside a cycle — caused by the duplicate.
3)Finding the entrance of the cycle (Phase 2):
a)Reset one pointer to start = 0.
b)Move both pointers one step at a time (slow = nums[slow], slow1 = nums[slow1]) until they meet.
The meeting point is the duplicate number.
*/


class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow = 0, fast = 0;
        for(int i=0;i<nums.size();i++){
            slow = nums[slow];
            fast = nums[nums[fast]];
            if(slow == fast)break;
        }
        int slow1 = 0;
        for(int i = 0;i<nums.size();i++){
            slow = nums[slow];
            slow1 = nums[slow1];
            if(slow == slow1)return slow;
        }
        return -1;
    }
}; 