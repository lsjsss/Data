// Created by lsjss on 2020/6/10.
//
//#define MAXV 100
//#define INF 32767        //INF表示∞
//typedef int InfoType;
//typedef struct {
//    int no; //顶点编号
//    InfoType info;  //顶点其他信息
//} VertexType;
//typedef struct {    //图的定义
//    int edges[MAXV][MAXV];  //邻接矩阵
//    int n, e;   //顶点数，边数
//    VertexType vexs[MAXV];  //存放顶点信息
//} MatGraph;
//
//typedef struct ANode {
//    int adjvex; //该边的终点编号
//    struct ANode *nextarc;  //指向下一条边的指针
//    InfoType weight;    //该边的权值等信息
//} ArcNode;
//
//typedef struct Vnode {
//    Vertex data;    //顶点信息
//    ArcNode *firstarc;  //指向第一条边
//} VNode;
//
//typedef struct {
//    VNode adjlist[MAXV];    //邻接表
//    int n, e;   //图中顶点数n和边数e
//} AdjGraph;
//
////1 创建图的运算算法
//void CreateAdj(AdjGraph *&G, int A[MAXV][MAXV], int n, int e) { //创建图的邻接表
//    int i, j;
//    ArcNode *p;
//    G = (AdjGraph *) malloc(sizeof(AdjGraph));
//    for (i = 0; i < n; i++) //给邻接表中所有头结点的指针域置初值
//        G->adjlist[i].firstarc = NULL;
//    for (i = 0; i < n; i++) //检查邻接矩阵中每个元素
//        for (j = n - 1; j >= 0; j--)
//            if (A[i][j] != 0 && A[i][j] != INF) {   //存在一条边
//                p = (ArcNode *) malloc(sizeof(ArcNode)); //创建一个结点p
//                p->adjvex = j;  //存放邻接点
//                p->weight = A[i][j];    //存放权
//                p->nextarc = G->adjlist[i].firstarc;    //采用头插法插入结点p
//                G->adjlist[i].firstarc = p;
//            }
//    G->n = n;
//    G->e = e;
//}
//
////2 输出图的运算算法
//void DispAdj(AdjGraph *G) { //输出邻接表G
//    int i;
//    ArcNode *p;
//    for (i = 0; i < G->n; i++) {
//        p = G->adjlist[i].firstarc;
//        printf("%3d: ", i);
//        while (p != NULL) {
//            printf("%3d[%d]→", p->adjvex, p->weight);
//            p = p->nextarc;
//        }
//        printf("∧\n");
//    }
//}
//
////3 销毁图的运算算法
//void DestroyAdj(AdjGraph *&G) { //销毁邻接表
//    int i;
//    ArcNode *pre, *p;
//    for (i = 0; i < G->n; i++) {    //扫描所有的单链表
//        pre = G->adjlist[i].firstarc;   //p指向第i个单链表的首结点
//        if (pre != NULL) {
//            p = pre->nextarc;
//            while (p != NULL) { //释放第i个单链表的所有边结点
//                free(pre);
//                pre = p;
//                p = p->nextarc;
//            }
//            free(pre);
//        }
//    }
//    free(G);    //释放头结点数组
//}
//


