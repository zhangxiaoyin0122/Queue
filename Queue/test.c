#include <stdio.h>
#include <stdlib.h>

typedef int QDataType;

typedef struct QNode {
	struct QNode* _next;
	QDataType _data;
}QNode;

typedef struct Queue {
	QNode* _front;
	QNode* _rear;
	int _size;
}Queue;
//队列初始化
void QueueInit(Queue* q) {
	q->_front = q->_rear = NULL;
	q->_size = 0;
}
//创建新结点
QNode* CreatNode(QDataType data) {
	QNode* node = (QNode*)malloc(sizeof(QNode));
	node->_data = data;
	node->_next = NULL;
	return node;
}
//队列入队
void QueuePush(Queue* q, QDataType data) {    //进队列
	QNode* node = CreatNode(data);
	if (q->_front == NULL) {
		q->_front = q->_rear = node;
	}
	else {
		q->_rear ->_next= node;//连接新节点
		q->_rear = node; //更新尾指针
	}
	++q->_size;
}
//队列出队
void QueuePop(Queue* q) {   //出队列
	if (q->_front) {
		QNode* next = q->_front->_next;
		free(q->_front);
		q->_front = next;
		if (q->_front == NULL) {
			q->_front = NULL;

		}
	}
	--q->_size;
}
//队列元素个数
int QueueSize(Queue* q) {
	return q->_size;
}
QDataType QueueFront(Queue* q) {
	return q->_front->_data;
}
QDataType QueueBack(Queue* q) {
	return q->_rear->_data;
}
int QueueEmpty(Queue* q) {
	if (q->_front == NULL)
		return 1;
	return 0;
}
void QueueDesity(Queue* q) {
	QNode* cur = q->_front;
	while (cur) {
		QNode* next = cur->_next;
		free(cur);
		cur = next;
	}
	q->_front = q->_rear = NULL;
	q->_size = 0;
}

void test() {
	Queue q;
	QueueInit(&q);
	QueuePush(&q, 1);
	QueuePush(&q, 2);
	QueuePush(&q, 3);
	QueuePush(&q, 4);
	while (QueueEmpty(&q) != 1) { //队列元素遍历的实现,调用已有函数
		printf("%d ", QueueFront(&q));
		QueuePop(&q);
	}
	printf("\n");
}
int main() {
	test();
	system("pause");
	return 0;
}