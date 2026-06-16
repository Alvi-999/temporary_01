#include <bits/stdc++.h>

using namespace std;

int searchBin(long long arr[], int n, int curr, long long target)
{
    int left = 0, right = n - 1;

    while(left <= right)
    {
        int mid = (left + right) / 2;

        if(arr[mid] == target)
        {
            if(mid == curr) 
            {
                if(((mid - 1) >= 0) && (arr[mid - 1] == target)) return 1;
                else if(((mid + 1) < n) && (arr[mid + 1] == target)) return 1;
                else return 0;
            }
            else return 1;
        }

        if(arr[mid] < target) left = mid + 1;
        else right = mid - 1;
    }

    return 0;
}

int main()
{
    int t;
    scanf("%d", &t);

    while(t--)
    {
        long long n, x;
        scanf("%lld %lld", &n, &x);

        long long nums[n];
        for(int i = 0; i < n; i++) scanf("%lld", &nums[i]);

        sort(nums, nums + n);

        int dec = 0;
        for(int i = 0; i < n; i++)
        {
            dec = searchBin(nums, n, i, x - nums[i]);

            if(dec) break;
        }

        dec ? cout << "YES" : cout << "NO";
        cout << endl;
    }
}