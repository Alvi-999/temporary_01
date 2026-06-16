#include <bits/stdc++.h>

using namespace std;

int indLeft(int arr[], int n, int target)
{
    int left = 0, right = n - 1;

    int ans = n;
    while(left <= right)
    {
        int mid = (right + left) / 2;

        if(arr[mid] == target)
        {
            ans = mid;
            right = mid - 1; 
        }
        else if(arr[mid] > target) right = mid - 1;
        else left = mid + 1;
    }

    return ans;
}

int indRight(int arr[], int n, int target)
{
    int left = 0, right = n - 1;

    int ans = n;
    while(left <= right)
    {
        int mid = (right + left) / 2;

        if(arr[mid] >= target)
        {
            ans = mid;
            right = mid - 1; 
        }
        else left = mid + 1;
    }

    if(ans == n) return -1;
    else return ans;


}

int main()
{
    int n, q;
    cin >> n >> q;

    int nums[n];
    for(int i = 0; i < n; i++) cin >> nums[i];

    sort(nums, nums + n);

    while(q--)
    {
        int left = 0, right = n - 1;

        int l, r;
        scanf("%d %d", &l, &r);

        int start = indLeft(nums, n, l);
        int end = indRight(nums, n, r);

        cout << end - start << endl;
    }
}