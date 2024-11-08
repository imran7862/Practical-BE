#include <iostream>
using namespace std;
int knapsack_DP(int *weight, int *profit, int w, int n)
{
    int **t;
    t = new int *[n + 1];
    for (int i = 0; i <= n; i++)
    {
        t[i] = new int[w + 1];
    }

    for (int i = 0; i <= n; i++)
    {
        t[i][0] = 0;
    }

    for (int i = 0; i <= w; i++)
    {
        t[0][i] = 0;
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= w;j++)
        {
            if(weight[i-1]<=j)
            {
                int res1,res2;
                res1=profit[i-1]+t[i-1][j-weight[i-1]];
                res2=t[i-1][j];
                t[i][j]=max(res1,res2);
            
            }
            else
            {
                t[i][j]=t[i-1][j];
            }
        }
    }
    return t[n][w];
}
int main()
{
    int n, w;
    cout << "how many objects are there " << endl;
    cin >> n;
    int *weight = new int[n];
    int *profit = new int[n];
    cout << "Enter the weight of " << n << " objects " << endl;

    for (int i = 0; i < n; i++)
    {
        cin >> weight[i];
    }
    cout << "Enter the profit of " << n << " objects " << endl;

    for (int i = 0; i < n; i++)
    {
        cin >> profit[i];
    }

    cout << "Enter the weight of knapsack" << endl;
    cin >> w;

    int ans = knapsack_DP(weight, profit, w, n);
    cout << ans << endl;
}


