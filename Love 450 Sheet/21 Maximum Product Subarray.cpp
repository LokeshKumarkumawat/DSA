int maximumProduct(vector<int> &arr, int n)
{
	// Write your code here
	if (n == 1)
		return arr[0];

	int min1 = arr[0];
	int max1 = arr[0];
	int res = arr[0];
	for (int i = 1; i < n; i++)
	{
		if (arr[i] < 0)
		{
			swap(max1, min1);
		}

		max1 = max(arr[i], max1 *arr[i]);
		min1 = min(arr[i], min1 *arr[i]);

		if (res < max1)
			res = max1;

	}

	return res;
}


#include <bits/stdc++.h>

int lengthOfLongestConsecutiveSequence(vector<int> &arr, int n)
{
	// Write your code here.
	if (n == 0)
		return 0;

	sort(arr.begin(), arr.end());

	int maxCount = 1;
	int count = 1;

	int curr = arr[0];
	for (int i = 1; i < n; i++)
	{
		if (arr[i] == curr + 1)
		{
			count++;
		}
		else if (arr[i] != curr)
		{
			count = 1;
		}

		curr = arr[i];
		maxCount = max(maxCount, count);
	}

	return maxCount;
}