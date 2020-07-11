//// Created by lsjss on 2020/6/10.
//
//typedef struct {
//    int u;        //边的起始顶点
//    int v;      //边的终止顶点
//    int w;    //边的权值
//} Edge;
//
//void Kruskal(MatGraph g) {
//    int i, j, u1, v1, sn1, sn2, k;
//    int vset[MAXV];
//    Edge E[MaxSize];    //存放所有边
//    k = 0;    //E数组的下标从0开始计
//    for (i = 0; i < g.n; i++) //由g产生的边集E
//        for (j = 0; j < g.n; j++)
//            if (g.edges[i][j] != 0 && g.edges[i][j] != INF) {
//                E[k].u = i;
//                E[k].v = j;
//                E[k].w = g.edges[i][j];
//                k++;
//            }
//    InsertSort(E, g.e);        //用直接插入排序对E数组按权值递增排序
//    for (i = 0; i < g.n; i++)    //初始化辅助数组
//        vset[i] = i;
//
//    k = 1;                //k表示当前构造生成树的第几条边
//    j = 0;                //E中边的下标，初值为0
//    while (k < g.n)        //生成的边数小于n时循环
//    {
//        u1 = E[j].u;
//        v1 = E[j].v;    //取一条边的头尾顶点
//        sn1 = vset[u1];
//        sn2 = vset[v1];        //分别得到两个顶点所属的集合编号
//        if (sn1 != sn2)        //两顶点属于不同的集合
//        {
//            printf("  (%d，%d):%d\n", u1, v1, E[j].w);
//            k++;            //生成边数增1
//            for (i = 0; i < g.n; i++)    //两个集合统一编号
//                if (vset[i] == sn2)    //集合编号为sn2的改为sn1
//                    vset[i] = sn1
//        }
//        j++;            //扫描下一条边
//    }
//}
//
//
//// 改进的Kruskal算法
//void Kruskal(MatGraph g) {
//    int i, j, k, u1, v1, sn1, sn2;
//    UFSTree t[MaxSize];
//    Edge E[MaxSize];
//    k = 1;  //e数组的下标从1开始计
//    for (i = 0; i < g.n; i++)   //由g产生的边集E
//        for (j = 0; j <= i; j++)
//            if (g.edges[i][j] != 0 && g.edges[i][j] != INF) {
//                E[k].u = i;
//                E[k].v = j;
//                E[k].w = g.edges[i][j];
//                k++;
//            }
//    HeapSort(E, g.e);    //采用堆排序对E数组按权值递增排序
//
//    MAKE_SET(t, g.n);    //初始化并查集树t
//    k = 1;    //k表示当前构造生成树的第几条边,初值为1
//    j = 1;    //E中边的下标从1开始
//    while (k < g.n) { //生成的边数小于n时循环
//        u1 = E[j].u;
//        v1 = E[j].v;  //取一条边的头尾顶点编号u1和v2
//        sn1 = FIND_SET(t, u1);
//        sn2 = FIND_SET(t, v1); //分别得到两个顶点所属的集合编号
//        if (sn1 != sn2)   //两顶点属不同的集合,是最小生成树的边
//        {
//            printf("  (%d,%d):%d\n", u1, v1, E[j].w);
//            k++;            //生成边数增1
//            UNION(t, u1, v1);    //将u1和v1两个顶点合并
//        }
//        j++;    //扫描下一条边
//    }
//}
//
//
