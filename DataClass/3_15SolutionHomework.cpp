// Created by lsjss on 2020/3/16.

#include <iostream>
#include <math.h>
using namespace std;
//#define equation main

int solution( double a, double b, double c, double &x1, double &x2 );
int equation(){
    double a, b, c, x1, x2;
    int detla;
    cout << "输入一元二次方程组的各项系数 a, b, c,计算这个方程的根 x1, x2:";
    cin >> a >> b >> c;
    detla = solution( a, b, c, x1, x2);
    if(detla==2){
        cout << "方程组有两个根，x1=" << x1 << ", x2=" << x2 << endl;
    }else if(detla==1){
        cout << "方程组有一个根，x1=x2=" << x1 << endl;
    }else if(detla==0){
        cout << "方程组没有根。" << endl;
    }
}

int solution( double a, double b, double c, double &x1, double &x2 ){
    double delta;
    delta = b * b - 4 * a * c;
    if(delta > 0){
        x1 = (-b + sqrt(delta)) / 2 * a;
        x2 = (-b - sqrt(delta)) / 2 * a;
        return 2;
    }else if(delta < 0){
        return 0;
    }else{
        x1 = -b / (2 * a);
        return 1;
    }
}


//
////Created by lsjss on 2020/3/11.
//#include <iostream>
//#include <math.h>
//using namespace std;
//#define equation main
//
//int solution( double a, double b, double c, double &x1, double &x2 );
//int equation(){
//    double a, b, c, x1, x2;
//    int detla;
//    printf("输入一元二次方程组的各项系数 a, b, c,计算这个方程的根 x1, x2:");
//    scanf("%lf %lf %lf", &a, &b, &c);
//    detla = solution( a, b, c, x1, x2);
//    if(detla==2){
//        printf("方程组有两个根，x1=%.2lf, x2=%.2lf", x1, x2);
//    }else if(detla==1){
//        printf("方程组有一个根，x1=x2=%.2lf", &x1 );
//    }else if(detla==0){
//        printf("方程组没有根。");
//    }
//}
//
//int solution( double a, double b, double c, double &x1, double &x2 ){
//    double delta;
//    delta = b * b - 4 * a * c;
//    if(delta > 0){
//        x1 = (-b + sqrt(delta)) / 2 * a;
//        x2 = (-b - sqrt(delta)) / 2 * a;
//        return 2;
//    }else if(delta < 0){
//        return 0;
//    }else if(delta == 0){
//        x1 = -b / (2.0 * a);
//        return 1;
//    }
//}


//void fun( int b[] , int n )
//{   int i, j, k, x;
//    for ( i=0; i<n-1; i++)
//    {  k = i ;
//        for ( j = i+1; j < n ; j++)
//            if ( b[k] > b[j])  k=j;
//        x = b[i]; b[i] = b[k]; b[k] = x;
//    }
//}







//
////
//// Created by Dell on 2020/3/11.
////
//#include <iostream>
//#include <stdio.h>
//#include <math.h>
//#define Test0311 main
//
//using namespace std;
//int solution(double a, double b, double c, double &x1, double &x2);
//int Test0311(){
//    double a, b, c, x1, x2, d;//定义方程的3个系数a，b，c，一级方程的两个x1，x2,d
//    cin>>a>>b>>c;
////    scanf("%f,%f,%f", &a, &b, &c);
//    d = solution( a, b, c, x1, x2);
//    if(d==2){
//        cout<<"x1"<<x1<<"x2"<<x2;
////        printf("该一元二次方程有两个解：x1=%f, x2=%f\n", x1, x2);
//    }else if(d==1){
//        cout<<"x1"<<x1;
////        printf("该一元二次方程有唯一解：x1=x2= %f\n", x1);
//    }else if(d==0){
//        cout<<"该一元二次方程无解"<<endl;
////        printf("该一元二次方程无解\n");
//    }
//
//    return 0;
//}
//
//int solution(double a, double b, double c, double &x1, double &x2){
//    double de;
//    de= (b*b) - (4*a*c);
//    if( de > 0 ){
//        x1 = ( -b+sqrt(de) ) / 2 * a;
//        x2 = ( -b-sqrt(de) ) / 2 * a;
//        return 2;
//    }
//    else if( de == 0 ){
//        x2 = x1 = -b / (2*a);
//        return 1;
//    }
//    else if( de < 0 ){
//        return 0;
//    }
//}




//
////
//#include<iostream>
//#include<math.h>
//int solution(int a,int b,int c,double &x1,double &x2){
//    double d;
//    d=(b*b)-(4*a*c);
//    if(d>0){
//        x1=(-b+sqrt(d))/(2*a);//x1的根
//        x2=(-b-sqrt(d))/(2*a);//x2的根
//        return 2;			  //两个实根
//    }else if(d==0){
//        x1=(-b)/(2*a);		  //x1的根
//        return 1;			  //一个实根
//    }else if(d<0){
//        return 0;			  //不存在实根
//    }
//}
//int main(){
////	double m=1,n=2;
//    int a=1,b=1,c=1;//初始化a,b,c
//    double x1, x2;
//    double nums;
//    scanf("%d %d %d",&a,&b,&c);//键盘输入a,b,c
////    printf("%.2f,%.2f", (double)a,b/20.0);
////	nums=score(m,n);
//    int dc = solution(a,b,c,x1,x2);
//    if(dc==2){
//        printf("%.2lf,%.2lf", x1, x2);
//    }else if(dc==1){
//        printf("%.2lf", x1);
//    }else if(dc==0){
//        printf("无根");
//    }
//    return 0;
//}
//double score(double& x1,double& x2);
//double score(double& x1,double& x2){
//	double num[1];
//	if(x1!=x2){
//		num[1]=x1,x2;
//	}else if(x1=x2){
//		num[1]=x1;
//	}else{
//		return 0;
//	}
//	return 0;
//}
