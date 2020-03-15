////
//// Created by lsjss on 2020/3/10.
////
//#include <iostream>
//#include <math.h>
//#include <ccomplex>
////#define Complex main
//
//typedef struct Complex {
//    double e1; // 实部
//    double e2; // 虚部
//}C;
//
//// 函数声明
//C AssignComplex(double v1, double v2);
//void DestroyComplex(C pc);
//double GetReal(C pc);
//double GetImag(C pc);
//C Add(C z1, C z2);
//
//
//int Complex(void) {
//    double v1 = 2.0, v2 = 3.0;
//    double v3 = 5.0, v4 = 8.5;
//    COMPLEX sum;
//    COMPLEX pc1 = AssignComplex(v1, v2);
//    COMPLEX pc2 = AssignComplex(v3, v4);
//
//    printf("第一个复数的实部为：%e, 虚部为：%e\n", GetReal(pc1), GetImag(pc1));
//
//    sum = Add(pc1, pc2);
//    printf("复数pc1与pc2之和的实部为：%e，虚部为：%e\n", sum.e1, sum.e2);
//    return 0;
//}
//
//
//C AssignComplex(double v1, double v2) {
//    COMPLEX pc;
//    pc.e1 = v1;
//    pc.e2 = v2;
//    return pc;
//}
//void DestroyComplex(C pc) {
//    // 销毁复数
//}
//double GetReal(C pc) {
//    double real = pc.e1;
//    return real;
//}
//
//double GetImag(C pc)
//{
//    double imag = pc.e2;
//    return imag;
//}
//C Add(C z1, C z2)
//{
//    COMPLEX sum;
//    double z1_e1, z2_e1;
//    double z1_e2, z2_e2;
//
//    z1_e1 = z1.e1;
//    z2_e1 = z2.e1;
//
//    z1_e2 = z1.e2;
//    z2_e2 = z2.e2;
//
//    sum.e1 = z1_e1 + z2_e1;
//    sum.e2 = z1_e2 + z2_e2;
//
//    return sum;
//}
