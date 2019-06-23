#ifndef RECTANGLE_H
#define RECTANGLE_H

#include <stdlib.h>
#include <unistd.h>
#include <locale.h>
#include <ncurses.h>
//图形Y坐标极限为3 为箭头留下空间
#define SHARP_LIMIT_Y 3
//箭头Y坐标极限为1
#define ARROW_LIMIT_Y 1

typedef struct rectangle  Rectangle;
struct rectangle{
	int x;//坐标x
	int y;//坐标y
	int width;//宽
	int height;//高
	int value;//值
	int fColor;//前景色
	int bColor;//背景色
	int colorNum;//颜色编号
	void (*draw)(Rectangle *rec,bool isBlink);//显示图形
	void (*del)(Rectangle *rec);//删除图形
	void (*swap)(Rectangle *src,Rectangle *target);//交换图形
	void (*compare)(Rectangle *src,Rectangle *target);//比较,就是一个特效

};

Rectangle* createRec(int x,int y,int width,int height,int fColor,int bColor,int value);//创建对象

void destroy(Rectangle* rec);//销毁对象

void draw(Rectangle* rec,bool isBlink);//显示图形

void del(Rectangle* rec);//删除图形

void swap(Rectangle* src,Rectangle* target);//交换图形

void compare(Rectangle* src,Rectangle* target);//比较,没啥特殊的,就是一个特效

#endif
