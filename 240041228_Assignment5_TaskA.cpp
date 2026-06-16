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

        long double left = 0, right = 1e6;

        bool printed = false;
        while((right - left) > 1e-7)
        {
            long double mid = (left + right) / 2.0;

            if((mid * mid * mid) >= (long double)n) right = mid;
            else left = mid;
        }

        cout << fixed << setprecision(3) << left << endl; 
    }
}