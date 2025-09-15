#include<iostream>
#include<vector>
#include<set>
#include<cmath>

using namespace std;

class Point{
    public:
    double x,y;

    bool operator<(const Point &p) const
    {
        if(x<p.x)
            return true;
        else if(x==p.x)
        {
            if(y<p.y)
                return true;
            else
                return false;
        }
        else
            return false;
    }
};

//vector<Point> result;

set<Point> result;

int findSide(Point p1,Point p2,Point p)
{

    int result=(((p1.x-p2.x)*(p1.y-p.y))-(p1.y-p2.y)*(p1.x-p.x));

    if(result<0)
        return -1;
    if(result>0)
        return 1;
    return 0;
}

int relativeDistance(Point p1,Point p2,Point p)
{
    //Relative Distance of p point from the line joining p1 and p2
    return abs((((p1.x-p2.x)*(p1.y-p.y))-(p1.y-p2.y)*(p1.x-p.x)));
}


void findConvex(vector<Point> points,Point p1,Point p2,int side)
{
    int farindex=-1;
    int maxdistance=0;
    for(int i=0;i<points.size();i++)
    {
        int temp=relativeDistance(p1,p2,points[i]);
        if(findSide(p1,p2,points[i])==side && temp>maxdistance)
        {
            farindex=i;
            maxdistance=temp;
        }
    }

    if(farindex==-1)//Occurs when no point is present outside the polygon.
    {
        result.insert(p1);
        result.insert(p2);
        return;
    }

    findConvex(points,p1,points[farindex],findSide(p1,p2,points[farindex]));
    findConvex(points,points[farindex],p2,findSide(p1,p2,points[farindex]));
}

void firstConvexPolygon(vector<Point> points)
{
    int leftmost=0,rightmost=0;
    for(int i=1;i<points.size();i++)
    {
        if(points[i].x<points[leftmost].x)
            leftmost=i;
        if(points[i].x>points[rightmost].x)
            rightmost=i;
    }

    findConvex(points,points[leftmost],points[rightmost],1);

    findConvex(points,points[leftmost],points[rightmost],-1);
}


int main()
{

    FILE *fp1=freopen("Task-1_io/in1.txt","r",stdin);

    int n;
    cin>>n;

    if(n<3)
    {
        cout<<"No convex Hall Possible"<<endl;
        return 0;
    }

    vector<Point> points(n);
    for(int i=0;i<n;i++)
    {
        cin>>points[i].x>>points[i].y;
    }

    firstConvexPolygon(points);

    cout<<"Convex polygon perimeter :"<<result.size()<<endl;
    set<Point>::iterator pointer;
    for(pointer=result.begin();pointer != result.end();pointer++)
    {
        cout<<pointer->x<<" "<<pointer->y<<endl;
    }
    

    fclose(fp1);


    return 0;
}