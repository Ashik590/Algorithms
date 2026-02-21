#include <bits/stdc++.h>
using namespace std;
#define nl "\n"
#define ll long long

struct Point
{
    double x;
    double y;

    Point(double x, double y)
    {
        this->x = x;
        this->y = y;
    }
    Point()
    {
    }
};

bool comp_beingPivot(Point p1, Point p2)
{
    if (p1.y < p2.y)
        return true;
    else if (p1.y == p2.y)
        return p1.x < p2.x;
    else
        return false;
}

Point pivot;

bool comp_havingLowestAngleAndClosest_towardsPivot(Point p1, Point p2)
{
    double angleOfPivotP1Line_towards_xaxis = atan2((p1.y - pivot.y), (p1.x - pivot.x));
    double angleOfPivotP2Line_towards_xaxis = atan2((p2.y - pivot.y), (p2.x - pivot.x));

    double dist_p1ToPivot_sq = (pivot.x - p1.x) * (pivot.x - p1.x) + (pivot.y - p1.y) * (pivot.y - p1.y);
    double dist_p2ToPivot_sq = (pivot.x - p2.x) * (pivot.x - p2.x) + (pivot.y - p2.y) * (pivot.y - p2.y);

    if (angleOfPivotP1Line_towards_xaxis < angleOfPivotP2Line_towards_xaxis)
        return true;
    else if (angleOfPivotP1Line_towards_xaxis == angleOfPivotP2Line_towards_xaxis)
        return dist_p1ToPivot_sq < dist_p2ToPivot_sq;
    else
        return false;
}

double cross_product(Point p1, Point p2, Point p3)
{
    return (p2.x - p1.x) * (p3.y - p2.y) - (p2.y - p1.y) * (p3.x - p2.x); // crossing p1p2 x p2p3
}

int main()
{
    int n;
    cout << "#Points = ";
    cin >> n;

    vector<Point> points(n);

    for (int i = 0; i < n; i++)
        cin >> points[i].x >> points[i].y;

    sort(points.begin(), points.end(), comp_beingPivot);

    pivot = points[0];

    sort(points.begin() + 1, points.end(), comp_havingLowestAngleAndClosest_towardsPivot);

    for (int i = 0; i < n; i++)
        cout << points[i].x << ',' << points[i].y << ' ';
    cout << nl;

    stack<Point> convex_hull;

    for (int i = 0; i < points.size(); i++)
    {
        Point newP = points[i];

        while (convex_hull.size() > 1)
        {
            Point p2 = convex_hull.top();
            convex_hull.pop();
            Point p1 = convex_hull.top();

            double crossProduct_val = cross_product(p1, p2, newP);
            cout << crossProduct_val << nl;

            if (crossProduct_val > 0)
            {
                convex_hull.push(p2);

                break;
            }
        }
        convex_hull.push(newP);
    }

    // cout << convex_hull.size() << nl;
    while (convex_hull.size())
    {
        cout << '(' << convex_hull.top().x << ',' << convex_hull.top().y << ')' << ' ';
        convex_hull.pop();
    }

    cout << nl;

    return 0;
}