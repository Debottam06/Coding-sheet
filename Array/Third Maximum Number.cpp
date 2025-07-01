//Third Maximum Number
#include<bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <limits>

using namespace std;
/*

method 1 :

Time Complexity : O(nlogn) => for insertion n elements => O(nlogn) ans erase also O(logn)
Space Complexity : O(n)

Approach : 
1)We have to take a set and insert elements of the vector into the set
2)if total element in the set is lass than 3 then there must be no 3rd largest elemnt so return the maximum 
3)then erase last two elemnts from  the set and then return the last element
*/
class Solution {
public:
    int thirdMax(vector<int>& nums) {
        //if an unsorted array is inserted into a set , in the set all elements are sorted in order
        set<int>s(nums.begin(),nums.end());
        if(s.size()<3)return *s.rbegin();

        //s.rbegin()=> gives an iterator to get the actual value 
        s.erase(*s.rbegin());
        s.erase(*s.rbegin());
        return *s.rbegin();
    }
};    

/*

method 2 :

Time Complexity : O(nlogn) // sorting the vector
Sapce Complexity : O(1)

approach : 
1)Sort the vector
2)traverse the verctor through a loop from the last index(n-2) of the vector  if adjacent two elemnts are not equal then increment the counter
3) when counter == 3 , means we have to find the 3rd largest element
4)if counter <3 return the largest element 
*/

class Solution {
public:
    int thirdMax(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int count = 1;
        for(int i =nums.size()-2;i>=0;i--){
            if(nums[i]!=nums[i+1])count++;
            if(count == 3) return nums[i];
        }
        return nums[nums.size()-1];
    }
}; 


/*

method 3 :

Time Complexity : O(n)
Space Complexity : O(1)

Approach : 
1)we have to take 3 varable famx , smax, tmax and intialize this to INT_MIN
2)now iterate the vector through loop 
3)return the 3rd maximum element (tmax) if find , if not find return fmax
*/

class Solution {
public:
    int thirdMax(vector<int>& nums) {
        int fmax = INT_MIN,smax = INT_MIN,tmax=INT_MIN;
        for(auto num : nums){
            if(num>fmax){
                fmax = num;
                smax = fmax;
                tmax = smax;
            }
            else if(num>smax && num != fmax){
                smax = num;
                tmax = smax;
            }
            else if(num>tmax && num!=smax && num != fmax){
                tmax = num;
            }
        }
        return (tmax == INT_MIN)? fmax : tmax ;
    }
}; 