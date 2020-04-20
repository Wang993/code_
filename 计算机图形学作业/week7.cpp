// Perspective.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <graphics.h>
#include <ege.h>

//窗口
const double WINDOW_TOP = 0.0;
const double WINDOW_LEFT = 0.0;
const double WINDOW_RIGHT = 640;
const double WINDOW_BOTTOM = 480;
//视口
const double VIEWPORT_TOP = 50.0;
const double VIEWPORT_BOTTOM = 380.0;
const double VIEWPORT_LEFT = 50.0;
const double VIEWPORT_RIGHT = 540.0;
//数组
double xpArr[8];
double ypArr[8];
double xvArr[8];
double yvArr[8];

/**
 * 计算数组的最小值
 * 
 * @param p     数组
 * @param len   数组长度
 * @return 最小值
 */
double getMin(double* p, int len) {
    int j;
    double min = p[0];

    for (j = 0; j < len; j++) {
        if (p[j] < min) {
            min = p[j];
        }
    }
    return min;
}

/**
 * 计算数组的最大值
 *
 * @param p     数组
 * @param len   数组长度
 * @return 最大值
 */
double getMax(double* p, int len) {
    int j;
    double max = p[0];

    for (j = 0; j < len; j++) {
        if (p[j] >= max) {
            max = p[j];
        }
    }
    return max;
}

/**
 * 插入顶点的投影x坐标
 * 
 * @param x     顶点的x坐标
 * @param z     顶点的z坐标
 * @param zPrp  投影参考点
 * @param pos   数组位置
 */
void insertIntoXpArr(double x, double z, double zPrp, int pos) {
    double xp = x * zPrp / (zPrp - z);
    xpArr[pos] = xp;
}

/**
 * 插入顶点的投影y坐标
 *
 * @param y     顶点的y坐标
 * @param z     顶点的z坐标
 * @param zPrp  投影参考点
 * @param pos   数组位置
 */
void insertIntoYpArr(double y, double z, double zPrp, int pos) {
    double yp = y * zPrp / (zPrp - z);
    ypArr[pos] = yp;
}

/**
 * 插入顶点的投影坐标
 *
 * @param x     顶点的x坐标
 * @param y     顶点的y坐标
 * @param z     顶点的z坐标
 * @param zPrp  投影参考点
 * @param pos   数组位置
 */
void insertIntoXpYpArr(double x, double y, double z, double zPrp, int pos) {
    insertIntoXpArr(x, z, zPrp, pos);
    insertIntoYpArr(y, z, zPrp, pos);
}
/**
 * 计算屏幕上显示的x坐标
 * 
 * @param xvMin     视区x坐标最小值
 * @param xw        投影顶点的x坐标
 * @param xwMin     窗口x坐标最小值
 * @param sx        x轴缩放因子
 * @param pos       数组位置
 */
void insertIntoXvArr(double xvMin, double xw, double xwMin, double sx, int pos) {
    double xv = xvMin + (xw - xwMin) * sx;
    xvArr[pos] = xv;
}
/**
 * 计算屏幕上显示的y坐标
 *
 * @param yvMin     视区y坐标最小值
 * @param yw        投影顶点的y坐标
 * @param ywMin     窗口y坐标最小值
 * @param sy        y轴缩放因子
 * @param pos       数组位置
 */
void insertIntoYvArr(double yvMin, double yw, double ywMin, double sy, int pos) {
    double yv = yvMin + (yw - ywMin) * sy;
    yvArr[pos] = yv;
}

/*
 * 翻转坐标
 * 
 * @param y y坐标
 * @return 翻转后的坐标
 */
double reversePosition(double y) {
    double middle = VIEWPORT_BOTTOM / 2;
    return y > VIEWPORT_BOTTOM ? y - 2 * (y - middle) : y + 2 * (middle - y);
}

