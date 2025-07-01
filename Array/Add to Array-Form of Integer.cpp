//Add to Array-Form of Integer
#include <bits/stdc++.h>
#include <vector>
#include <string>

using namespace std;
/*

Method 1 : 

Time and space complexity : O(n) n => size of the vector and string 
Approach : 
1) We have to store all the elements of the vector nums into the string b
2)then chnage the string to ll and sum with k 
3) Store this sum into the string s
4) then use a vector to store the character of the string which are converted into int and return the vector
*/
class Solution {
public:
    vector<int> addToArrayForm(vector<int>& nums, int k) {
        vector<int>v;
        string b;
        for(int  i = 0;i<nums.size();i++){
            b+=to_string(nums[i]);
        }
        string s = to_string(stoll(b)+k);
        for(int i=0;i<s.size();i++){
            v.push_back(s[i]-'0');
        }
        return v;
    }   
};    

/*

Method 2 :

Time Complexity : O(n) , Space Complexity : O(1)
Approach : 
1)You have to traverse from the last index of the vector nums
2)first sum with k and nums[i] and push the last digit of the sum means carry 
3)and store the remmaing carry into k by (k /=10;)
4)atlast reverse the vector because digits were added from least to most significant.
*/
class Solution {
public:
    vector<int> addToArrayForm(vector<int>& nums, int k) {
        vector<int>v;
        int i = nums.size()-1;
        while(i>=0 || k >0){
            if(i>=0){
                k+=nums[i];
                i--;
            }
            v.push_back(k%10);
            k /=10;
        }
        reverse(v.begin(),v.end());
        return v;
    }   
}; 