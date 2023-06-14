// Graham Scan Algorithm
#include <bits/stdc++.h>
using namespace std;
struct Point
{
    int x, y;
};
Point nextToTop(stack<Point> &S)
{
    Point p = S.top();
    S.pop();
    Point res = S.top();
    S.push(p);
    return res;
}
int distSq(Point p1, Point p2)
{
    return (p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y);
}
int orientation(Point p, Point q, Point r)
{
    int val = (q.y - p.y) * (r.x - q.x) - (q.x - p.x) * (r.y - q.y);
    if (val == 0)
        return 0;
    return (val > 0) ? 1 : 2;
}
vector<Point> convexHull(Point points[], int n)
{
    int ymin = points[0].y, min = 0;
    for (int i = 1; i < n; i++)
    {
        int y = points[i].y;
        if ((y < ymin) || (ymin == y && points[i].x < points[min].x))
            ymin = points[i].y, min = i;
    }
    swap(points[0], points[min]);
    Point p0 = points[0];
    sort(points + 1, points + n, [&](Point p1, Point p2)
         {
int o = orientation(p0, p1, p2);
if (o == 0) return distSq(p0, p2) >= distSq(p0, p1);
return (o == 2); });
    stack<Point> S;
    S.push(points[0]);
    S.push(points[1]);
    S.push(points[2]);
    for (int i = 3; i < n; i++)
    {
        while (S.size() > 1 && orientation(nextToTop(S), S.top(), points[i]) != 2)
            S.pop();
        S.push(points[i]);
    }
    vector<Point> hull;
    while (!S.empty())
    {
        Point p = S.top();
        hull.push_back(p);
        S.pop();
    }
    reverse(hull.begin(), hull.end());
    return hull;
}
int main()
{
    int n;
    cin >> n;
    Point points[n];
    for (int i = 0; i < n; i++)
        cin >> points[i].x >> points[i].y;
    vector<Point> hull = convexHull(points, n);
    for (int i = hull.size() - 1; i >= 0; i--)
        cout << "(" << hull[i].x << ", " << hull[i].y << ")" << endl;
    return 0;
}