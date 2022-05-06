//Write C++/Java program to draw inscribed and Circumscribed circles in the triangle as shown as an example below. (Use any Circle drawing and Line drawing algorithms) 


#include<graphics.h>
#include<iostream>
#include<stdlib.h>
#include<math.h>
using namespace std;

class pixel  //Base Class
{
   protected: int x1,y1;//center of circle
   public: 
          pixel() //constructor
          {
	    x1=0;y1=0;
          }

          void setoff(int xx,int yy) //set co-ordinates
          {
            x1=xx;
            y1=yy;
          }
};

class dcircle: public pixel // Derived Class
{
     private: int r; //radious of circle
     public:
           
     dcircle():pixel() //constructor
     {
	  r=0;
     }

     void setrad(int z)  //set radious
     {
         r=z;
     }

     
     void drawbc() //Bresenham's Circle
     { 
        int i,x,y;
        float d;

        x=0, y=r;
        d = 3 - 2*r; //decision variable
        
        do
        {
           putpixel(x1+x, y1+y,15);
           putpixel(x1+y, y1+x,15);
           putpixel(x1+y, y1-x,15);
           putpixel(x1+x, y1-y,15);
           putpixel(x1-x, y1-y,15);
           putpixel(x1-y, y1-x,15);
           putpixel(x1-y, y1+x,15);
           putpixel(x1-x, y1+y,15);

           if(d<=0)
           {
              x = x + 1;
              d = d + (4*x) + 6;
           }
           else
           {
              x = x + 1;
              y = y - 1;
              d = d + (4*x-4*y) + 10;
           }

        }while(x<=y);

    }//Function Closed


   
};

int main()
{
	int gd=DETECT,gm=VGAMAX;
	int i, x, y, r1,r2,ch, xmax,ymax,xmid,ymid;
	float a,b;
	char ans;
	dcircle c1,c2;
        initgraph(&gd, &gm, NULL);
 	
        xmax = getmaxx();
	ymax = getmaxy();
	xmid = xmax /2;
	ymid = ymax /2;

	line(xmid,0,xmid,ymax); //Y co-ordinate
	line(0,ymid,xmax,ymid); //X co-ordinate
	 	   
	  
	cout<<"\n Enter x: "; cin>>x;
	cout<<"\n Enter y: "; cin>>y;
	cout<<"\n Enter radius: "; cin>>r1;
        cout<<"\n Enter radius: "; cin>>r2;
        c1.setoff(xmid+x, ymid-y);
        c1.setrad(r1);
        c1.drawbc();
        c2.setoff(xmid+x, ymid-y);  

	line(0+xmid,ymid-r2,xmid+(0.866*r2),ymid+r1 ) ;
      	line(0+xmid,ymid-r2,xmid-(0.866*r2),ymid+r1 ) ;
	line(xmid+(0.866*r2),ymid+r1,xmid-(0.866*r2),ymid+r1 ) ;
        //line(xmid,ymid-r2,100,100);
        c2.setrad(r2);
        c2.drawbc();

        delay(3000);
	getch();
	closegraph();
	return 0;
}
