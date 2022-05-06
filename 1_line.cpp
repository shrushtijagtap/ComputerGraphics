#include<iostream>
#include<graphics.h>
#include<math.h>
using namespace std;

class pixel
{
   
public:
    int x1,y1,x2,y2,dx,dy,len;
};

class dda : public pixel
{
  public :
  void draw(int n)
{
   
  cout<<"\n Enter value of x1:";
  cin>>x1;
  cout<<"\n Enter value of y1:";
  cin>>y1;  
  cout<<"\n Enter value of x2:";
  cin>>x2;
  cout<<"\n Enter value of y2:";
  cin>>y2;
 int gd=DETECT,gm=VGAMAX;
 initgraph(&gd,&gm,NULL);
 	  int x,y,i=0;
	   x=x1;
	   y=y1;
	   putpixel(abs(x),abs(y),15);
	   delay(50);
  int dx,dy;
  dx=x2-x1;
  dy=y2-y1;
  float m=dy/dx;
  if(m<1)
  {
	 do
	 {
	 x=x+1;
	 y=y+m;
	 putpixel(x,y,15);
	 delay(50);
	 }while(x!=x2);
  }
  else if(m==1)
  {
	  do
	 {
	 x=x+1;
	 y=y+1;
	 putpixel(x,y,15);
	 delay(50);
	 }while(x!=x2);
  }
  else
  {
	  do
	 {
	 x=x+1/m;
	 y=y+1;
	 putpixel(x,y,15);
	 delay(50);
	 }while(x!=x2);
  }
  getch();
closegraph();
} 
};

class Bresen: public pixel
{
  public:

  void draw()
 {
   int gd=DETECT,gm=VGAMAX;
   cout<<"\n Enter value of x1:";
   cin>>x1;
   cout<<"\n Enter value of y1:";
   cin>>y1;
   cout<<"\n Enter value of x2:";
   cin>>x2;
   cout<<"\n Enter value of y2:";
   cin>>y2;
 initgraph(&gd,&gm,NULL);
	   int x,y,i=0;
	   x=x1;
	   y=y1;
	   putpixel(abs(x),abs(y),15);
	   delay(50);
	   dx=abs(x2-x1);
	   dy=abs(y2-y1);
	   int po=abs(2*dy-dx);
	   do
	   {
		   if(po<0)
		   {
		   x=x+1;
		  	 putpixel(x,y,15);
		  	 po=po+2*dy;
		   }
		   else
		   {
		   x=x+1;
		   y=y+1;
		  	 putpixel(x,y,15);
		  	 po=po+2*dy-2*dx;
		   }
	   i++;
	   delay(50);
	   }while(i<=dx);
	   getch();
closegraph();
}
};

int main()
{
 dda d;
 Bresen b;
 int  ch;
do
{
cout<<"\n***LINE DRAWING ALGORITHM***";
cout<<"\n\n MENU:";
cout<<"\n1.DDA";
cout<<"\n2.Bresenhams";
cout<<"\n3.Exit";
cout<<"\n Enter your choice:";
cin>>ch;
switch(ch)
{
case 1: d.draw(15);
        break;
case 2: b.draw();
        break;
case 3: exit(0);
}
}
while(ch!=3);

return 0;
}

