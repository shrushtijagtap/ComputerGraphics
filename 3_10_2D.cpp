
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
    void translate(int);
    void scale(int);
    void rotate(int);
    void shear(int);
};
int pixel::poly[10][2];

void pixel::draw(int ch)
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
        setcolor(GREEN);
        line(poly[0][0]+mx,my-poly[0][1],mx+poly[1][0],my-poly[1][1]);
        line(mx+poly[1][0],my-poly[1][1],mx+poly[2][0],my-poly[2][1]);
        line(mx+poly[0][0],my-poly[0][1],mx+poly[2][0],my-poly[2][1]);
        delay(1000);

    if(ch==1)
             translate(n);
    else if(ch==2)
             rotate(n);
    else if(ch==3)
             scale(n);
    else
             shear(n);
    delay(20000);
    closegraph();
}

void pixel::translate(int n)
{
          setcolor(BLUE);
          cout<<"\nEnter the distance by which you want to shift\nx-direction : ";
          cin>>x;
          cout<<"\ny-direction : ";
          cin>>y;
          for(i=0;i<n;i++)
          {
                  if(i>0)
                  {
                        line(mx+poly[i-1][0]+x,my-poly[i-1][1]-y,mx+poly[i][0]+x,my-poly[i][1]-y);
                  }
                  if(i==n-1)
                  {
                        line(mx+poly[0][0]+x,my-poly[0][1]-y,mx+poly[i][0]+x,my-poly[i][1]-y);
                  }
          }
}

void pixel::scale(int n)
{
          setcolor(BLUE);
          cout<<"\nEnter the scaling factors\nx : ";
          cin>>x;
          while(x==0)
          {
                  cout<<"\n\n***Don't enter 0 enter 0 or else x co-ordinates will become 0!!!\nEnter 1 to keep it same\n\nEnter x :";
                  cin>>x;
          }
          cout<<"\ny : ";
          cin>>y;
          while(y==0)
          {
                  cout<<"\n\n***Don't enter 0 enter 0 or else y co-ordinates will become 0!!!\nEnter 1 to keep it same\n\nEnter y :";
                  cin>>y;
          }
          for(i=0;i<n;i++)
          {
                  if(i>0)
                  {
                        line(mx+poly[i-1][0]*x,my-poly[i-1][1]*y,mx+poly[i][0]*x,my-poly[i][1]*y);
                  }
                  if(i==n-1)
                  {
                        line(mx+poly[0][0]*x,my-poly[0][1]*y,mx+poly[i][0]*x,my-poly[i][1]*y);
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

void pixel::shear(int n)
{
     int sx,sy;
     int t[n][2];
     cout<<"\nEnter the shear factors\nx : ";
     cin>>sx;
     cout<<"\nsy : ";
     cin>>sy;
     for(int i=0;i<n;i++)
     {
            t[i][0]=poly[i][0]+poly[i][1]*sx;
            t[i][1]=poly[i][0]*sy+poly[i][1];
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
        cout<<"\n\n\n=======MENU=======\n\n\n1.Translattion\n2.Rotation about an arbitrary point\n3.Scaling\n4.Shearing\nPress 0 to exit\nChoice : ";
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
