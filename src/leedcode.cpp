#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<math.h>
#include <unordered_map>
#include<queue>
#include<opencv2/opencv.hpp>
using namespace std;
using namespace cv;

//// 两数之和（注意：排序后索引会变化，此版本仅演示双指针，实际LeetCode需返回原索引）
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        // 修复循环条件：原i++会导致跳过第一个元素，改为i < nums.size(); i++
        for (int i = 0; i < nums.size(); i++) {
            std::cout << nums[i] << std::endl;
        }
        int i = 0;
        int j = nums.size() - 1;
        vector<int> res;
        while (i < j) {
            int sum = nums[i] + nums[j];
            if (sum < target) {
                i++;
            } else if (sum > target) {
                j--;
            } else {
                res.push_back(i);
                res.push_back(j);
                break;
            }
        }
        return res;
    }
};

// int main()
// {
//     vector<int> nums = {2,7,11,15};
//     int target = 9;
//     Solution *solve = new Solution();
//     vector<int> res = solve->twoSum(nums,target);
//     for (int i = 0; i < res.size(); i++)
//     {
//         cout << res[i] << endl;
//     }
//     delete solve; // 修复内存泄漏：添加delete
//     solve = nullptr;
//     return 0;
// }

// leetcode 633：平方数之和
class Solution633 {
public:
    bool judgeSquareSum(int c) {
        int left = 0;
        int right = int(sqrt(c)) + 1;
        while (left <= right) {
            // 修复溢出风险：用long long存储平方和
            long long sum = (long long)left * left + (long long)right * right;
            if (sum == c)
                return true;
            else if (sum < c) {
                left++;
            } else {
                right--;
            }
        }
        return false;
    }
};
// int main()
// {
//     Solution633 *solve = new Solution633();
//     int c = 5;
//     bool res = solve->judgeSquareSum(c);
//     std::cout << (res ? "true" : "false") << std::endl; // 优化输出：显示true/false而非1/0
//     delete solve;
//     solve = nullptr;
//     return 0;
// }

// leetcode 88：合并两个有序数组
class Solution88 {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int index_1 = m - 1;
        int index_2 = n - 1;
        int num_merge = m + n - 1;
        while (index_1 >= 0 || index_2 >= 0) {
            if (index_1 < 0)
                nums1[num_merge--] = nums2[index_2--];
            else if (index_2 < 0)
                nums1[num_merge--] = nums1[index_1--];
            else if (nums1[index_1] <= nums2[index_2])
                nums1[num_merge--] = nums2[index_2--];
            else
                nums1[num_merge--] = nums1[index_1--];
        }
    }
};

// 找到第n位数字
class SolutionNthDigit {
public:
    int findNthDigit(int n) {
        // 记录n所在的位数（1位、2位、3位...）
        int digit = 1;
        // 记录当前位数的起始数字（1, 10, 100...）
        long long start = 1;
        // 记录当前位数之前所有数字的总位数
        long long sum = 9;
        // 确定n在某一位数的范围内
        while (n > sum) {
            n -= sum;
            start *= 10;
            digit++;
            // 计算当前位数的数字总位数（9*起始数*位数）
            sum = 9 * start * digit;
        }
        // 确定n对应的具体数字
        int num = start + (n - 1) / digit;
        // 确定n在该数字中的第几位
        int index = (n - 1) % digit;
        return to_string(num)[index] - '0';
    }

    int findNthDigit_test(int n) {
        int i = 1;
        while (i * pow(10, i) < n) {
            n = n + pow(10, i);
            i++;
        }
        int num = n / i;
        int index = n % i;
        return to_string(num)[index] - '0';
    }
};

// 第一个只出现一次的字符
class SolutionFirstUnique {
public:
    int FirstNotRepeatingChar0(string str) {
        unordered_map<char, int> mp;
        for (int i = 0; i < str.length(); i++) {
            mp[str[i]]++;
        }
        // 修复逻辑错误：原mp[i]改为mp[str[i]]（i是索引，str[i]才是字符）
        for (int i = 0; i < str.length(); i++) {
            if (mp[str[i]] == 1)
                return i;
        }
        return -1;
    }

    int FirstNotRepeatingChar1(string str) {
        unordered_map<char, int> mp;
        queue<pair<char, int>> q;
        for (int i = 0; i < str.length(); i++) {
            if (!mp.count(str[i])) {
                mp[str[i]] = i;
                q.push(make_pair(str[i], i));
            } else {
                mp[str[i]] = -1;
                while (!q.empty() && mp[q.front().first] == -1) {
                    q.pop();
                }
            }
        }
        if (q.empty())
            return -1;
        return q.front().second;
    }
};

// 链表公共节点
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
class SolutionCommonNode {
public:
    ListNode* FindFirstCommonNode(ListNode* pHead1, ListNode* pHead2) {
        int length1 = get_length(pHead1);
        int length2 = get_length(pHead2);
        // 让长链表先走差值步，使两链表长度一致
        while (length1 != length2) {
            if (length1 < length2) {
                pHead2 = pHead2->next;
                length2--;
            } else {
                pHead1 = pHead1->next;
                length1--;
            }
        }
        // 同步遍历，找到第一个公共节点
        while (pHead1 != pHead2) {
            pHead1 = pHead1->next;
            pHead2 = pHead2->next;
        }
        return pHead1;
    }
private:
    int get_length(ListNode* pHead) {
        int length = 0;
        while (pHead) {
            length++;
            pHead = pHead->next;
        }
        return length;
    }
};

// 数字在排序数组中出现的次数
class SolutionCountK {
public:
    // 二分查找：找到第一个大于k的位置
    int get_left_right(vector<int> &data, float k) {
        int left = 0;
        int right = data.size() - 1;
        while (left <= right) {
            int mid = (left + right) / 2;
            if (data[mid] < k) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return left;
    }
    int GetNumberOfK(vector<int> data, int k) {
        // 找k-0.5的插入位置（第一个>=k的位置）
        int left = get_left_right(data, k - 0.5);
        // 找k+0.5的插入位置（第一个>k的位置）
        int right = get_left_right(data, k + 0.5);
        return right - left;
    }
};

int main()
{
    // 测试数字出现次数（输出应为4）
    SolutionCountK* solve = new SolutionCountK();
    vector<int> data = {1,2,3,3,3,3,4,5};
    int k = 3;
    int res = solve->GetNumberOfK(data, k);
    std::cout << "数字" << k << "出现的次数：" << res << std::endl;
    delete solve;
    solve = nullptr;

    // 以下是OpenCV相关代码（需配置OpenCV环境才能运行，按需启用）
    // Mat img;
    // // 读取图片（替换为你的图片路径）
    // img = imread("D:\\lcw_data\\data_a\\测试数据\\示例图片\\风景图+图片\\图片2.jpg", 1); // 1-RGB模式，0-灰度模式
    // // 创建一个名为 "beautiful" 的窗口
    // namedWindow("beautiful", CV_WINDOW_NORMAL);
    // // 在beautiful窗口中显示图片
    // imshow("beautiful", img);
    // // 等待6000毫秒后窗口自动关闭（0表示无限等待，按任意键关闭）
    // waitKey(6000);
    // destroyAllWindows(); // 释放窗口资源

    return 0;
}