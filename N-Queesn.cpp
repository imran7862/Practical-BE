#include<iostream>
#include<vector>
using namespace std;

bool safe(int row,int col,vector<string>&board,int n)
{
    int rowdummy=row;
    int coldummy=col;
    
    while(col>=0 && row>=0)
    {
        if(board[row][col]=='Q')
        {
            return false;
        }


        col--;
        row--;
    }

    row=rowdummy;
    col=coldummy;

    while(col>=0)
    {
        if(board[row][col]=='Q')
        {
            return false;
        }


        col--;
    }

    row=rowdummy;
    col=coldummy;


    while(row<n && col>=0)
    {

        if(board[row][col]=='Q')
        {
            return false;
        }

        row++;
        col--;
        
    }

    return true;
}


void solution(int col,vector<vector<string>>&ans,vector<string>&board,int n)
{
    if(col==n)
    {
        ans.push_back(board);
        return;
    }
    else
    {
        for(int row=0; row<n ; row++)
        {
            if(safe(row,col,board,n))
            {
                board[row][col]='Q';
                solution(col+1,ans,board,n);
                board[row][col]='_';
            }
        }
    }
}
int main()
{
    int n;
    cout<<"Enter the size of board"<<endl;
    cin>>n;
    vector<vector<string>>ans;
    vector<string>board(n);

    string s(n,'_');

    for(int i=0; i<n; i++)
    {
        board[i]=s;
    }

    solution(0,ans,board,n);

    for(int i=0; i<ans.size(); i++)
    {
        for(int j=0; j<n; j++)
        {
            cout<<ans[i][j]<<endl;
        }

        cout<<endl;
    }

    
}