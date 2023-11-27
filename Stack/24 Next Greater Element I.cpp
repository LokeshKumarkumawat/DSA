
496. Next Greater Element I
https://leetcode.com/problems/next-greater-element-i/


class Solution
{
	public:
		vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2)
		{
			int m = nums2.size();
			unordered_map<int, int> mp;
			stack<int> s;
			for (int i = m - 1; i >= 0; i--)
			{
				if (s.size() == 0)
				{
					mp[nums2[i]] = -1;
				}
				else if (s.size() > 0 && s.top() > nums2[i])
				{
					mp[nums2[i]] = s.top();
				}
				else if (s.size() > 0 && s.top() <= nums2[i])
				{
					while (s.size() > 0 && s.top() <= nums2[i])
					{
						s.pop();
					}

					if (s.size() == 0)
					{
						mp[nums2[i]] = -1;
					}
					else
					{
						mp[nums2[i]] = s.top();
					}
				}

				s.push(nums2[i]);
			}

			vector<int> ans;
			for (auto i: nums1)
			{
				ans.push_back(mp[i]);
			}

			return ans;
		}
};