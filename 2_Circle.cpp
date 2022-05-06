#include<iostream>
#include<math.h>
#include<graphics.h>

using namespace std;

class circle
{
  public : 
    int x1,y1;
    
   void line1(int x1,int y1,int r)
  {
    int x2=x1;
    int y2=y1-r;   
    line(x1,y1,x2,y2); 
  }


};

class bresen : public circle 
{
  public :

  void bresenc(int x1,int y1,int r)
  {
    int d,x,y;
    d=3-2*r;
    x=0;
    y=r;

    while(x<=y)
   {
     putpixel(x1+x,y1-y,15);
     putpixel(x1+y,y1-(-x),12);
     putpixel(x1+x,y1-(-y),15);
     putpixel(x1+(-y),y1-(-x),12);
     putpixel(x1+(-y),y1-x,15);
     putpixel(x1+(-x),y1-y,12);
     putpixel(x1+(-x),y1-(-y),15);
     putpixel(x1+y,y1-x,12);
     if(d<0)
     {
       d=d+4*x+6;
       x=x+1;
     }
  
   if(d>0)
   {
     d=d+4*(x-y)+10;
     x=x+1;
     y=y-1;

   }

       delay(100);
  }
 }
};


int main()
{
   int x1,y1,r;
   cout<<"\n *** BRESENHAMS CIRCLE DRAWING ALGO ***";
   cout<<"\n Enter x1 :";
   cin>>x1;
   cout<<"\n Enter y1 :";
   cin>>y1;
   cout<<"\n Enter radius :";
   cin>>r;

  bresen b;
  int gd=DETECT,gm=VGAMAX;
    initgraph(&gd,&gm,NULL);

  b.line1(x1,y1,r);
  b.bresenc(x1,y1,r);
  getch();
  closegraph();
  return 0;
}
