//Majority element II => Given an integer array of size n, find all elements that appear more than ⌊ n/3 ⌋ times.
/*In the majority element problem (> n/2 times), only one element can qualify, as no two elements can each exceed half the array. 
In majority element II (> n/3 times), at most two elements can qualify; three would exceed the total count. Hence, we look for one or two elements respectively.
*/
#include<bits/stdc++.h>
#include <vector>
using namespace std;

/*
Time Complexity : O(n)
Space Complexity : O(1)

Approach : Same as Majority element
the only difference is we have to take two counter variable and two candidate element here
*/

vector<int> majorityElement(vector<int>& nums) {
    int n = nums.size();
    int candidate1 = 0,candidate2 = -1;
    int count1 = 0,count2 = 0;
    for(int i = 0;i<n;i++){
        if(count1 == 0){
            candidate1 = nums[i];
            count1 = 1;
        }
        else if(count2 == 0){
            candidate2 = nums[i];
            count2 = 1;
        }
        else if(nums[i] == candidate1){
            count1++;
        }
        else if(nums[i]== candidate2){
            count2++;
        }
        else{
            count1--;
            count2--;
        }
    }

    vector<int>v;
    count1 =0,count2 = 0;
    for(int  i = 0;i<n;i++){
        if(nums[i]==candidate1)count1++;
        if(nums[i]==candidate2)count2++;
    }
    if(count1>n/3)v.push_back(candidate1);
    else if(count2>n/3)v.push_back(candidate2);
    return v;
}    