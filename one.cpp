#include <bits/stdc++.h>
using namespace std;

int upper(int a[], int n, int key)
{
    int index = 0;
    bool flag = 0;
    for (int i = 0; i < n; i++)
    {
        if (key == a[i])
        {
            flag = 1;
            index = i + 1;
        }
    }
    if (flag)
    {
        int x = index+1;
        for (int i = x ; i < n; i++)
        {
            if (a[i] == a[index])
            {
                index = i;
            }
            else
            {
                break;
            }
        }
        return index;
    }
    bool flag2 = 0;
    for (int i = 1; i < n; i++)
    {
        if (a[i - 1] < key and a[i + 1] > key)
        {
            flag2 = 1;
            index = i + 1;
            break;
        }
    }
    if (flag2)
    {
        int x = index;
        for (int i = x + 1; i < n; i++)
        {
            if (a[i] == a[index])
            {
                index = i;
            }
        }
        return index;
    }
    return 0;
}

int lower(int a[], int n, int key)
{
    int index = 0;
    bool flag = 0;
    if (a[0] == key)
    {
        return 0;
    }
    for (int i = 1; i < n; i++)
    {
        if (key == a[i])
        {
            flag = 1;
            index = i;
            return index;
        }
    }
    if (!flag)
    {
        int x = index;
        bool check = 0;
        for (int i = n - 1; i >= 0; i--)
        {
            if (a[i] < key)
            {
                index = i;
                if (a[i - 1] == a[i])
                {
                    check = 1;
                }
                break;
            }
        }
        if (!check)
        {
            return index;
        }

        x = index;
        bool flag2 = 0;
        for (int i = x; i > 0; i--)
        {
            if (a[i] == a[i - 1])
            {
                index = i;
            }
            else
            {
                break;
            }
        }
        return index - 1;
    }
    return 0;
}

int main()
{
    int n, s;
    cin >> n >> s;
    int A[n + 2];
    for (int i = 0; i < n; i++)
    {
        cin >> A[i];
    }
    cout << upper(A, n, s) << " " << lower(A, n, s) << endl;
}
/* 
in:
8 12
1 3 5 5 5 7 9 10
out: 8 7
*/
