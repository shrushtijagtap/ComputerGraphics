#include<iostream>
#include<graphics.h>
using namespace std;
int main()
{
int gd=DETECT,gm,i=0,j=0;
initgraph(&gd,&gm,NULL);
for(i;i<600;++i)
{

	line(0,245,650,245);
	line(0+i,200,210+i,200);
	line(50+i,200,70+i,170);
	line(70+i,170,140+i,170);
	line(140+i,170,160+i,200);
	line(85+i,170,85+i,200);
	line(125+i,170,125+i,200);
	line(0+i,200,0+i,230);
	line(210+i,200,210+i,230);
	line(0+i,230,50+i,230);
	circle(65+i,230,15);
	line(80+i,230,130+i,230);
	circle(145+i,230,15);
	line(210+i,230,160+i,230);


	delay(5);
	cleardevice();
}

getch();
closegraph();
return 0;
}
