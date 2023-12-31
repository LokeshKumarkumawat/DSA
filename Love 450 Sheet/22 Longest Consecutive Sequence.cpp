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