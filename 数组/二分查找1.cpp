leetcode---704---Easy
//二分查找，在n个元素有序数组中找一个目标值，返回其下标，否则返回-1
/*案例
输入: nums = [-1,0,3,5,9,12], target = 9
输出: 4
解释: 9 出现在 nums 中并且下标为 4
*/
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size()-1;
        while(left <= right) {
            int mid = left + (right-left)/2;		//防止边界溢出
            if(nums[mid] > target)
                right = mid-1;
            else if(nums[mid] < target)
                left = mid+1;
            else    return mid;
        }
        return -1;
    }
};

leetcode---35--Easy
///给定一个排序数组和target  返回其索引，如果目标值不存在于数组中，返回它将会被按顺序插入的位置。

/*案例
输入: nums = [1,3,5,6], target = 5
输出: 2
输入: nums = [1,3,5,6], target = 2
输出: 1
*/
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int left = 0,right = nums.size()-1;
        while(left <= right) {
            int mid = left + (right-left)/2;
            if(nums[mid] < target)
                left = mid+1;
            else if(nums[mid] > target)
                right = mid-1;
            else return mid;
        }
        return right+1;
    }
};


Leetcode--34--Middle
//在排序数组中找到target的第一个位置与最后一个位置
/*案例
输入: nums = [5,7,7,8,8,10], target = 8
输出: [3,4]
输入: nums = [5,7,7,8,8,10], target = 6
输出: [-1,-1]
*/

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int low = lower_bound(nums, target);
        int high = upper_bound(nums, target);
        if (low == high) 
            return {-1, -1};
        else
            return {low, high - 1};
    }
    int lower_bound(vector<int>& nums, int target) {
        const int N = nums.size();
        // [l, r)
        int l = 0, r = N;
        while (l < r) {
            int mid = l + (r - l) / 2;
            if (nums[mid] >= target) {
                r = mid;
            } else  {
                l = mid + 1;
            }
        }
        return l;
    }
    int upper_bound(vector<int>& nums, int target) {
        const int N = nums.size();
        // [l, r)
        int l = 0, r = N;
        while (l < r) {
            int mid = l + (r - l) / 2;
            if (nums[mid] <= target) {
                l = mid + 1;
            } else {
                r = mid;
            }
        }
        return l;
    }
};


//leetcode--69--Easy
//返回非负整数的算术平方根--只保留整数部分

class Solution {
public:
    int mySqrt(int x) {
        int left = 0,right = x;
        while(left < right) {
            int mid = left+(right-left)/2+1;
            if(mid > x/mid)
                right = mid-1;
            else
                left = mid;
        }
        return left;
    }
};

