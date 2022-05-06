// ---------------Assignment No.6----------------
//Title:- Write C++ program to draw line using DDA with patterns such as dotted, dashed,dash dot and thick. 

#include<iostream>
#include<stdlib.h>
#include<graphics.h> //header file for switching text to graphics mode  
#include<math.h>

using namespace std;
class Line
{
  int s1,s2;
  public:
     void dashed();
     void dotted();
     void dashdot();
      int thick(int x1,int y1, int x2, int y2);
     int sign(float);
     
};


//Dashed Line

void Line::dashed()  
{
   int x1,x2,y1,y2;
   
//Step1: read end points of line
   cout<<"Enter the X1 and Y1 co-ordiates::";   cin>>x1>>y1;  
   cout<<"Enter the X2 and Y2 co-ordiates::";   cin>>x2>>y2;
   
   int i,length,dx,dy;
   float x,y,xinc,yinc,temp1;

//Step 2: find dx and dy  
   dx=abs(x2-x1);
   dy=abs(y2-y1);

//Step 3:decide in which direction to move 
  if(dx>=dy)
   length=dx;
  else
   length=dy;

//Step 4: find increment value for x and y
  xinc=(float)(x2-x1)/length;
  yinc=(float)(y2-y1)/length;
     s1=sign(xinc);
     s2=sign(yinc);
    
//Step 5: Plot first pixel   
  x=x1+(0.5*s1);
  y=y1+(0.5*s2);;
  putpixel(x,y,WHITE); //plot first pixel
   
//Step 6: 
  for(i=1;i<=length;i++)
   {  
      
       
      x=x+xinc;
      y=y+yinc;
      if(i%9>4)
        putpixel(x,y,WHITE);
    
   }

}

//Dash Dot Line

void Line::dashdot()   
{
   int x1,x2,y1,y2;
   
//Step1: read end points of line
   cout<<"Enter the X1 and Y1 co-ordiates::";   cin>>x1>>y1;  
   cout<<"Enter the X2 and Y2 co-ordiates::";   cin>>x2>>y2;
   
   int i,length,dx,dy;
   float x,y,xinc,yinc,temp1;

//Step 2: find dx and dy  
   dx=abs(x2-x1);
   dy=abs(y2-y1);

//Step 3:decide in which direction to move 
  if(dx>=dy)
   length=dx;
  else
   length=dy;

//Step 4: find increment value for x and y
  xinc=(float)(x2-x1)/length;
  yinc=(float)(y2-y1)/length;
     s1=sign(xinc);
     s2=sign(yinc);
    
//Step 5: Plot first pixel   
  x=x1+(0.5*s1);
  y=y1+(0.5*s2);;
  putpixel(x,y,WHITE); //plot first pixel
   
//Step 6: 
  for(i=1;i<=length;i++)
   {  
      x=x+xinc;
      y=y+yinc;
      if(i%9<2)
       {}
      else if(i%9<6)
         putpixel(x,y,WHITE);
      else if(i%9==7)
       {}
      else
        putpixel(x,y,WHITE);
    
   }

}

//Dotted Line
void Line::dotted()   
{
   int x1,x2,y1,y2;
   
//Step1: read end points of line
   cout<<"Enter the X1 and Y1 co-ordiates::";   cin>>x1>>y1;  
   cout<<"Enter the X2 and Y2 co-ordiates::";   cin>>x2>>y2;
   
   int i,length,dx,dy;
   float x,y,xinc,yinc,temp1;

//Step 2: find dx and dy  
   dx=abs(x2-x1);
   dy=abs(y2-y1);

//Step 3:decide in which direction to move 
  if(dx>=dy)
   length=dx;
  else
   length=dy;

//Step 4: find increment value for x and y
  xinc=(float)(x2-x1)/length;
  yinc=(float)(y2-y1)/length;
     s1=sign(xinc);
     s2=sign(yinc);
    
//Step 5: Plot first pixel   
  x=x1+(0.5*s1);
  y=y1+(0.5*s2);;
  putpixel(x,y,WHITE); //plot first pixel
   
//Step 6: 
  for(i=1;i<=length;i++)
   {  
      x=x+xinc;
      y=y+yinc;
      if(i%2==1)
        putpixel(x,y,WHITE);
      else 
       {}
         
   }

}

