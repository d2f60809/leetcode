#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int len = nums.size();
        int i, j;

        for (i = 0; i < len; i++)
        {
            for (j = i + 1; j < len; j++)
            {
                if (nums[i] + nums[j] == target)
                {
                    return {i,j};
                }
            }
        }

        return {};
    }

    vector<int> twoSum_hash(vector<int> &nums, int target)
    {
        unordered_map<int, int> mp; // hash map

        // target = a + b
        for (int i = 0; i < nums.size(); i++)
        {
            //令num[i] = a, 找map中有無 b = target - a
            if (mp.find(target - nums[i]) == mp.end()) // 因為是hash map，找很快
                mp[nums[i]] = i; // 如果找不到，就將a放入map --> {[a,i], ...}，接著從下一個num開始找
            else
                return {mp[target - nums[i]], i};
        }

        return {-1, -1};


        //ex: [7,8,9] target = 16 = a + b
        // start: mp = {}, i = 0
        // 1st loop: a = 7, find b = 9 -> i = 0, mp = {} (not found)
        // 2nd loop: a = 8, find b = 8 -> i = 1, mp = {[7, 0]} (not found)
        // 3rd loop: a = 9, find b = 7 -> i = 2, mp = {[7, 0], [8, 1]} (found!! ans = {0,2})

        // 概念： hash map 搜尋速度為O(1)，利用這點，將題目想成尋找b = target - a
        // 先把(7,0)放進map中，接著，從8開始，在table中找有沒有8 (16-8) -> 沒有
        // 再把(8,1)放進map中，接著從9開始，在table中找有沒有7 (16-9) ->有
        // 如此如果有n個數字，只需要尋找最多n次，由於hash table為O(1),因此為O(n)
    }
    
};
