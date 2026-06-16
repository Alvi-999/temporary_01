#include <bits/stdc++.h>

using namespace std;

int upperBound(long long arr[], int n, long long target)
{
    int left = 0, right = n - 1;    

    int ans = n;
    while(left <= right)
    {
        int mid = (left + right) / 2;

        if(arr[mid] > target)
        {
            ans = mid;
            right = mid - 1;
        }
        else left = mid + 1;
    }

    return ans;
}


int lowerBound(long long arr[], int n, long long target)
{
    int left = 0, right = n - 1;    

    int ans = n;
    while(left <= right)
    {
        int mid = (left + right) / 2;

        if(arr[mid] >= target)
        {
            ans = mid;
            right = mid - 1;
        }
        else left = mid + 1;
    }

    return ans;
}

long long binSearch(long long arr[], long long n,int ign, long long target)
{
    int up = upperBound(arr, n, target);
    int low = lowerBound(arr, n, target);
    
    int ans = up - low;

    if((ign >= low) && (ign < up)) ans--;

    return ans;
}

int main()
{
    int t;
    scanf("%d", &t);

    while(t--)
    {
        long long n, x;
        cin >> n >> x;

        long long nums[n];
        for(int i = 0; i < n; i++) scanf("%lld", &nums[i]);

        sort(nums, nums + n);
        
        long long ans = 0;
        for(int i = 0; i < n; i++) ans += binSearch(nums, n, i, x - nums[i]);

        cout << ans / 2 << endl;
    }
}