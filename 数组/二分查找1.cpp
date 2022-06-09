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
