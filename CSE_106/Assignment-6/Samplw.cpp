#include <iostream>
// #include "BFSmap.cpp"
#include <bits/stdc++.h>

using namespace std;

int n, m, q;

class Rider
{
private:
    int x;
    int y;
    int k;

public:
    // Rider(int x, int y, int k)
    // {
    //     this->x = x;
    //     this->y = y;
    //     this->k = k;
    // }
    Rider()
    {
        this->x = 0;
        this->y = 0;
        this->k = 0;
    }
    int getx()
    {
        return this->x;
    }
    int gety()
    {
        return this->y;
    }
    int getk()
    {
        return this->k;
    }

    void setx(int x)
    {
        this->x = x;
    }
    void sety(int y)
    {
        this->y = y;
    }
    void setk(int k)
    {
        this->k = k;
    }
    // void print()
    // {
    //     cout << x << "," << y << "," << k << endl;
    // }

    // bool operator<(const Rider &obj) const
    // {
    //     if (x < obj.x && y < obj.y)
    //     {
    //         return true;
    //     }
    //     return false;
    // }
};

bool isinboundary(int x, int y)
{
    return (x >= 0 && x < n) && (y >= 0 && y < m);
}

class Point
{
public:
    int x;
    int y;
    Point(int x, int y)
    {
        this->x = x;
        this->y = y;
    }
    Point()
    {
        this->x = 0;
        this->y = 0;
    }

    // void setval(int x,int y)
    // {
    //     this->x=x;
    //     this->y=y;
    // }
    // void print()
    // {
    //     cout << x << "," << y << "," << endl;
    // }

    // bool operator<(const Point &obj) const
    // {
    //     if (x < obj.x && y < obj.y)
    //     {
    //         return true;
    //     }
    //     return false;
    // }
};

