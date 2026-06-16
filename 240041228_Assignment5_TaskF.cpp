#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin >> t;

    while(t--)
    {
        long long n, x;
        cin >> n >> x;

        long long nums[n];
        for(int i = 0; i < n; i++) cin >> nums[i];

        sort(nums, nums + n);

        long long left = nums[0], right = nums[n - 1] + x;

        while(left <= right)
        {
            long long height = (left + right) / 2;

            long long req = 0;
            for(int i = 0; i < n; i++)
            {
                if(nums[i] >= height) break;

                req += (height - nums[i]);
            } 

            if(req == x)
            {
                right = height;
                break;
            }
            else if(req > x) right = height - 1;
            else left = height + 1;
        }

        cout << right << endl;
    }
}