//  mid point circle drawing algorithm
#include<iostream.h>
#include<conio.h>
#include<graphics.h>

int main() {
  clrscr();
    int h, k, x, y, r, P, X, Y;

    int gd = DETECT,gm;
    initgraph(&gd, &gm, "C:\\TC\\BGI");

    line(319, 15, 319, 464);	// y-axis
    line(15, 239, 624, 239);	// x-axis

    cout<<"Enter co-ordinates of center(h, k): ";
    cin>>h>>k;
    cout<<"Radius: ";
    cin>>r;

    x = 0;
    y = r;

    P = 1 - r;

    for(; x<=y; x++) {
       X = x+h;
       Y = y+k;

       /*	REFLECTIONS	*/
       //  (X`, Y`)    ..............    O  -> Oct.
       putpixel(319+X, 239-Y, RED);     // O1
       putpixel(319+X, 239+Y, RED);     // O4
       putpixel(319-X, 239-Y, RED);     // O5
       putpixel(319-X, 239+Y, RED);     // O8
       //  (Y`, X`)
       putpixel(319+Y, 239-X, GREEN);   // O2
       putpixel(319+Y, 239+X, GREEN);   // O3
       putpixel(319-Y, 239-X, GREEN);   // O6
       putpixel(319-Y, 239+X, GREEN);   // O7

       if(P<0) {
	 P += 2*x + 3;
       } else {
	 P += 2*x - 2*y + 5;
	 y--;
       }
    }

  getch();
  closegraph();
}