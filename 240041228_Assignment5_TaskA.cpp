#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin >> t;

    while(t--)
    {
        double n;
        cin >> n;

        double left = 0, right = n;

        bool printed = false;
        while((right - left) > 1e-4)
        {
            float mid = (left + right) / 2.0;

            if((mid * mid * mid) > n) right = mid;
            else left = mid;
        }

        cout << fixed << setprecision(3) << left << endl; 
    }
}