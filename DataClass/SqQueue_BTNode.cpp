//// Created by lsjss on 2020/6/1.
///** 基于 BTNode 的 SqQueue */
//
//// 基于二叉树的顺序队
//#define MaxSize 50
//
//typedef struct {
//    BTNode *data[MaxSize];
//    int front, rear;    //队首和队尾指针
//} SqQueue;
//
////1 初始化队列
//void InitQueue(SqQueue *&q) {
//    q = (SqQueue *) malloc(sizeof(SqQueue));
//    q->front = q->rear = -1;
//}
//
////2 销毁队列
//void DestroyQueue(SqQueue *&q) {
//    free(q);
//}
//
////3 判断队列是否为空
//bool QueueEmpty(SqQueue *q) {
//    return (q->front == q->rear);
//}
//
////4 进队列
//bool enQueue(SqQueue *&q, BTNode *&e) {
//    if (q->rear == MaxSize - 1)    //队满上溢出
//        return false;
//    q->rear++;
//    q->data[q->rear] = e;
//    return true;
//}
//
////5 出队列
//bool deQueue(SqQueue *&q, BTNode *&e) {
//    if (q->front == q->rear)  //队空下溢出
//        return false;
//    q->front++;
//    e = q->data[q->front];
//    return true;
//}
