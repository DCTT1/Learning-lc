//双指针包括快慢指针和双向指针
//双向指针：就是两个指针相向而行 或 相背而行
//快慢指针：就是两个指针同向而行，一快一慢

数组---2

//LeetCode--27--Esay
//给一个数组 nums 和一个值 val，原地移除所有数值等于 val 的元素，并返回移除后数组的新长度。

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int slow = 0,fast = 0;
        for(fast = 0;fast < nums.size(); fast++) {
            if(nums[fast] != val)
                nums[slow++] = nums[fast];
        }
        return slow;
    }
};
//也可以使用双向指针
class Solution {
public:
	int removeElement(vector<int>& nums, int val) {
		int left = 0;
		int right = nums.size()-1;
		while(left <= right) {
			while(left<= right && nums[left] != val)
				++left;
			while(left<= right && nums[right] != val)
				--right;
			if(left < right)
				nums[left++] = nums[right--];
		}
		return left;
	}	
};

//LeetCode--26---Easy
一个升序排列的数组nums ，原地删除重复出现的元素，使每个元素 只出现一次 ，返回删除后数组的新长度。元素的相对顺序应该保持 一致 。

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.empty())    return 0;
        int slow = 0;
        for(int fast = 0;fast < (nums.size()-1); fast++) {
            if(nums[fast] != nums[fast+1])
                nums[++slow] = nums[fast+1];
        }
        return slow+1;
    }
};
//或者换一种形式的双指针//
class Solution {
public:
	int removeDuplicates(vector<int>& nums) {
		if (nums.size() < 2) return nums.size();
		int j = 0;
		for (int i = 1; i < nums.size(); i++)
			if (nums[j] != nums[i]) 
				nums[++j] = nums[i];
		return ++j;
 	}
};


/LeetCode--80---Middle
一个升序排列的数组nums ，原地删除重复出现的元素，使每个元素 最多出现两次 ，返回删除后数组的新长度。元素的相对顺序应该保持 一致 。
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size() < 2)
            return nums.size();
        int k=1,count = 1;
        for(int i=1;i<nums.size(); i++) {
            if(nums[i] == nums[i-1]) {
                count ++;
                if(count <3) {
                    if(k != 1)
                        nums[k] = nums[i];
                    k++;
                }
            }
            else {
                count = 1;
                nums[k] = nums[i];
                k++;
            }
        }
        return k;
    }
};


//LeetCode---283---Easy
//给定一个数组nums，编写函数将所有的0移到数组末尾，同时保存非零元素的相对顺序
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int slow = 0,fast = 0;
        for(slow = 0;slow<nums.size();slow++) {
            if(nums[slow] != 0)
                nums[fast++] = nums[slow];
        }
        while(fast<nums.size())
            nums[fast++] = 0;
    }    
};

//Leetcode--844---Easy
//给定s和t两个字符串,当它们分别被输入到空白的文本编辑器后，如果两者相等，返回tru.    # 代表退格字符。
class Solution {
private:
    void count(const string &x, int &i, int &b) {
        while(i >= 0) {
            if(x[i] == '#') b++;
            else if(b)  b--;
            else break;
            i--;
        }
    }
public:
    bool backspaceCompare(string s, string t) {
        int i = s.size()-1, j = t.size()-1;
        int bs = 0,bt = 0;
        while(i >= 0 || j>=0) {
            count(s,i,bs);
            count(t,j,bt);
            if(i<0 || j<0)  break;
            if(s[i--] != t[j--])    return false;
        }
        return i<0 &&j<0;
    }
};

//这题使用栈效果也很不错，如果它是退格符，那么我们将栈顶弹出如果它是普通字符，那么我们将其压入栈中。
class Solution {
public:
    bool backspaceCompare(string S, string T) {
        return build(S) == build(T);
    }

    string build(string str) {
        string ret;
        for (char ch : str) {
            if (ch != '#') {
                ret.push_back(ch);
            } else if (!ret.empty()) {
                ret.pop_back();
            }
        }
        return ret;
    }
};


//LeetCode--977---Easy
//一个按非递减顺序排序的整数数组 nums，
返回每个数字的平方组成的新数组，要求也按非递减顺序排序。
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int right = nums.size()-1;
        vector<int> result(nums.size(), 0);
        for(int i=0,j = right; i <= j;) {
            if(nums[i]*nums[i] < nums[j]*nums[j]) {
                result[right--] = nums[j]*nums[j];
                j--;
            }
            else {
                result[right--] = nums[i]*nums[i];
                i++;
            }
        }
        return result;
    }
};
