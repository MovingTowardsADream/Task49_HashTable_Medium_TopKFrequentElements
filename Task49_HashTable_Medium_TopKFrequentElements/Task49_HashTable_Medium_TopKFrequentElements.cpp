#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <queue>

// Second solution

class Solution {
public:
    static std::vector<int> topKFrequent(std::vector<int>& nums, int k) {
        std::map<int, int> num_map;
        for (int i = 0;i < nums.size();i++)
            num_map[nums[i]]++;
        std::priority_queue<std::pair<int, int>>  pq;
        for (auto& i : num_map)
            pq.push({ i.second, i.first });
        std::vector<int> result;
        while (k--) {
            result.push_back(pq.top().second);
            pq.pop();
        }
        return result;
    }
};

// First solution

//class Solution {
//public:
//    static std::vector<int> topKFrequent(std::vector<int>& nums, int k) {
//        std::map<int, int> num_map;
//        for (int i = 0;i < nums.size();i++)
//            num_map[nums[i]]++;
//        std::vector<std::pair<int, int>> tmp;
//        for (auto& i : num_map)
//            tmp.push_back({ i.second, i.first });
//        std::sort(tmp.rbegin(), tmp.rend());
//        std::vector<int> result;
//        for (int i = 0;i < k;i++) {
//            result.push_back(tmp[i].second);
//        }
//        return result;
//    }
//};

int main()
{
    std::vector<int> nums = { 1,1,1,2,2,3 };
    for (int i : Solution::topKFrequent(nums, 2)) {
        std::cout << i << " ";
    }
}
