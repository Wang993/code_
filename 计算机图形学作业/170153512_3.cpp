#include<stdio.h>
#include<graphics.h>
#include<math.h>
#include<stdlib.h>
void drawsample(int r,int g,int b,int shigh,int slow,char* check,int wlocy,int cflocx,int cflocy){
	setfillcolor(EGERGB(r,g,b));
	rectangle(610,shigh,630,slow);
	outtextxy(640,wlocy,check);
	floodfill(613,wlocy + 6,WHITE);
	floodfill(cflocx,cflocy,WHITE);
} 
int main(){
	initgraph(800,600);
	setcolor(EGERGB(120,220,200));
	setlinewidth(1);
	setfont(50,30,"����");
	outtextxy(200,20,"���۱�");
	//���ñ������������壬����ͼ������
	
	setcolor(WHITE);
	setfont(20,15,"����");
	//���÷�������
	
	ellipse(290,240,0,360,215,150);
	//��������������Բ����
	
	int lines[4*4] = {290,240,290,90,290,240,470,157,290,240,110,157,290,240,174,366};
	drawlines(4,lines);
	//ͼ���зָ��� 
	
	rectangle(600,200,780,325);
	//���½Ǵ����
	char check1[] = {"huadong"};
	char check2[] = {"huabei"};
	char check3[] = {"huanan"};
	char check4[] = {"huaxi"};
	drawsample(255,165,0,213,227,check1,210,295,235); 
	drawsample(176,48,96,243,257,check2,240,295,245); 
	drawsample(186,85,211,273,287,check3,270,255,245); 
	drawsample(148,0,211,303,317,check4,300,280,205); 
	
		
	getch();
	closegraph();
	return 0;
			 
} 
