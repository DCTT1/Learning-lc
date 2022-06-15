数组---3
//Leetcode--167--Middle
//给一个整数数组，非递减 顺序排列，找到两数之和等于target，并返回下标
//实例输入：numbers = [2,7,11,15], target = 9
输出：[1,2]
解释：2 与 7 之和等于目标数 9 。因此 index1 = 1, index2 = 2 。返回 [1, 2] 。

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int left = 0,right = nums.size()-1;
        while(left < right) {
            int sum = nums[left]+nums[right];
            if(sum < target)    left++;
            else if(sum > target)   right--;
            else    return {left+1, right+1};
        }
        return {};
    }
};

LeetCode---633--Easy
/给定一个非负整数 c ，你要判断是否存在两个整数 a 和 b，使得 a平方 + b平方 = c 
class Solution {
public:
    bool judgeSquareSum(int c) {
        if(c <= 1)  return true;
        long i=0,j = sqrt(c);
        while(i <= j) {
            if(i*i + j*j < c)   i++;
            else if(i*i + j*j > c)  j--;
            else    return true;
        }
        return false;
    }
};


LeetCode---88--Easy
//两个按非递减顺序排列的整数数组nums1和nums2，另有两个整数 m 和n,分别表示 nums1 和 nums2 中的元素数目。合并 nums2 到 nums1 中，使合并后的数组同样按 非递减顺序 排列。

