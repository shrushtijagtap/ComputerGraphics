

#include<iostream>
#include<math.h>
#include<graphics.h>
using namespace std;

class pixel
{
           int mx,my,n,x,y,x1,y1,x2,y2,x3,y3,i,j;
           static int poly[10][2];
public :
    void draw(int);
    void xref(int);
    void yref(int);
    void bref(int);
    void rotate(int);
};

int pixel::poly[10][2];

void pixel::draw(int ch)
{
    int g;
    cout<<"\n 1.Triangle\nChoice : ";
    cin>>g;
    if(g==1)
    
    {
        cout<<"\nEnter the co-ordinates of triangle\nx1 : ";
        cin>>poly[0][0];
        cout<<"\ny1 : ";
        cin>>poly[0][1];
        cout<<"\nx2 : ";
        cin>>poly[1][0];
        cout<<"\ny2 : ";
        cin>>poly[1][1];
        cout<<"\nx3 : ";
        cin>>poly[2][0];
        cout<<"\ny3 : ";
        cin>>poly[2][1];
        n=3;
        int gd=DETECT,gm;
        initgraph(&gd,&gm,NULL);
        mx=getmaxx()/2;
        my=getmaxy()/2;
        setcolor(WHITE);
        line(mx,0,mx,my*2);
        line(0,my,mx*2,my);
        line(poly[0][0]+mx,my-poly[0][1],mx+poly[1][0],my-poly[1][1]);
        line(mx+poly[1][0],my-poly[1][1],mx+poly[2][0],my-poly[2][1]);
        line(mx+poly[0][0],my-poly[0][1],mx+poly[2][0],my-poly[2][1]);
        delay(1000);
    }
    if(ch==1)
             xref(n);
    else if(ch==2)
             yref(n);
    else if(ch==3)
             bref(n);
    else
             rotate(n);
    delay(2000);
    closegraph();
}

void pixel::xref(int n)
{
          setcolor(BLUE);
          for(i=0;i<n;i++)
          {
                  if(i>0)
                  {
                        line(mx+poly[i-1][0],my+poly[i-1][1],mx+poly[i][0],my+poly[i][1]);
                  }
                  if(i==n-1)
                  {
                        line(mx+poly[0][0],my+poly[0][1],mx+poly[i][0],my+poly[i][1]);
                  }
          }
}

void pixel::yref(int n)
{
          setcolor(BLUE);
          for(i=0;i<n;i++)
          {
                  if(i>0)
                  {
                        line(mx-poly[i-1][0],my-poly[i-1][1],mx-poly[i][0],my-poly[i][1]);
                  }
                  if(i==n-1)
                  {
                        line(mx-poly[0][0],my-poly[0][1],mx-poly[i][0],my-poly[i][1]);
                  }
          }
}

void pixel::bref(int n)
{
          setcolor(WHITE);
          line(mx,my,mx*2,0);
          setcolor(BLUE);
          for(i=0;i<n;i++)
          {                                   
                  if(i>0)
                  {
                        line(mx+poly[i-1][1],my-poly[i-1][0],mx+poly[i][1],my-poly[i][0]);
                  }
                  if(i==n-1)
                  {
                        line(mx+poly[0][1],my-poly[0][0],mx+poly[i][1],my-poly[i][0]);
                  }
          }
}

void pixel::rotate(int n)
{
    float temp[3][3];
    double angle;
    int t[n][2],r;
    setcolor(BLUE);
    cout<<"\nEnter the point\nx : ";
    cin>>x1;
    cout<<"\ny : ";
    cin>>y1;
    cout<<"\nEnter the angle : ";
    cin>>angle;
    cout<<"\n1.anticlockwise\n2.Clockwise\nChoice : ";
    cin>>r;
    angle=(angle/180)*3.14;
    if(r==1)
    {
            temp[0][0]=cos(angle);
            temp[0][1]=sin(angle);
            temp[1][0]=-sin(angle);
            temp[1][1]=cos(angle);  
            temp[2][0]=-x1*cos(angle)+y1*sin(angle)+x1;
            temp[2][1]=-x1*sin(angle)-y1*cos(angle)+y1;
            temp[0][2]=temp[1][2]=0;
            temp[2][2]=1;      
    }
    else if(r==2)
    {
            temp[0][0]=cos(angle);
            temp[0][1]=-sin(angle);
            temp[1][0]=sin(angle);
            temp[1][1]=cos(angle);
            temp[2][0]=-x1*cos(angle)-y1*sin(angle)+x1;
            temp[2][1]=x1*sin(angle)-y1*cos(angle)+y1;
            temp[0][2]=temp[1][2]=0;
            temp[2][2]=1;
    }
    for(i=0;i<n;i++)
    {
        for(j=0;j<2;j++)
        {
            t[i][j]=poly[i][0]*temp[0][j]+poly[i][1]*temp[1][j]+temp[2][j];
        }
    }
    
    for(i=0;i<n;i++)
    {                                   
                  if(i>0)
                  {
                        line(mx+t[i-1][0],my-t[i-1][1],mx+t[i][0],my-t[i][1]);
                  }
                  if(i==n-1)
                  {
                        line(mx+t[0][0],my-t[0][1],mx+t[i][0],my-t[i][1]);
                  }
    }
}

int main()
{
    pixel P;
    int ch;
    do
    {
        cout<<"\n\n\n=======MENU=======\n\n\n1.Reflection about X axis\n2.Reflection about y axis\n3.Reflection about X=Y axis\n4.Rotate about arbitrary point\nPress 0 to exit\nChoice : ";
        cin>>ch;
        if(ch<5 && ch!=0)
        {
                P.draw(ch);
        }
        else if(ch!=0)
            cout<<"\n\n\n***Invalid choice!!!\n\n\n";
    }while(ch!=0);
    return 0;
}


/*

akshay@akshay-HP-Pavilion-Notebook:~/Desktop$ ./a.out



=======MENU=======


1.Reflection about X axis
2.Reflection about y axis
3.Reflection about X=Y axis
4.Rotate about arbitrary point
Press 0 to exit
Choice : 1

1.Line
2.Rextangle
3.Triangle
Choice : 1

Enter the co-ordinates of line
x1 : 20

y1 : 20

x2 : 100

y2 : 100
=======MENU=======


1.Reflection about X axis
2.Reflection about y axis
3.Reflection about X=Y axis
4.Rotate about arbitrary point
Press 0 to exit
Choice : 2

1.Line
2.Rextangle
3.Triangle
Choice : 1

Enter the co-ordinates of line
x1 : 100

y1 : 100

x2 : 200

y2 : 200


=======MENU=======


1.Reflection about X axis
2.Reflection about y axis
3.Reflection about X=Y axis
4.Rotate about arbitrary point
Press 0 to exit
Choice : 3

1.Line
2.Rextangle
3.Triangle
Choice : 1

Enter the co-ordinates of line
x1 : 100

y1 : 100

x2 : 200

y2 : 200


=======MENU=======


1.Reflection about X axis
2.Reflection about y axis
3.Reflection about X=Y axis
4.Rotate about arbitrary point
Press 0 to exit
Choice : 4

1.Line
2.Rextangle
3.Triangle
Choice : 1

Enter the co-ordinates of line
x1 : 100

y1 : 100

x2 : 200

y2 : 200

Enter the point
x : 3

y : 3

Enter the angle : 30

1.anticlockwise
2.Clockwise
Choice : 1


*/


