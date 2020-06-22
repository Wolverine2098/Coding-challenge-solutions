# Coding-challenge-solutions
Contains the solution of coding challenges by cctech-labs

## Question 1 approach
![snip1](https://user-images.githubusercontent.com/31897207/85330191-833aac80-b4f1-11ea-9ca0-a3bc6748869f.png)

1. drawing horizontal lines from each point and extending it to MAX_INT (max possible value)
2. checking whether the line interescting the polygon
3  if yes,then checking no of times the lines are intersecting
4. If no of intersections are 1 that shows either point is inside or on the edge else point lies outside
5. In case of second figure we check whether the point is colinear or not if found then we check for the side where the point lies
6. If point cannot be found on the line we return false
## Question 2 approach

![tempsnip](https://user-images.githubusercontent.com/31897207/85329511-48844480-b4f0-11ea-89c1-ea523cd7e7b4.png)

1. Enter the coordinates of buildings
2. Initially the first building facing the sun will have its front and top facing sun add them to the sum
3. check next building if larger than the prev one ,draw and imaginary line from sun to point (x02,y02)
4. Extend the figure till the line intersect the building
5. calculate the slope of the line segment using (x,y) and (x02,y02)
6. Using the slope calculate the coordinate y' as shown
7. Now calculate the distance from (X1,Y') and (X1,Y2) and add it to the distance
8. similarly do for rest of buildings
