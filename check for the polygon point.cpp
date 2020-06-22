#include<bits/stdc++.h>
using namespace std;

struct Point 
{ 
    int x; 
    int y; 
}; 

// To find orientation of ordered triplet (p, q, r). The function returns values for clockwise ,anticlockwise or collinear
int chk(Point p, Point q, Point r) 
{ 
    int val = (q.y - p.y)*(r.x - q.x)-(q.x - p.x)*(r.y - q.y); 
  
    if (val == 0) return 0;   
    return (val > 0)? 1:2; // clock or counterclock wise 
} 
  

// function to check whether the point lies on the side of the polygon
bool inlin(Point p, Point q, Point r) 
{ 
    if (q.x <= max(p.x, r.x) && q.x >= min(p.x, r.x) && 
            q.y <= max(p.y, r.y) && q.y >= min(p.y, r.y)) 
        return true; 
    return false; 
}

bool colid(Point p1, Point q1, Point p2, Point q2) 
{ 

    int o1 = chk(p1, q1, p2); 
    int o2 = chk(p1, q1, q2); 
    int o3 = chk(p2, q2, p1); 
    int o4 = chk(p2, q2, q1); 
 
    if (o1 != o2 && o3 != o4) 
        return true; 
  
    if (o1 == 0 && inlin(p1, p2, q1)) return true; 
    if (o2 == 0 && inlin(p1, q2, q1)) return true; 
    if (o3 == 0 && inlin(p2, p1, q2)) return true;
    if (o4 == 0 && inlin(p2, q1, q2)) return true; 
  
    return false;  
} 
  
 
bool inside(Point polygon[], int n, Point p) 
{ 
     
    if (n < 3)  return false; 
  
     
    Point extreme = {INT_MAX, p.y}; 
  
    // Count intersections of the above line with polygon 
    int count = 0, i = 0; 
    do
    { 
        int next = (i+1)%n; 
  
        // Checking if the line segment from 'p' to 'extreme' intersects  with the line segment from 'polygon[i]' to 'polygon[next]' 
        if (colid(polygon[i], polygon[next], p, extreme)) 
        { 
            // If the point 'p' is colinear with line segment 'i-next',then check if it lies on segment. If it lies, return true, 
        
            if (chk(polygon[i], p, polygon[next]) == 0) 
               return inlin(polygon[i], p, polygon[next]); 
  
            count++; 
        } 
        i = next; 
    } while (i != 0); 
  
    // Return true if count is odd, otherwise false 
    return count%2 == 1;  
} 
  
 
int main() 
{ 
    Point polygon1[] = {{0, 0}, {10, 0}, {10, 10}, {0, 10}}; 
    int n = sizeof(polygon1)/sizeof(polygon1[0]); 
    Point p = {20, 20}; 
    inside(polygon1, n, p)? cout << "true \n": cout << "false \n"; 
  
   
  
    Point polygon2[] = {{0, 0}, {5, 5}, {5, 0}}; 
    p = {3, 3}; 
    n = sizeof(polygon2)/sizeof(polygon2[0]); 
    inside(polygon2, n, p)? cout << "true \n": cout << "False \n"; 
    return 0; 
}

