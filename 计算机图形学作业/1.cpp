#include<stdio.h>
#include<graphics.h>
float decas(int degree,float coeff[],float t){
     int r,i;
     float t1;
     float coeffa[10];
     t1=1.0-t;
     for(i=0;i<=degree;i++){
         coeffa[i]=coeff[i];
     }
     for(r=1;r<=degree;r++){
        for(i=0;i<=degree-r;i++){
            coeffa[i]=t1*coeffa[i]+t*coeffa[i+1];
        }
     }
     return (coeffa[0]);
}
int main(){
    
 	int gd = DETECT, gm = 0;
 	initgraph(&gd, &gm, "c:\\TC\\BGI");
    cleardevice();
    setfont(18, 0, "宋体");
    setlinewidth(2);
    xyprintf(0,0,"鼠标在屏幕上单击得到四个控制点从而获取三次bezier曲线");
    
 	static int p[2*4];
	float i=0;int x,y;  //i为 p[]下标变量 ,x,y为临时变量用于规范数组下标的值 
	static float px[4];
	static float py[4]; 
    mouse_msg msg = {0};	
    for (i=0; is_run() ; delay_fps(60))
    {    	
        while (mousemsg()&&i<30)//获取鼠标消息，这个函数会等待，等待到有消息为止
        {
            msg = getmouse();//将鼠标运行信息存入mouse_msg结构体
        }        
		if(msg.is_down()==1){
			setcolor(RED);
			line(msg.x,msg.y,msg.x+1,msg.y+1);
			setcolor(WHITE);		
			x=i/4;y=i/4+1;		 
			if(x==1||x==3||x==5||x==7){
				x=x-1;
				y=y-1;
			p[x] = msg.x;
			p[y] = msg.y;
			xyprintf(0,20,"选定控制点坐标：num = %2d, (%2d,%2d)",x/2,msg.x, msg.y);
			}												
			i=i+1;
			
		}
		if(i >= 30)
		{
		px[0]=p[0];
		px[1]=p[2];
		px[2]=p[4];
		px[3]=p[6];
		py[0]=p[1];
		py[1]=p[3];
		py[2]=p[5];
		py[3]=p[7];
		int n=3;
		int k=3000;
		float t;
		for (int i=0;i<n;i++)
	        line(px[i],py[i],px[i+1],py[i+1]);
	    setcolor(YELLOW);
	    for(int i=0;i<=k;i++){
	        t=(float)i/k;
	        x=decas(n,px,t);
	        y=decas(n,py,t);
	        if(i==0)
	            moveto(x,y);
	        else
	            lineto(x,y);
		}
	}
    }
    getch();    
	return 0;       
}

