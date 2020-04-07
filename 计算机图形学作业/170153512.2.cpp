#include <stdio.h>
#include <graphics.h> 
#include <math.h> 
void wave(int b,int a){
	setcolor(GREEN);
	int i;
	for(int i=5400;i>0;i--)
	{
		line((i+500)/10+a,-0.35*(200*sin(i*3.14/360)+300)/10+b,(i+1+500)/10+a,-0.35*(200*sin((i+1)*3.14/360)+300)/10+b);
		//借用上次的画正弦函数曲线 
	} 
} 
void star(float a, int x, int y){
	setcolor(EGERGB(105,105,105));
	setfillcolor(WHITE);
	//颜色准备 
	int star[22]={330,124,351,128,354,149,365,131,386,134,372,118,381,99,362,107,347,92,349,114,330,124};
	for(int j = 0; j < 22; j++){
		star[j] = star[j] * a;
	}
	for(int j = 0; j < 22; j = j + 2){
		star[j] = star[j] + x;
	}	
	for(int j = 1; j < 22; j = j + 2){
		star[j] = star[j] + y;
	}	
	fillpoly(11,star);
	int b = 330 * a + x;
	int c = 124 * a + y;
	floodfill(b,c,EGERGB(105,105,105));	
}

	
void house(int a,int b,float c){
	setcolor(WHITE);
	int i = 0;
	int p1[2*7] = {a,c*b,a,b+85,a+70,b+85,a+70+20,b+85-20,a+70+20,c*(b-20),a+70+20-70,c*(b-20),a,c*b};
	//试验得出的长宽高间距 
	drawpoly(7,p1); 
	float temp0,temp1;
	temp0 = c*(b+5);
	int w11[2*5] = {a+10,temp0,a+20,temp0,a+20,b+80,a+10,b+80,a+10,temp0};  
	int w21[2*5] = {a+30,temp0,a+40,temp0,a+40,b+80,a+30,b+80,a+30,temp0}; 
	int w31[2*5] = {a+50,temp0,a+60,temp0,a+60,b+80,a+50,b+80,a+50,temp0}; 
	drawpoly(5,w11);
	drawpoly(5,w21);
	drawpoly(5,w31);
	//画房子和窗户外框线——然后填充 
	setfillcolor(EGERGB(255,165,0));
	floodfill(a+3,c*(b+3),WHITE);
	setfillcolor(EGERGB(105,105,105));
	floodfill(a+13,c*(b+8),WHITE);
	floodfill(a+33,c*(b+8),WHITE);
	floodfill(a+53,c*(b+8),WHITE);
	
	//画房子和窗户内部框线 
	int p2[2*6] = {a+70,c*b, a,c*b, a+70,c*b, a+70,b+85, a+70,c*b,a+70+20,c*(b-20) }; //外框
	drawlines(4,p2);	//依次两两画线 
	float temp2,temp3;
	temp2 = c*b+5+(b+85-c*b-10)/3;
	temp3 = c*b+5+2*(b+85-c*b-10)/3;
	int w12[2*4] = {a+20,temp2,a+10,temp2,a+20,temp3,a+10,temp3}; 
	int w22[2*4] = {a+40,temp2,a+30,temp2,a+40,temp3,a+30,temp3};
	int w32[2*4] = {a+60,temp2,a+50,temp2,a+60,temp3,a+50,temp3};
	drawlines(2,w12);
	drawlines(2,w22);
	drawlines(2,w32);		
}
 
int main(){
	initgraph(800,400);
	setlinewidth(2);
	setbkcolor(BLUE); 
		
	//以左顶点为a,b。缩短则需要上端点y坐标扩大（下移） 
	house(170,220,0.85);
	house(270,220,1.08);
	house(370,220,1.0);	
	house(470,220,1.0);	

	//波浪，长得一般般； 
	wave(350,100);
	wave(360,105);
	wave(350,110);
	wave(370,110);
	wave(350,80);
	wave(380,130);
	//五角星：
	star(1.0,0,0); 
	star(0.8,80,-39); 
	star(1,-50,-40);
	star(1.5,-20,-30);
	star(0.5,112,-39); 
	star(0.3,137,20); 
	star(0.8,130,-39);
	star(0.5,298,70);
	star(0.9,390,40);
	star(0.5,417,110);
	star(0.5,537,140);
	getch();
	closegraph();
	return 0; 
}


//以下为封装前使用方法。 

