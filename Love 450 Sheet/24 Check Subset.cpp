#include <bits/stdc++.h>

bool checkSubset(vector<int> &arr1, vector<int> &arr2, int n, int m)
{
    // Write your code here.
    sort(arr2.begin(), arr2.end());
    sort(arr1.begin(), arr1.end());
    if (m > n)
    {
        return false;
    }

    int found = 0, j = 0, start = 0;
    while (start < n)
    {
        if (arr2[j] == arr1[start])
        {
            found++;
            j++;
            start++;
            if (found == m)
                break;
        }
        else
            start++;
    }

    if (found == m)
        return true;
    else
        return false;
}