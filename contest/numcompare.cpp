#include<stdio.h>
#include<vector>
#include<iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;
    while(n--)
    {
        int  size;
        vector<int> res;
        int a;
        cin >> size;
        while(size--)
        {
            cin >> a;
            res.push_back(a);
        }
        int num = res[0];
        int count = 1;
        for(int i = 1; i < res.size(); i++)
        {
            if(res[i] == num)
            {
                count += 1;
            }
            else
            {
                num = res[i];
            }
        }
        cout << count << "\n";
    }
    return 0;
}