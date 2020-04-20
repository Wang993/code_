// Perspective.cpp : ���ļ����� "main" ����������ִ�н��ڴ˴���ʼ��������
//

#include <graphics.h>
#include <ege.h>

//����
const double WINDOW_TOP = 0.0;
const double WINDOW_LEFT = 0.0;
const double WINDOW_RIGHT = 640;
const double WINDOW_BOTTOM = 480;
//�ӿ�
const double VIEWPORT_TOP = 50.0;
const double VIEWPORT_BOTTOM = 380.0;
const double VIEWPORT_LEFT = 50.0;
const double VIEWPORT_RIGHT = 540.0;
//����
double xpArr[8];
double ypArr[8];
double xvArr[8];
double yvArr[8];

/**
 * �����������Сֵ
 * 
 * @param p     ����
 * @param len   ���鳤��
 * @return ��Сֵ
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
 * ������������ֵ
 *
 * @param p     ����
 * @param len   ���鳤��
 * @return ���ֵ
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
 * ���붥���ͶӰx����
 * 
 * @param x     �����x����
 * @param z     �����z����
 * @param zPrp  ͶӰ�ο���
 * @param pos   ����λ��
 */
void insertIntoXpArr(double x, double z, double zPrp, int pos) {
    double xp = x * zPrp / (zPrp - z);
    xpArr[pos] = xp;
}

/**
 * ���붥���ͶӰy����
 *
 * @param y     �����y����
 * @param z     �����z����
 * @param zPrp  ͶӰ�ο���
 * @param pos   ����λ��
 */
void insertIntoYpArr(double y, double z, double zPrp, int pos) {
    double yp = y * zPrp / (zPrp - z);
    ypArr[pos] = yp;
}

/**
 * ���붥���ͶӰ����
 *
 * @param x     �����x����
 * @param y     �����y����
 * @param z     �����z����
 * @param zPrp  ͶӰ�ο���
 * @param pos   ����λ��
 */
void insertIntoXpYpArr(double x, double y, double z, double zPrp, int pos) {
    insertIntoXpArr(x, z, zPrp, pos);
    insertIntoYpArr(y, z, zPrp, pos);
}
/**
 * ������Ļ����ʾ��x����
 * 
 * @param xvMin     ����x������Сֵ
 * @param xw        ͶӰ�����x����
 * @param xwMin     ����x������Сֵ
 * @param sx        x����������
 * @param pos       ����λ��
 */
void insertIntoXvArr(double xvMin, double xw, double xwMin, double sx, int pos) {
    double xv = xvMin + (xw - xwMin) * sx;
    xvArr[pos] = xv;
}
/**
 * ������Ļ����ʾ��y����
 *
 * @param yvMin     ����y������Сֵ
 * @param yw        ͶӰ�����y����
 * @param ywMin     ����y������Сֵ
 * @param sy        y����������
 * @param pos       ����λ��
 */
void insertIntoYvArr(double yvMin, double yw, double ywMin, double sy, int pos) {
    double yv = yvMin + (yw - ywMin) * sy;
    yvArr[pos] = yv;
}

/*
 * ��ת����
 * 
 * @param y y����
 * @return ��ת�������
 */
double reversePosition(double y) {
    double middle = VIEWPORT_BOTTOM / 2;
    return y > VIEWPORT_BOTTOM ? y - 2 * (y - middle) : y + 2 * (middle - y);
}

int main() {
    setinitmode(0);
    initgraph(WINDOW_RIGHT, WINDOW_BOTTOM);
    setviewport(0, 10, 630, 470);

    //�۲��
    double projectPoint[3] = { 0, 0, 8 };

    //1����ֱ������ϵ��ȷ������������������
    double pointA[3] = { 0.5, 0.5, 0 }; //0
    double pointB[3] = { 0.5, 0.5, 1 }; //1
    double pointC[3] = { 1.5, 0.5, 1 }; //2
    double pointD[3] = { 1.5, 0.5, 0 }; //3
    double pointE[3] = { 0.5, 1.5, 0 }; //4
    double pointF[3] = { 0.5, 1.5, 1 }; //5
    double pointG[3] = { 1.5, 1.5, 1 }; //6
    double pointH[3] = { 1.5, 1.5, 0 }; //7

    //2��ȷ��������������ͶӰ����
    insertIntoXpYpArr(pointA[0], pointA[1], pointA[2], projectPoint[2], 0);
    insertIntoXpYpArr(pointB[0], pointB[1], pointB[2], projectPoint[2], 1);
    insertIntoXpYpArr(pointC[0], pointC[1], pointC[2], projectPoint[2], 2);
    insertIntoXpYpArr(pointD[0], pointD[1], pointD[2], projectPoint[2], 3);
    insertIntoXpYpArr(pointE[0], pointE[1], pointE[2], projectPoint[2], 4);
    insertIntoXpYpArr(pointF[0], pointF[1], pointF[2], projectPoint[2], 5);
    insertIntoXpYpArr(pointG[0], pointG[1], pointG[2], projectPoint[2], 6);
    insertIntoXpYpArr(pointH[0], pointH[1], pointH[2], projectPoint[2], 7);

    //3����ͶӰ����任����Ļ�ϣ�������ߡ�
    //3.1���������ֵ
    double xwMin = getMin(xpArr, 8);
    double xwMax = getMax(xpArr, 8);
    double ywMin = getMin(ypArr, 8);
    double ywMax = getMax(ypArr, 8);
    double sx = (double)(VIEWPORT_RIGHT - VIEWPORT_LEFT) / (xwMax - xwMin);
    double sy = (double)(VIEWPORT_BOTTOM - VIEWPORT_TOP) / (ywMax - ywMin);

    //3.2����Ļ�����������
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

    //3.3������
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

// ���г���: Ctrl + F5 ����� >����ʼִ��(������)���˵�
// ���Գ���: F5 ����� >����ʼ���ԡ��˵�

// ����ʹ�ü���: 
//   1. ʹ�ý��������Դ�������������/�����ļ�
//   2. ʹ���Ŷ���Դ�������������ӵ�Դ�������
//   3. ʹ��������ڲ鿴���������������Ϣ
//   4. ʹ�ô����б��ڲ鿴����
//   5. ת������Ŀ��>���������Դ����µĴ����ļ�����ת������Ŀ��>�����������Խ����д����ļ���ӵ���Ŀ
//   6. ��������Ҫ�ٴδ򿪴���Ŀ����ת�����ļ���>���򿪡�>����Ŀ����ѡ�� .sln �ļ�

