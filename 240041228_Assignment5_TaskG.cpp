#include <bits/stdc++.h>

using namespace std;

bool dec(int pos[], int n, int cows, int dist)
{
    int placed = 1;
    int last = pos[0];

    for(int i = 1; i < n; i++)
    {
        if(pos[i] - last >= dist)
        {
            placed++;
            last = pos[i];

            if(placed == cows) return true;
        }
    }

    return false;
}

int main()
{
    int t;
    cin >> t;

    while(t--)
    {
        int n, c;
        cin >> n >> c;

        int pos[n];

        for(int i = 0; i < n; i++) cin >> pos[i];

        sort(pos, pos + n);

        int left = 0, right = pos[n - 1] - pos[0], ans = 0;

        while(left <= right)
        {
            int mid = (right + left) / 2;

            if(dec(pos, n, c, mid))
            {
                ans = mid;
                left = mid + 1;
            }
            else
            {
                right = mid - 1;
            }
        }

        cout << ans << endl;
    }
}