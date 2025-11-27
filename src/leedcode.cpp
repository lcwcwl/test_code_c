#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<math.h>
#include <unordered_map>
#include<queue>
#include <opencv2/opencv.hpp>
using namespace std;
using namespace cv;
//// 两数之和
//class Solution 
//{
//public:
//	vector<int> twoSum(vector<int>& nums, int target)
//	{
//		sort(nums.begin(), nums.end());
//		for (int i = 0; i++; i < nums.size())
//		{
//			std::cout << nums[i] << std::endl;
//		}
//		int i = 0;
//		int j = nums.size() - 1;
//		//cout << j << endl;
//		vector<int > res;
//		while (i < j)
//		{
//			int sum = nums[i] + nums[j];
//			if (sum < target)
//			{
//				i++;
//			}
//			else if (sum > target)
//			{
//				j--;
//			}
//			else
//			{
//				res.push_back(i);
//				res.push_back(j);
//				break;
//			}
//
//		}
//		return res;
//	}
//};
//int main()
//{
//	vector<int > nums = { 2,7,11,15 };
//	int target = 9;
//	Solution *solve = new Solution();
//	vector<int > res = solve->twoSum(nums,target);
//	for (int i = 0; i < res.size(); i++)
//	{
//		cout << res[i] << endl;
//	}
//	return 0;
//}

// leedcode 633
//class Solution {
//public:
//	bool judgeSquareSum(int c) {
//		int left = 0;
//		int right = int(sqrt(c)) + 1;
//		while (left<=right)
//		{
//			int sum = left * left + right * right;
//			if ( sum == c)
//				return true;
//			else if (sum < c)
//			{
//				left++;
//			}
//			else
//			{
//				right--;
//			}
//		}
//		return false;
//	}
//};
//int main()
//{
//	Solution *solve = new Solution();
//	int c = 5;
//	bool res = solve->judgeSquareSum(c);
//	std::cout << res << std::endl;
//	return 0;
//}

//// leedcode 88
//class Solution {
//public:
//	void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
//		int index_1 = m - 1;
//		int index_2 = n - 1;
//		int num_merge = m + n - 1;
//		while (index_1 >=0 || index_2 >=0)
//		{
//			if (index_1 < 0)
//				nums1[num_merge--] = nums2[index_2--];
//			else if (index_2 < 0)
//				nums1[num_merge--] = nums1[index_1--];
//			else if (nums1[index_1] <= nums2[index_2])
//				nums1[num_merge--] = nums2[index_2--];
//			else
//				nums1[num_merge--] = nums1[index_1--];
//		}
//	}
//};

//class Solution {
//public:
//	int findNthDigit(int n) {
//		//记录n是几位数
//		int digit = 1;
//		//记录当前位数区间的起始数字：1,10,100...
//		long long start = 1;
//		//记录当前区间之前总共有多少位数字
//		long long sum = 9;
//		//将n定位在某个位数的区间中
//		while (n > sum) {
//			n -= sum;
//			start *= 10;
//			digit++;
//			//该区间的总共位数
//			sum = 9 * start * digit;
//		}
//		//定位n在哪个数字上
//		int num = start + (n - 1) / digit;
//		//定位n在数字的哪一位上
//		int index = (n - 1) % digit;
//		return to_string(num)[index] - '0';
//	}
//
//	int findNthDigit_test(int n) {
//		int i = 1;
//		while (i * pow(10,i)<n)
//		{
//			n = n + pow(10, i);
//			i++;
//		}
//		int num = n / i;
//		int index = n % i;
//		int res = to_string(num)[index] - '0';
//		return res;
//	}
//};

//class Solution {
//public:
//	int FirstNotRepeatingChar0(string str) {
//		unordered_map<char, int> mp;
//		for (int i = 0; i < str.length(); i++)
//		{
//			mp[str[i]]++;
//		}
//		for (int i = 0; i < str.length(); i++)
//		{
//			if (mp[i] == 1)
//				return i;
//
//		}
//		return -1;
//
//
//	}
//
//	int FirstNotRepeatingChar1(string str)
//	{
//		unordered_map<char, int> mp;
//		queue<pair<char, int> > q;
//		for (int i = 0; i < str.length(); i++)
//		{
//			if (!mp.count(str[i]))
//			{
//				mp[str[i]] = i;
//				q.push(make_pair(str[i],i));
//			}
//			else
//			{
//
//				mp[str[i]] = -1;
//				while (!q.empty() && mp[q.front().first] == -1)
//				{
//					q.pop();
//				}
//			}
//			
//		}
//		if (q.empty())
//			return -1;
//		return q.front().second;
//	}
//};


//struct ListNode {
//	int val;
//	struct ListNode *next;
//	ListNode(int x) :
//			val(x), next(NULL) {
//	}
//};
//class Solution {
//public:
//	ListNode* FindFirstCommonNode(ListNode* pHead1, ListNode* pHead2) {
//		int length1 = get_length(pHead1);
//		int length2 = get_length(pHead2);
//		while (length1 != length2) {
//			if (length1 < length2) {
//				pHead2 = pHead2->next;
//				length2--;
//			}
//			else {
//				pHead1 = pHead1->next;
//				length1--;
//			}
//		}
//		while (pHead1 != pHead2) {
//			pHead1 = pHead1->next;
//			pHead2 = pHead2->next;
//		}
//		return pHead1;
//	}
//	int get_length(ListNode* pHead) {
//		int length = 0;
//		while (pHead) {
//			length++;
//			pHead = pHead->next;
//		}
//		return length;
//	}
//};


class Solution {
public:
	int get_left_right(vector<int> &data, float k) {
		int left = 0;
		int right = data.size() - 1;
		while (left<=right)
		{
			int mid = (left + right) / 2;
			if (data[mid] < k) {
				left = mid + 1;
			}
			else
			{
				right = mid - 1;
			}
		}
		return left;
	}
	int GetNumberOfK(vector<int> data, int k) {
		int left = get_left_right(data, k - 0.5);
		int right = get_left_right(data, k + 0.5);
		return right - left;
	}
};

int main()
{
	Solution* solve = new Solution();
	vector<int > data = { 1,2,3,3,3,3,4,5};
	int k = 3;
	int res = solve->GetNumberOfK(data,k);
	std::cout << res << std::endl;
	delete solve;
	solve = nullptr;
	//Mat img;
	//// 读取图像
	//img = imread("D:\\lcw_data\\data_a\\文件资料\\个人资料\\个人简历+照片\\照片2.jpg", 1); // 1-RGB、0-gray
	//// 创建一个名为 "beautiful"窗口
	//namedWindow("beautiful", CV_WINDOW_NORMAL);
	//// 在窗口中显示“beautiful”窗口
	//imshow("beautiful", img);
	//// 等待6000 ms后窗口自动关闭
	//waitKey(6000);
	//system("pause");
	return 0;
}