#pragma once

/*
顺序实现队列：先进先出
*/
const int maxsize = 20;
typedef struct seqqueue
{
	double data[maxsize];
	int front, rear;
}SeqQue;

