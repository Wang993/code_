#include <graphics.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
	initgraph(1000,640);
	//Step1:
	//��ֱ������ϵ��ȷ������������������
	int cube[8*3] = {-1,-1,-1, -2,-1,-1, -2,-1,-2, -1,-1,-2, -1,-2,-2, -2,-2,-2, -2,-2,-1, -1,-2,-1}; 
	//�������ͶӰ���꣬δ������Ļ�任 
	float point[8*2];
	//ͶӰ�������Ļ����
	int new_point[8*2];
	//ѭ������ 
	int i,j,k;
	//Step2:ȷ���������ͶӰ����
	//�趨��ز�����
	float Zvp=0.8,Zprp=2.7,XVmax=300,XVmin=20,YVmax=300,YVmin=20;
	for(i = 0; i< 16 ; i++){
		//�������꣬����Ϊ������
		if(i % 2 == 0){
			point[i] = cube[3*(i/2)] * ((Zprp - Zvp)/(Zprp - cube[3*(i/2)+2]));
		}
		if(i % 2 == 1){
			point[i] = cube[3*(i/2)+1] * ((Zprp - Zvp)/(Zprp - cube[3*(i/2)+2]));
		}
		 
	} 
	//ͨ�������㷨�ҵ����ֵ����Сֵ�� 
	int Xpmax = point[0],Xpmin = point[0];
	int Ypmax = point[1],Ypmin = point[1];
	for(k=0;k<16;k=k+2){
		if(point[k]>Xpmax)
			Xpmax=point[k];
		else if(point[k]<Xpmin)
			Xpmin=point[k];
	}	
 
	for(k=1;k<16;k=k+2){
		if(point[k]>Ypmax)
			Ypmax=point[k];
		else if(point[k]<Ypmin)
			Ypmin=point[k];
	}
	//ͶӰ����任����Ļ�� 
	for(j = 0;j < 16;j++){
		if(j % 2 == 0){		
			new_point[j] = XVmin+(point[j]-Xpmin)*(XVmax-XVmin)/(Xpmax-Xpmin);
			//����������� 
		}
		else{			
			new_point[j] = YVmin+(point[j]-Ypmin)*(YVmax-YVmin)/(Ypmax-Ypmin);
			//�����������
		}
	
	}
	//������������������ 
	setcolor(WHITE);
	drawpoly(8,new_point);	
	line(new_point[0],new_point[1],new_point[6],new_point[7]);
	line(new_point[0],new_point[1],new_point[14],new_point[15]);
	line(new_point[2],new_point[3],new_point[12],new_point[13]);
	line(new_point[4],new_point[6],new_point[10],new_point[11]);
	line(new_point[8],new_point[9],new_point[14],new_point[15]);
	getch();
	closegraph();
    return 0;
	
	
	
	
	
}
