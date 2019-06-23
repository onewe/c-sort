#include "rectangle.h"

//画箭头
static void drawArrow(Rectangle* src,Rectangle* target);
//删除箭头
static void delArrow(Rectangle* src,Rectangle* target);

//创建对象
Rectangle* createRec(int x,int y,int width,int height,int fColor,int bColor,int value){
	Rectangle *rec;
	rec = (Rectangle*)malloc(sizeof(Rectangle));
	rec->x = x;
	rec->y = y;
	rec->width = width;
	rec->height = height;
	rec->value = value;
	rec->draw = draw;
	rec->swap = swap;
	rec->del=del;
	rec->colorNum = fColor+bColor;		
	rec->compare=compare;
	init_pair(rec->colorNum,fColor,bColor);
	return rec;
}

//销毁对象
void destroy(Rectangle* rec){
	free(rec);
}
//显示图形
void draw(Rectangle* rec,bool isBlink){
	if(isBlink)
		attron(A_BLINK);
	attron(COLOR_PAIR(rec->colorNum));
	int height = rec->height;
	int width = rec->width;
	move(rec->y,rec->x);
	for(int i = 1; i <= height; i++){
		//移动光标
		move(rec->y - i,rec->x);
		for(int j = 0; j < width; j++){
			printw("█");
		}
	
	}
	if(isBlink)
		attroff(A_BLINK);
	attroff(COLOR_PAIR(rec->colorNum));
	move(0,0);
	refresh();

}
//删除图形
void del(Rectangle* rec){
	int height = rec->height;
	int width = rec->width;
	move(rec->y,rec->x);
	for(int i = 1; i <= height; i++){
		move(rec->y - i,rec->x);
		for(int j = 0; j < width; j++){
			printw(" ");
		}
	}
	move(0,0);
	refresh();

}
//交换图形
void swap(Rectangle* src,Rectangle* target){
	drawArrow(src,target);
	draw(target,true);
	sleep(1);
	delArrow(src,target);
	int srcX = src->x;
	int targetX = target->x;

	del(src);
	del(target);

	src->x = targetX;
	target->x = srcX;
	draw(src,false);
	draw(target,false);
	
	
}
//比较,就是一个特效
void compare(Rectangle* src,Rectangle* target){
	beep();
	drawArrow(src,target);
	usleep(1000 * 300);
	delArrow(src,target);

}

//箭头
static void drawArrow(Rectangle* src,Rectangle* target){
	//起点x坐标
	int startX = src->x + (src->width - 1) / 2;
	//起点y坐标
	int startY = src->y - src->height;
	
	//终点x坐标
	int endX = target->x + (target->width - 1) / 2;
	//终点y坐标
	int endY = target->y - target->height;

	attron(COLOR_PAIR(src->colorNum));
	move(startY,startX);
	for(int i = startY - 1;i >= ARROW_LIMIT_Y;i--){
		move(i,startX);
		if(i == ARROW_LIMIT_Y){
			printw("*");
		}else{
			printw("|");
		}
	}
	attroff(COLOR_PAIR(src->colorNum));	
	for(int i = startX + 1;i <= endX;i++){
		move(ARROW_LIMIT_Y,i);
		printw("-");
	}
	attron(COLOR_PAIR(target->colorNum));
	for(int i = ARROW_LIMIT_Y;i < endY;i++){
		move(i,endX);
		if(i == (endY - 1)){
			printw("∨");
		}else{
			if(i == ARROW_LIMIT_Y){
				printw("*");
			}else{
				printw("|");
			}
		}
	}
	attroff(COLOR_PAIR(target->colorNum));
	move(0,0);
	refresh();
}

//擦除箭头
static void delArrow(Rectangle* src,Rectangle* target){
	//起点x坐标
	int startX = src->x + (src->width - 1) / 2;
	//起点y坐标
	int startY = src->y - src->height;
	
	//终点x坐标
	int endX = target->x + (target->width - 1) / 2;
	//终点y坐标
	int endY = target->y - target->height;

	move(startY,startX);
	for(int i = startY - 1;i >= ARROW_LIMIT_Y;i--){
		move(i,startX);
		printw(" ");
	}
	for(int i = startX + 1;i <= endX;i++){
		move(ARROW_LIMIT_Y,i);
		printw(" ");
	}
	for(int i = ARROW_LIMIT_Y;i < endY;i++){
		move(i,endX);
		printw(" ");
	}
	move(0,0);
	refresh();
}

