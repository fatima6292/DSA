#include <iostream>
#include <stack>
#include<queue>
using namespace std;

class Point {
public:
    int row;
    int col;
    bool operator == (Point rhs) {
        return (row == rhs.row && col == rhs.col);
    }
    bool operator != (Point rhs) {
        return (row != rhs.row || col != rhs.col);
    }
    Point()
    {
        row = 0;
        col = 0;
    }
};

void Maze(int arr[][5], int size=5)
{
    stack<Point>s;
    Point temp;
    Point start, end;
    cout << "Enter start: ";
    cin >> start.row;
    cin >> start.col;
    cout << "Enter end: ";
    cin >> end.row;
    cin >> end.col;
    int i = start.row;
    int j = start.col;
    bool flag=true;
    s.push(start);
    while (start != end)
    {
        if (i + 1 < size  && arr[i + 1][j] == 0)
        {
            arr[i][j] = 3;
            i++;
            start.row = i;
            start.col = j;
            s.push(start);
        }
        else if (j + 1 < size  && arr[i][j + 1] == 0)
        {
            arr[i][j] = 3;
            j++;
            start.row = i;
            start.col = j;
            s.push(start);
        }
        else if (i - 1 >= 0 && arr[i - 1][j] == 0)
        {
            arr[i][j] = 3;
            i--;
            start.row = i;
            start.col = j;
            s.push(start);
        }
        else if (j - 1 >= 0 && arr[i][j - 1] == 0)
        {
            arr[i][j] = 3;
            j--;
            start.row = i;
            start.col = j;
            s.push(start);
        }
        else
        {
            if (!s.empty()) 
            {
                start = s.top();
                i = start.row;
                j = start.col;
                if (arr[i][j] == 2)
                {
                    s.pop();
                    start = s.top();
                    i = start.row;
                    j = start.col;
                }
                arr[i][j] = 2;
                
            }
            else 
            {
                cout << "Path not found";
                flag=false;
                break;
            }
            
        }
    }
    if (flag)
    {
        cout << "Path found"<<endl;
        stack<Point>q;
        while (!s.empty())
        {
            start = s.top();
            q.push(start);
            s.pop();
        }
      
            while (!q.empty())
            {
                start = q.top();
                q.pop();
                cout << start.row << "," << start.col << endl;
            }
    }
}
int main()
{
    int maze[5][5];
        for (int i = 0; i < 5; i++)
        {
            for (int j = 0; j < 5; j++)
            {
                cin >> maze[i][j];
            }cout << endl;
        }

        for (int i = 0; i < 5; i++)
        {
            for (int j = 0; j < 5; j++)
            {
                cout<< maze[i][j]<<" ";
            }cout << endl;
        }

        Maze (maze, 5);

        return 0;
}