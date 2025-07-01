//Majority element => The majority element is the element that appears more than ⌊n / 2⌋ times. 
#include<bits/stdc++.h>
#include <vector>
using namespace std;

/*

method 1 :
Time and Space complexity : O(n)

Approach :
1)You have to take a map data structure
2)Insert all elements of the vector into the map
3)if any of this element occur more than n/2 times then return this 
*/
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        map<int,int>mp;
        for(auto i :nums)mp[i]++;
        for(auto it :mp){
            if(it.second>n/2)return it.first;
        }
        return -1;
    }    
};  


/*

method 2 : Moore voting algorithm

Time Complexity :O(n)
Space Complexity : O(1)

Approach : 
1)step 1 : Find a candiadate with the majority
a)when vote =0 , choose the candidate = arr[i] , make votes=1.
b)when the elements are same as the candidate element votes are incremented whereas when some other element is found, decrement the vote
2)step 2 : Check if the candidate has more than N/2 votes -
a)intialize a counter
b)check if nums[i] is equal to candidate element then increment the counter
3)allast check counter is >n/2 or not
*/

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int candidate = -1, vote = 0;
        for(int i = 0;i<nums.size();i++){
            if(vote == 0){
                candidate = nums[i];
                vote = 1;
            }
            else if(candidate == nums[i])vote++;
            else vote--;
        }
        int count = 0;
        for(int i = 0;i<nums.size();i++){
            if(nums[i]== candidate)count++;
        }
        int n = nums.size();
        if(count>n/2) return candidate;
        return -1;
    }    
};

/*

method 3 : Moore voting algorithm (modified)

Time Complexity :O(n)
Space Complexity : O(1)

Approach : 
1) if counter is 0 ,the current element is assigned as the new candidate, and counter is set to 1
2)if current element is the same as the candidate,the counter is incremented
3)if the current elements is different as the candidate,the counter is decremented
4)now after iterating through the vactor if counter is greater than n/2 return th candidate element.
*/

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count = 0,candidate = -1;
        for(int i = 0;i<nums.size();i++){
            if(nums[i]==candidate)count++;
            else if(count == 0){
                candidate = nums[i];
                count = 1;
            }
            else count--;
        }
        int n = nums.size();
        if(count>n/2)return candidate;
        return -1;
    }    
};