//#include <stdio.h>
//#include <graphics.h> 
//#include <math.h> 
//int main(){
//	int check1[10]={300,300,350,300,350,250,300,250,300,300};	
//	int check2[8]={300,250,317.675,232.325,367.675,232.325,350,250};	
//	int check3[8]={367.675,232.325,367.675,282.325,350,300,350,250};
//	
//	int check4[10]={300,300,350,300,350,250,300,250,300,300};	
//	int check5[8]={300,250,317.675,232.325,367.675,232.325,350,250};	
//	int check6[8]={367.675,232.325,367.675,282.325,350,300,350,250};
//	
//	initgraph(1000,640);
//	setlinewidth(2);
//	setbkcolor(BLUE); 
//	setcolor(WHITE);
//	setfillstyle(1,BROWN);
//	fillpoly(5,check1);
//	fillpoly(4,check2);
//	fillpoly(4,check3);
//	
//	float delta = (check1[1]-check1[5]-20)/3;
//	delta = (check1[1]-check1[5])/3;
//	for(int i = 1;i < 7; i++){
//		line(check1[0]+7*i,check1[1]-10,check1[0]+7*i,check1[5]+10);	
//	} 
//	for(int i = 1;i < 7; i = i + 2){
//		line(check1[0]+7*i,check1[5]+10,check1[0]+7*(i+1),check1[5]+10);	
//	}
//	for(int i = 1;i < 7; i = i + 2){
//		line(check1[0]+7*i,check1[1]-10,check1[0]+7*(i+1),check1[1]-10);	
//	}
//	for(int i = 1;i < 7; i = i + 2){
//		line(check1[0]+7*i,check1[5]+10,check1[0]+7*(i+1),check1[5]+10);	
//	}
//	for(int i = 1;i < 7; i = i + 2){
//		line(check1[0]+7*i,check1[1]-10,check1[0]+7*(i+1),check1[1]-10);	
//	}
//	for(int i = 1;i < 7; i = i + 2){
//		line(check1[0]+7*i,check1[1]-2*delta,check1[0]+7*(i+1),check1[1]-2*delta);	
//	}
//	for(int i = 1;i < 7; i = i + 2){
//		line(check1[0]+7*i,check1[1]-delta,check1[0]+7*(i+1),check1[1]-delta);
//		setfillcolor(EGERGB(0x00, 0x00, 0x01));
//		bar(check1[0]+7*i+2,check1[1]-delta-2,check1[0]+7*(i+1)-2,check1[1]-2*delta+2);
//		bar(check1[0]+7*i+2,check1[1]-10-2,check1[0]+7*(i+1)-2,check1[1]-delta+2);
//		bar(check1[0]+7*i+2,check1[1]-2*delta-2,check1[0]+7*(i+1)-2,check1[5]+10+2);
//		//填充颜色
////		setfillstyle(1,EGERGB(0x00, 0x00, 0x01));
////		setcolor(BLACK);
////		floodfillsurface(check1[0]+5,check1[1]-delta,BLUE);	
//	}
//	
//	
//	
//	setfillstyle(1,BROWN);
//	setcolor(WHITE);
//	
//	
//	
//	//画左起第二栋房子，作为标准，右边放大为1.5倍，左边放大为2倍
//	for(int i = 0;i < 10; i = i + 2){
//		check1[i] = check1[i]-80;	
//	} 
//	for(int i = 0;i < 8; i = i + 2){
//		check2[i] = check2[i]-80;
//		check3[i] = check3[i]-80;	
//	}
//	for(int i = 1;i < 8; i = i + 2){
//		check2[i] = check2[i]-50;		
//	}
//	check1[5] = check1[5] - 50; 
//	check1[7] = check1[7] - 50;
//	check3[7] = check3[7] - 50;
//	check3[1] = check3[1] - 50;
//	fillpoly(5,check1);
//	fillpoly(4,check2);
//	fillpoly(4,check3);
//	
//	//画窗户:
//	delta = (check1[1]-check1[5]-20)/3;
//	for(int i = 1;i < 7; i++){
//		line(check1[0]+7*i,check1[1]-10,check1[0]+7*i,check1[5]+10);	
//	} 
//	for(int i = 1;i < 7; i = i + 2){
//		line(check1[0]+7*i,check1[5]+10,check1[0]+7*(i+1),check1[5]+10);	
//	}
//	for(int i = 1;i < 7; i = i + 2){
//		line(check1[0]+7*i,check1[1]-10,check1[0]+7*(i+1),check1[1]-10);	
//	}
//		for(int i = 1;i < 7; i = i + 2){
//		line(check1[0]+7*i,check1[5]+10,check1[0]+7*(i+1),check1[5]+10);	
//	}
//	for(int i = 1;i < 7; i = i + 2){
//		line(check1[0]+7*i,check1[1]-10,check1[0]+7*(i+1),check1[1]-10);	
//	}
//	for(int i = 1;i < 7; i = i + 2){
//		line(check1[0]+7*i,check1[1]-2*delta,check1[0]+7*(i+1),check1[1]-2*delta);	
//	}
//	for(int i = 1;i < 7; i = i + 2){
//		line(check1[0]+7*i,check1[1]-delta,check1[0]+7*(i+1),check1[1]-delta);	
//		setfillcolor(EGERGB(0x00, 0x00, 0x01));
//		bar(check1[0]+7*i+2,check1[1]-delta-2,check1[0]+7*(i+1)-2,check1[1]-2*delta+2);
//		bar(check1[0]+7*i+2,check1[1]-10-2,check1[0]+7*(i+1)-2,check1[1]-delta+2);
//		bar(check1[0]+7*i+2,check1[1]-2*delta-2,check1[0]+7*(i+1)-2,check1[5]+10+2);
//	}
//	
//	
//	setfillstyle(1,BROWN);
//	setcolor(WHITE);
//	
//	//还原数据 
//	for(int i = 0;i < 10; i++){
//		check1[i] = check4[i];	
//	} 	
//	for(int i = 0;i < 8; i++){
//		check2[i] = check5[i];
//		check3[i] = check6[i];	
//	}
//	//左起第一栋 
//	for(int i = 0;i < 10; i = i + 2){
//		check1[i] = check1[i]+80;	
//	} 
//	for(int i = 0;i < 8; i = i + 2){
//		check2[i] = check2[i]+80;
//		check3[i] = check3[i]+80;	
//	}
//	for(int i = 1;i < 8; i = i + 2){
//		check2[i] = check2[i]-25;		
//	}
//	check1[5] = check1[5] - 25; 
//	check1[7] = check1[7] - 25;
//	check3[7] = check3[7] - 25;
//	check3[1] = check3[1] - 25;
//	fillpoly(5,check1);
//	fillpoly(4,check2);
//	fillpoly(4,check3);
//	delta = (check1[1]-check1[5]-20)/3;
//	for(int i = 1;i < 7; i++){
//		line(check1[0]+7*i,check1[1]-10,check1[0]+7*i,check1[5]+10);	
//	} 
//	for(int i = 1;i < 7; i = i + 2){
//		line(check1[0]+7*i,check1[5]+10,check1[0]+7*(i+1),check1[5]+10);	
//	}
//	for(int i = 1;i < 7; i = i + 2){
//		line(check1[0]+7*i,check1[1]-10,check1[0]+7*(i+1),check1[1]-10);	
//	}
//		for(int i = 1;i < 7; i = i + 2){
//		line(check1[0]+7*i,check1[5]+10,check1[0]+7*(i+1),check1[5]+10);	
//	}
//	for(int i = 1;i < 7; i = i + 2){
//		line(check1[0]+7*i,check1[1]-10,check1[0]+7*(i+1),check1[1]-10);	
//	}
//	for(int i = 1;i < 7; i = i + 2){
//		line(check1[0]+7*i,check1[1]-2*delta,check1[0]+7*(i+1),check1[1]-2*delta);	
//	}
//	for(int i = 1;i < 7; i = i + 2){
//		line(check1[0]+7*i,check1[1]-delta,check1[0]+7*(i+1),check1[1]-delta);	
//		setfillcolor(EGERGB(0x00, 0x00, 0x01));
//		bar(check1[0]+7*i+2,check1[1]-delta-2,check1[0]+7*(i+1)-2,check1[1]-2*delta+2);
//		bar(check1[0]+7*i+2,check1[1]-10-2,check1[0]+7*(i+1)-2,check1[1]-delta+2);
//		bar(check1[0]+7*i+2,check1[1]-2*delta-2,check1[0]+7*(i+1)-2,check1[5]+10+2);
//	}
//	
//	
//	setfillstyle(1,BROWN);
//	setcolor(WHITE);
//	
//	
//	//左起三 
//	for(int i = 0;i < 10; i = i + 2){
//		check1[i] = check1[i]+80;	
//	} 
//	for(int i = 0;i < 8; i = i + 2){
//		check2[i] = check2[i]+80;
//		check3[i] = check3[i]+80;	
//	}
//	fillpoly(5,check1);
//	fillpoly(4,check2);
//	fillpoly(4,check3);
//	delta = (check1[1]-check1[5]-20)/3;
//	for(int i = 1;i < 7; i++){
//		line(check1[0]+7*i,check1[1]-10,check1[0]+7*i,check1[5]+10);	
//	} 
//	for(int i = 1;i < 7; i = i + 2){
//		line(check1[0]+7*i,check1[5]+10,check1[0]+7*(i+1),check1[5]+10);	
//	}
//	for(int i = 1;i < 7; i = i + 2){
//		line(check1[0]+7*i,check1[1]-10,check1[0]+7*(i+1),check1[1]-10);	
//	}
//		for(int i = 1;i < 7; i = i + 2){
//		line(check1[0]+7*i,check1[5]+10,check1[0]+7*(i+1),check1[5]+10);	
//	}
//	for(int i = 1;i < 7; i = i + 2){
//		line(check1[0]+7*i,check1[1]-10,check1[0]+7*(i+1),check1[1]-10);	
//	}
//	for(int i = 1;i < 7; i = i + 2){
//		line(check1[0]+7*i,check1[1]-2*delta,check1[0]+7*(i+1),check1[1]-2*delta);	
//	}
//	for(int i = 1;i < 7; i = i + 2){
//		line(check1[0]+7*i,check1[1]-delta,check1[0]+7*(i+1),check1[1]-delta);	
//		setfillcolor(EGERGB(0x00, 0x00, 0x01));
//		bar(check1[0]+7*i+2,check1[1]-delta-2,check1[0]+7*(i+1)-2,check1[1]-2*delta+2);
//		bar(check1[0]+7*i+2,check1[1]-10-2,check1[0]+7*(i+1)-2,check1[1]-delta+2);
//		bar(check1[0]+7*i+2,check1[1]-2*delta-2,check1[0]+7*(i+1)-2,check1[5]+10+2);
//	}
//	
//	
//	setfillstyle(1,BROWN);
//	setcolor(WHITE);
//	
//	
//	
//	//左起四 
//	//波浪，长得一般般； 
//	setcolor(GREEN); 
//	for(int i=5400;i>0;i--)
//	{
//		line((i+500)/10+100,-0.35*(200*sin(i*3.14/360)+300)/10+400,(i+1+500)/10+100,-0.35*(200*sin((i+1)*3.14/360)+300)/10+400);
//	} 
//	for(int i=5400;i>0;i--)
//	{
//		line((i+500)/10+120,-0.35*(200*sin(i*3.14/360)+300)/10+420,(i+1+500)/10+120,-0.35*(200*sin((i+1)*3.14/360)+300)/10+420);
//	} 
//	for(int i=5400;i>0;i--)
//	{
//		line((i+500)/10+100,-0.35*(200*sin(i*3.14/360)+300)/10+440,(i+1+500)/10+100,-0.35*(200*sin((i+1)*3.14/360)+300)/10+440);
//	} 
//	for(int i=5400;i>0;i--)
//	{
//		line((i+500)/10+100,-0.35*(200*sin(i*3.14/360)+300)/10+460,(i+1+500)/10+100,-0.35*(200*sin((i+1)*3.14/360)+300)/10+460);
//	} 
//	for(int i=5400;i>0;i--)
//	{
//		line((i+500)/10+120,-0.35*(200*sin(i*3.14/360)+300)/10+480,(i+1+500)/10+120,-0.35*(200*sin((i+1)*3.14/360)+300)/10+480);
//	} 
//	
//	//五角星：
//	int star[22]={330,124,351,128,354,149,365,131,386,134,372,118,381,99,362,107,347,92,349,114,330,124};
//	setcolor(WHITE);
//	fillpoly(11,star);
//	
//	for(int j = 0; j < 22; j++){
//		star[j] = star[j] - 50;
//	}
//	fillpoly(11,star);
//
//	for(int j = 0; j < 22; j++){
//		star[j] = star[j] - 36;
//	}
//	
//	fillpoly(11,star);
//	
//	for(int j = 0; j < 22; j = j + 2){
//		star[j] = star[j] - 50;
//	}
//	
//	fillpoly(11,star);
//	
//	for(int j = 0; j < 22; j = j + 2){
//		star[j] = star[j] + 200;
//	}
//	
//	fillpoly(11,star);
//	
//	for(int j = 1; j < 22; j = j + 2){
//		star[j] = star[j] + 50;
//	}
//	
//	fillpoly(11,star);
//
//	for(int j = 1; j < 22; j = j + 2){
//		star[j] = star[j] + 50;
//	}
//	fillpoly(11,star);
//	
//	for(int j = 0; j < 22; j = j + 2){
//		star[j] = star[j] + 50;
//	}
//	
//	fillpoly(11,star);
//	
//	
//	
//	for(int j = 1; j < 22; j = j + 2){
//		star[j] = star[j]-80;
//	}
//	for(int j = 0; j < 22; j = j + 2){
//		star[j] = star[j]-300;
//	}
//	for(int j = 0; j < 22; j = j + 2){
//		star[j] = star[j]*0.5;
//	}
//	for(int j = 1; j < 22; j = j + 2){
//		star[j] = star[j]*0.5;
//	}
//
//	for(int k = 0;k < 22; k++){
//		printf("%d,",star[k]);
//	} 
//	fillpoly(11,star);
//	
//	
//	getch();
//	closegraph();
//	return 0; 
//}
