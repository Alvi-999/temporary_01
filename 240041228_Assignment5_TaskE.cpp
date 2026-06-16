#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin >> t;

    while(t--)
    {
        long long n;
        cin >> n;

        long long left = 0, right = 2 * pow(10, 9);
        long long ans = -1;

        while(left <= right)
        {
            long long mid = (left + right) / 2;

            long long total = mid * (mid + 1) / 2;

            if(total <= n)
            {
                ans = mid;
                left = mid + 1;
            }
            else right = mid - 1;
        }

        cout << ans << endl;
    }
}