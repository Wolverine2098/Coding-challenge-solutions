
#include <bits/stdc++.h>

using namespace std;

struct point{
    double x,y;
    
    
};
//structure to accept the coordinates

struct building{
   struct point p1,p2,p3,p4;
   
   float s1,s2,s3;
   void calwall()// to calculate the length of all the 3 walls that will be affected by the sunlight
   {
         s1=sqrt(pow(p1.x - p2.x, 2)+ pow(p1.y - p2.y, 2) * 1.0); // length of the left wall
         s2=sqrt(pow(p2.x - p3.x, 2)+ pow(p2.y - p2.y, 2) * 1.0); // length of the upper terrace
         s3=sqrt(pow(p3.x - p4.x, 2)+ pow(p3.y - p4.y, 2) * 1.0); // length of the right wall
   }
 // double s1=sqrt(pow(p1.x - p2.x, 2)+ pow(p1.y - p2.y, 2) * 1.0);
  //double s2=sqrt(pow(p2.x - p3.x, 2)+ pow(p2.y - p2.y, 2) * 1.0); 
  //double s3=sqrt(pow(p3.x - p4.x, 2)+ pow(p3.y - p4.y, 2) * 1.0); 
  
};

double slope(double x1, double y1, double x2, double y2) // function to calculate the slope of the line
{ 
    return (y2 - y1) / (x2 - x1); 
} 

int main(){
    building b[] = { { {4,0},{4,-5},{7,-5},{7,0} }, { {0.4,-2},{0.4,-5},{2.5,-5},{2.5,-2} } };
    
    int s= sizeof b/sizeof b[0];// no of buildings
    for(int i=0;i<s;i++){
       b[i].calwall(); //calculating all the walls of each building
    }
    //cout<<b[0].s1;
    //cout<<b[1].s1;
    point sun; // coordinates of sun
    sun ={-3.5,1};
    
    int maxh=INT_MIN; //max height of the building 
    
 
 //cout<<b[0].s1<<" "<< b[0].s2<<endl;
 double light=b[0].s1+b[0].s2; // since light of sun will always fall on the first building
 
maxh=b[0].s1; //initialising max height as height of 1st building
double maxx=b[0].p3.x;
double maxy=b[0].p3.y;
 for(int i =1;i<s;i++){
   
    
     if(maxh<=b[i-1].s1){ //if building is larger than previously large building
        
        maxh=b[i-1].s1;// new max height
        
        double slo=slope(sun.x,sun.y,maxx,maxy); // calculating the slope of ray of light
        
        double newp= (slo * (b[i].p1.x - sun.x) )+sun.y; //calculating the y coordinate where the sunlight will strike
        
        
        float dist =sqrt(pow(b[i].p3.y - newp, 2) * 1.0);
        //cout<<dist<<endl;
       
        light=light+b[i].s2+ dist;
        
        double maxx=b[0].p3.x;// new max x 
        double maxy=b[0].p3.y; // new max y
        
        
    }      
     
     
 }
  cout<<light<<endl;  
    
}
//Assuming that the building with higher height will cover the next shorter building fully 
// if that's not true then code can be further extended by checking the portion of next shorter building covered by sunlight
// this can be easily done by calculating the  slope of line/ray of sunlight from sun to rightmost point of i-1 th building 
// then extending that ray where it strikes the terrace of i th building and calculating length of terrace
// covered by the sun light
