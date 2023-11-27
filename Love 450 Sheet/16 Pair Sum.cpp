int pairSum(vector<int> &arr, int n, int target)
{
    int i = 0;
    int j = n - 1;
    int ans = 0;
    while (i < j)
    {
        if (arr[i] + arr[j] == target)
        {
            i++;
            j--;
            ans++;
        }
        else if (arr[i] + arr[j] < target)
        {
            i++;
        }
        else
        {
            j--;
        }
    }

    if (ans == 0)
        return -1;
    return ans;
}