//Thick Line
int Line::thick(int x1,int y1, int x2, int y2)
{

   int i,length,dx,dy;
   float x,y,xinc,yinc,temp1;

//Step 2: find dx and dy  
   dx=abs(x2-x1);
   dy=abs(y2-y1);

//Step 3:decide in which direction to move 
  if(dx>=dy)
   length=dx;
  else
   length=dy;

//Step 4: find increment value for x and y
  xinc=(float)(x2-x1)/length;
  yinc=(float)(y2-y1)/length;
     s1=sign(xinc);
     s2=sign(yinc);
    
//Step 5: Plot first pixel   
  x=x1+(0.5*s1);
  y=y1+(0.5*s2);;
  putpixel(x,y,WHITE); //plot first pixel
   
//Step 6: 
  for(i=1;i<=length;i++)
   {  
      x=x+xinc;
      y=y+yinc;
      putpixel(x,y,WHITE);
    
   }



}

//Sign function
int Line::sign(float temp)  
{
  if(temp==0) return 0;
  else if(temp>0) return 1;
  else return -1;
}




int main()
{
    Line s;
    int ch,i,th,wx,wy; 
    char a;
    int gd=DETECT,gm;
    int x1,x2,y1,y2;
    initgraph(&gd,&gm,NULL);

    do
    {
    cout<<"___________MENU_____________";
    cout<<"\n1. Dashed Line::";
    cout<<"\n2. Dotted Line::";
    cout<<"\n3. Dot Dash Line::";
    cout<<"\n4. Thick Line::\n";
    cout<<"___________________________";
    cout<<"\nEnter ur choice::\t";     cin>>ch;

      switch(ch)
      {
       case 1:
	s.dashed();
	break;

       case 2:
	s.dotted();
	break;    
       
       case 3:
	s.dashdot();
	break; 
      
       case 4:
	cout<<"Enter the X1 and Y1 co-ordiates::";   cin>>x1>>y1;  
        cout<<"Enter the X2 and Y2 co-ordiates::";   cin>>x2>>y2;    
        cout<<"Enter Thickness: ";
        cin>>th;
        s.thick(x1,y1,x2,y2);        
        if((y2-y1)/(x2-x1) <1)
        {
            wy=(th-1)*sqrt(pow((x2-x1),2)+pow((y2-y1),2))/(2*abs(x2-x1));
            for(i=0;i<wy;i++)
            {
                s.thick(x1,y1-i,x2,y2-i);
                s.thick(x1,y1+i,x2,y2+i);
            }
        }
        else
        {
            wx=(th-1)*sqrt(pow((x2-x1),2)+pow((y2-y1),2))/(2*abs(y2-y1));
            for(i=0;i<wx;i++)
            {
                s.thick(x1-i,y1,x2-i,y2);
                s.thick(x1+i,y1,x2+i,y2);
            }
 }
        
	break;
     }
     cout<<"\n\ndo u want to continue(y/n)::";      
     cin>>a;
    }while(a=='y');
     
}



/*------Output--------
isbm@isbm-ThinkCentre-M72e:~$ g++ ass6.cpp -lgraph
isbm@isbm-ThinkCentre-M72e:~$ ./a.out
___________MENU_____________
1. Dashed Line::
2. Dotted Line::
3. Dot Dash Line::
4. Thick Line::
___________________________
Enter ur choice::	
1
Enter the X1 and Y1 co-ordiates::100 100
Enter the X2 and Y2 co-ordiates::300 300


do u want to continue(y/n)::y
___________MENU_____________
1. Dashed Line::
2. Dotted Line::
3. Dot Dash Line::
4. Thick Line::
___________________________
Enter ur choice::	4
Enter the X1 and Y1 co-ordiates::100 150
Enter the X2 and Y2 co-ordiates::250 350
Enter Thickness: 10


do u want to continue(y/n)::


*/