int main() {
    setinitmode(0);
    initgraph(WINDOW_RIGHT, WINDOW_BOTTOM);
    setviewport(0, 10, 630, 470);

    //观察点
    double projectPoint[3] = { 0, 0, 8 };

    //1、在直角坐标系中确定立方体各顶点的坐标
    double pointA[3] = { 0.5, 0.5, 0 }; //0
    double pointB[3] = { 0.5, 0.5, 1 }; //1
    double pointC[3] = { 1.5, 0.5, 1 }; //2
    double pointD[3] = { 1.5, 0.5, 0 }; //3
    double pointE[3] = { 0.5, 1.5, 0 }; //4
    double pointF[3] = { 0.5, 1.5, 1 }; //5
    double pointG[3] = { 1.5, 1.5, 1 }; //6
    double pointH[3] = { 1.5, 1.5, 0 }; //7

    //2、确定立方体各顶点的投影坐标
    insertIntoXpYpArr(pointA[0], pointA[1], pointA[2], projectPoint[2], 0);
    insertIntoXpYpArr(pointB[0], pointB[1], pointB[2], projectPoint[2], 1);
    insertIntoXpYpArr(pointC[0], pointC[1], pointC[2], projectPoint[2], 2);
    insertIntoXpYpArr(pointD[0], pointD[1], pointD[2], projectPoint[2], 3);
    insertIntoXpYpArr(pointE[0], pointE[1], pointE[2], projectPoint[2], 4);
    insertIntoXpYpArr(pointF[0], pointF[1], pointF[2], projectPoint[2], 5);
    insertIntoXpYpArr(pointG[0], pointG[1], pointG[2], projectPoint[2], 6);
    insertIntoXpYpArr(pointH[0], pointH[1], pointH[2], projectPoint[2], 7);

    //3、将投影坐标变换到屏幕上，最后连线。
    //3.1、计算相关值
    double xwMin = getMin(xpArr, 8);
    double xwMax = getMax(xpArr, 8);
    double ywMin = getMin(ypArr, 8);
    double ywMax = getMax(ypArr, 8);
    double sx = (double)(VIEWPORT_RIGHT - VIEWPORT_LEFT) / (xwMax - xwMin);
    double sy = (double)(VIEWPORT_BOTTOM - VIEWPORT_TOP) / (ywMax - ywMin);

    //3.2、屏幕坐标插入数组
    insertIntoXvArr(VIEWPORT_LEFT, xpArr[0], xwMin, sx, 0);
    insertIntoYvArr(VIEWPORT_TOP, ypArr[0], ywMin, sy, 0);
    insertIntoXvArr(VIEWPORT_LEFT, xpArr[1], xwMin, sx, 1);
    insertIntoYvArr(VIEWPORT_TOP, ypArr[1], ywMin, sy, 1);
    insertIntoXvArr(VIEWPORT_LEFT, xpArr[2], xwMin, sx, 2);
    insertIntoYvArr(VIEWPORT_TOP, ypArr[2], ywMin, sy, 2);
    insertIntoXvArr(VIEWPORT_LEFT, xpArr[3], xwMin, sx, 3);
    insertIntoYvArr(VIEWPORT_TOP, ypArr[3], ywMin, sy, 3);
    insertIntoXvArr(VIEWPORT_LEFT, xpArr[4], xwMin, sx, 4);
    insertIntoYvArr(VIEWPORT_TOP, ypArr[4], ywMin, sy, 4);
    insertIntoXvArr(VIEWPORT_LEFT, xpArr[5], xwMin, sx, 5);
    insertIntoYvArr(VIEWPORT_TOP, ypArr[5], ywMin, sy, 5);
    insertIntoXvArr(VIEWPORT_LEFT, xpArr[6], xwMin, sx, 6);
    insertIntoYvArr(VIEWPORT_TOP, ypArr[6], ywMin, sy, 6);
    insertIntoXvArr(VIEWPORT_LEFT, xpArr[7], xwMin, sx, 7);
    insertIntoYvArr(VIEWPORT_TOP, ypArr[7], ywMin, sy, 7);

    //3.3、连线
    line(xvArr[0], reversePosition(yvArr[0]), xvArr[1], reversePosition(yvArr[1]));	//AB
    line(xvArr[0], reversePosition(yvArr[0]), xvArr[3], reversePosition(yvArr[3]));	//AD
    line(xvArr[0], reversePosition(yvArr[0]), xvArr[4], reversePosition(yvArr[4]));	//AE
    line(xvArr[1], reversePosition(yvArr[1]), xvArr[2], reversePosition(yvArr[2]));	//BC
    line(xvArr[1], reversePosition(yvArr[1]), xvArr[5], reversePosition(yvArr[5]));	//BF
    line(xvArr[2], reversePosition(yvArr[2]), xvArr[3], reversePosition(yvArr[3]));	//CD
    line(xvArr[2], reversePosition(yvArr[2]), xvArr[6], reversePosition(yvArr[6]));	//CG
    line(xvArr[3], reversePosition(yvArr[3]), xvArr[7], reversePosition(yvArr[7]));	//DH
    line(xvArr[4], reversePosition(yvArr[4]), xvArr[5], reversePosition(yvArr[5]));	//EF
    line(xvArr[4], reversePosition(yvArr[4]), xvArr[7], reversePosition(yvArr[7]));	//EH
    line(xvArr[5], reversePosition(yvArr[5]), xvArr[6], reversePosition(yvArr[6]));	//FG
    line(xvArr[7], reversePosition(yvArr[7]), xvArr[6], reversePosition(yvArr[6]));	//HG

    getch();
    closegraph();
    return EXIT_SUCCESS;
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件