int main()
{

    FILE *fp1 = freopen("in.txt", "r", stdin);

    cin >> n >> m >> q;
    Rider rider[q];
    for (int i = 0; i < q; i++)
    {
        int x, y, k;
        cin >> x >> y >> k;
        rider[i].setx(x);
        rider[i].sety(y);
        rider[i].setk(k);
        // cout<<rider[i].getx()<<","<<rider[i].gety()<<","<<rider[i].getk()<<endl;
    }
    int result[n][m];
    int depth[q][n][m];
    memset(depth, -1, sizeof(depth));
    memset(result, 0, sizeof(result));
    for (int i = 0; i < q; i++)
    {
        bool isvisited[n][m];

        memset(isvisited, false, sizeof(isvisited));

        queue<Point> checking;
        Point temppoint;
        temppoint.x = rider[i].getx();
        temppoint.y = rider[i].gety();
        depth[i][temppoint.x][temppoint.y] = 0;
        isvisited[temppoint.x][temppoint.y] = true;
        checking.push(temppoint);

        while (!checking.empty())
        {
            Point currPoint = checking.front();
            checking.pop();
            int temp_x, temp_y;

            temp_x = currPoint.x + 2;
            temp_y = currPoint.y + 1;
            if (isinboundary(temp_x, temp_y) && !isvisited[temp_x][temp_y])
            {
                depth[i][temp_x][temp_y] = depth[i][currPoint.x][currPoint.y] + 1;
                isvisited[temp_x][temp_y] = true;
                // temppoint.setval(temp_x,temp_y);
                temppoint.x = temp_x;
                temppoint.y = temp_y;
                checking.push(temppoint);
            }
            temp_x = currPoint.x + 2;
            temp_y = currPoint.y - 1;
            if (isinboundary(temp_x, temp_y) && !isvisited[temp_x][temp_y])
            {
                depth[i][temp_x][temp_y] = depth[i][currPoint.x][currPoint.y] + 1;
                isvisited[temp_x][temp_y] = true;
                // temppoint.setval(temp_x,temp_y);
                temppoint.x = temp_x;
                temppoint.y = temp_y;
                checking.push(temppoint);
            }
            temp_x = currPoint.x - 2;
            temp_y = currPoint.y + 1;
            if (isinboundary(temp_x, temp_y) && !isvisited[temp_x][temp_y])
            {
                depth[i][temp_x][temp_y] = depth[i][currPoint.x][currPoint.y] + 1;
                isvisited[temp_x][temp_y] = true;
                // temppoint.setval(temp_x,temp_y);
                temppoint.x = temp_x;
                temppoint.y = temp_y;
                checking.push(temppoint);
            }
            temp_x = currPoint.x - 2;
            temp_y = currPoint.y - 1;
            if (isinboundary(temp_x, temp_y) && !isvisited[temp_x][temp_y])
            {
                depth[i][temp_x][temp_y] = depth[i][currPoint.x][currPoint.y] + 1;
                isvisited[temp_x][temp_y] = true;
                // temppoint.setval(temp_x,temp_y);
                temppoint.x = temp_x;
                temppoint.y = temp_y;
                checking.push(temppoint);
            }
            temp_x = currPoint.x + 1;
            temp_y = currPoint.y + 2;
            if (isinboundary(temp_x, temp_y) && !isvisited[temp_x][temp_y])
            {
                depth[i][temp_x][temp_y] = depth[i][currPoint.x][currPoint.y] + 1;
                isvisited[temp_x][temp_y] = true;
                // temppoint.setval(temp_x,temp_y);
                temppoint.x = temp_x;
                temppoint.y = temp_y;
                checking.push(temppoint);
            }
            temp_x = currPoint.x + 1;
            temp_y = currPoint.y - 2;
            if (isinboundary(temp_x, temp_y) && !isvisited[temp_x][temp_y])
            {
                depth[i][temp_x][temp_y] = depth[i][currPoint.x][currPoint.y] + 1;
                isvisited[temp_x][temp_y] = true;
                // temppoint.setval(temp_x,temp_y);
                temppoint.x = temp_x;
                temppoint.y = temp_y;
                checking.push(temppoint);
            }
            temp_x = currPoint.x - 1;
            temp_y = currPoint.y + 2;
            if (isinboundary(temp_x, temp_y) && !isvisited[temp_x][temp_y])
            {
                depth[i][temp_x][temp_y] = depth[i][currPoint.x][currPoint.y] + 1;
                isvisited[temp_x][temp_y] = true;
                // temppoint.setval(temp_x,temp_y);
                temppoint.x = temp_x;
                temppoint.y = temp_y;
                checking.push(temppoint);
            }
            temp_x = currPoint.x - 1;
            temp_y = currPoint.y - 2;
            if (isinboundary(temp_x, temp_y) && !isvisited[temp_x][temp_y])
            {
                depth[i][temp_x][temp_y] = depth[i][currPoint.x][currPoint.y] + 1;
                isvisited[temp_x][temp_y] = true;
                // temppoint.setval(temp_x,temp_y);
                temppoint.x = temp_x;
                temppoint.y = temp_y;
                checking.push(temppoint);
            }
        }
        for (int row = 0; row < n; row++)
        {
            for (int col = 0; col < m; col++)
            {
                if (isvisited[row][col])
                {
                    // cout<<rider[i].getk()<<" ";
                    depth[i][row][col] = ceil((1.0 * depth[i][row][col]) / (rider[i].getk()));
                }
            }

            // cout<<endl;
        }
        // for (int row = 0; row < n; row++)
        // {
        //     for (int col = 0; col < m; col++)
        //     {
        //         // if(isvisited[row][col])
        //         cout << depth[i][row][col] << " ";
        //     }
        //     cout << endl;
        // }
    }
    // Depth checking ends.


    for (int a = 0; a < n; a++)
    {
        for (int b = 0; b < m; b++)
        {
            for (int c = 0; c < q; c++)
            {
                if (depth[c][a][b] == -1)
                {
                    result[a][b] = INT_MAX;
                    break;
                }
                else
                {
                    result[a][b] += depth[c][a][b];
                }
            }
        }
    }

    // for (int row = 0; row < n; row++)
    // {
    //     for (int col = 0; col < m; col++)
    //     {
    //         cout << result[row][col] << " ";
    //     }
    //     cout << endl;
    // }

    int shortestmove = INT_MAX;
    for (int row = 0; row < n; row++)
    {
        for (int col = 0; col < m; col++)
        {
            if (shortestmove > result[row][col])
            {
                shortestmove = result[row][col];
            }
        }
    }

    if (shortestmove == INT_MAX)
    {
        cout << -1 << endl;
    }
    else
    {
        cout << shortestmove << endl;
    }

    fclose(fp1);
}
