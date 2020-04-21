#include <graphics.h>
#include <stdio.h>
#include <stdlib.h>
//编写立方体的透视投影图
int main()
{
	initgraph(1000, 600);
	//定义立方体在直角坐标系上各点 p1-p8 
	int cube[3*8] = {-1,-1,-1, -2,-1,-1, -2,-1,-2, -1,-1,-2, -1,-2,-2, -2,-2,-2, -2,-2,-1, -1,-2,-1};
	float p[2*8];
	int newp[2*8];
	int i,j,k;
	//定义 截距Zvp, 视点Zprp,视区 
	float Zvp=0.8,Zprp=2.7,XVmax=300,XVmin=20,YVmax=300,YVmin=20;
	//确定立方体的投影坐标 
	for(i=0;i<16;i++){
		//Xp
		if(i%2==0){		
			p[i] = cube[3*(i/2)]*((Zprp-Zvp)/(Zprp-cube[3*(i/2)+2]));	
		}
		//Yp
		else{			
			p[i] = cube[3*(i/2)+1]*((Zprp-Zvp)/(Zprp-cube[3*(i/2)+2]));	
		}		
	}
	//找到Xp,Yp的最值
	int Xpmax = p[0],Xpmin = p[0];
	int Ypmax = p[1],Ypmin = p[1];
	
	for(k=0;k<16;k=k+2){
		if(p[k]>Xpmax)
			Xpmax=p[k];
		else if(p[k]<Xpmin)
			Xpmin=p[k];
	}	
 
	for(k=1;k<16;k=k+2){
		if(p[k]>Ypmax)
			Ypmax=p[k];
		else if(p[k]<Ypmin)
			Ypmin=p[k];
	}
	//投影坐标变换到屏幕上 
	 for(j=0;j<16;j++){
		if(j%2==0){		//XV
			newp[j] = XVmin+(p[j]-Xpmin)*(XVmax-XVmin)/(Xpmax-Xpmin);
		}
		else{			//YV
			newp[j] = YVmin+(p[j]-Ypmin)*(YVmax-YVmin)/(Ypmax-Ypmin);
		}
	}
	//连线 
	setcolor(RED);
	drawpoly(8,newp);
	//p1-p4
	line(newp[0],newp[1],newp[6],newp[7]);
	//p1-p8 
	line(newp[0],newp[1],newp[14],newp[15]);
	//p2-p7
	line(newp[2],newp[3],newp[12],newp[13]);
	//p3-p6
	line(newp[4],newp[6],newp[10],newp[11]);
	//p5-p8
	line(newp[8],newp[9],newp[14],newp[15]);
	
	getch();
	closegraph();
    return 0;
} 



