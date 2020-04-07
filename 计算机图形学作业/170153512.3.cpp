#include <stdio.h>
#include <graphics.h>
int main(){
	initgraph(1000,640);
	setbkcolor(BLACK);
	int act[10] = {700,200,700,400,950,400,950,200,700,200};
	setlinewidth(3);
	setfillcolor(RED);
	circle(500,300,150);
	moveto(500,300);
	linerel(0,-150);
	moveto(500,300);
	linerel(-75,129.9);
	moveto(500,300);
	linerel(-130,-76);
	moveto(500,300);
	linerel(129.9,-75);
	moveto(500,300);
	floodfillsurface(500,301,BLACK); 
	setfillcolor(EGERGB(128,0,128));
	floodfillsurface(499,289,BLACK); 
	setfillcolor(EGERGB(128,0,80));
	floodfillsurface(450,301,BLACK);
	setfillcolor(YELLOW);
	floodfillsurface(502,267,BLACK); 
	drawpoly(5,act); 	 
	int smallsquare[10] = {720,220,735,220,735,235,720,235,720,220};
	drawpoly(5,smallsquare);
	setfillcolor(RED);
	floodfillsurface(smallsquare[0]+1,smallsquare[1]+1,BLACK); 
	outtextrect(smallsquare[0] + 40,smallsquare[1]/2 + smallsquare[5]/2 - 8,200,100,"huadong");
	for(int i = 1; i < 10 ; i = i + 2) {
		smallsquare[i] = smallsquare[i] + 42;
	}
	drawpoly(5,smallsquare);
	setfillcolor(EGERGB(128,0,128));
	floodfillsurface(smallsquare[0]+1,smallsquare[1]+1,BLACK);
	outtextrect(smallsquare[0] + 40,smallsquare[1]/2 + smallsquare[5]/2 - 8,200,100,"huadbei");
	for(int i = 1; i < 10 ; i = i + 2) {
		smallsquare[i] = smallsquare[i] + 42;
	}
	drawpoly(5,smallsquare);
	setfillcolor(EGERGB(128,0,80));
	floodfillsurface(smallsquare[0]+1,smallsquare[1]+1,BLACK);
	outtextrect(smallsquare[0] + 40,smallsquare[1]/2 + smallsquare[5]/2 - 8,200,100,"huanan");
	for(int i = 1; i < 10 ; i = i + 2) {
		smallsquare[i] = smallsquare[i] + 42;
	}
	drawpoly(5,smallsquare);
	setfillcolor(YELLOW);
	floodfillsurface(smallsquare[0]+1,smallsquare[1]+1,BLACK);
	outtextrect(smallsquare[0] + 40,smallsquare[1]/2 + smallsquare[5]/2 - 8,200,100,"huaxi");
	LOGFONTA f;
	getfont(&f);                          // 获取当前字体设置
	f.lfHeight = 48;                      // 设置字体高度为 48（包含行距）
	strcpy(f.lfFaceName, "黑体");         // 设置字体为“黑体”
	f.lfQuality = ANTIALIASED_QUALITY;    // 设置输出效果为抗锯齿  
	//设置字体颜色用的是什么鬼！ 
	setfont(&f);                          // 设置字体样式
	outtextxy(480,50,"销售表");
	getch();
	closegraph();
	return 0; 
} 
