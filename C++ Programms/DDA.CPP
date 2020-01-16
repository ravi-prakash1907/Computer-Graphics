//DDA

#include<iostream.h>
#include<conio.h>
#include<graphics.h>
#include<math.h>

////////////////////

struct point {
   float x;
   float y;
};

float findSlope(point a, point b) {
   float slope;
   slope = (b.y - a.y)/(b.x - a.x);
   return slope;
}

void main() {
clrscr();

   int gd = DETECT,gm;
   initgraph(&gd,&gm,"C:\\TC\\BGI");

   point beg, end, line;
   int j, i;

   cout<<"Enter co-ordinates of initial point: ";
   cin>>beg.x>>beg.y;
   cout<<"Enter co-ordinates of last point: ";
   cin>>end.x>>end.y;
   line = beg;

   ////////////////////////////////////////////////

   float m = fabs(findSlope(beg, end));
   if(m <= 1) {
     for(i=0; i<int(end.x-beg.x); i++) {
	putpixel(line.x, 449-line.y, GREEN);
	line.x += 1;
	line.y += m;
     }
   } else {
     for(i=0; i<int(end.y-beg.y); i++) {
	putpixel(line.x, 449-line.y, GREEN);
	line.x += 1/m;
	line.y += 1;
     }
   }

getch();
closegraph();
}