#include <graphics.h>
#include <stdio.h>
#include <stdlib.h>
//��д�������͸��ͶӰͼ
int main()
{
	initgraph(1000, 600);
	//������������ֱ������ϵ�ϸ��� p1-p8 
	int cube[3*8] = {-1,-1,-1, -2,-1,-1, -2,-1,-2, -1,-1,-2, -1,-2,-2, -2,-2,-2, -2,-2,-1, -1,-2,-1};
	float p[2*8];
	int newp[2*8];
	int i,j,k;
	//���� �ؾ�Zvp, �ӵ�Zprp,���� 
	float Zvp=0.8,Zprp=2.7,XVmax=300,XVmin=20,YVmax=300,YVmin=20;
	//ȷ���������ͶӰ���� 
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
	//�ҵ�Xp,Yp����ֵ
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
	//ͶӰ����任����Ļ�� 
	 for(j=0;j<16;j++){
		if(j%2==0){		//XV
			newp[j] = XVmin+(p[j]-Xpmin)*(XVmax-XVmin)/(Xpmax-Xpmin);
		}
		else{			//YV
			newp[j] = YVmin+(p[j]-Ypmin)*(YVmax-YVmin)/(Ypmax-Ypmin);
		}
	}
	//���� 
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



