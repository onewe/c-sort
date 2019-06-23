#include "rectangle.h"
#include "gui.h"
#include <time.h>
//颜色种类个数
#define COLOR_SIZE 15 
//矩形数组大小
#define RECTANGLE_ARR_SIZE 15
#define RANDOM_VALUE_RANGE 30

typedef struct{
	int backColor;
	int frontColor;
}ColorConf;

//返回待排序的矩形数组
static Rectangle** randomRectangleArrays();
//初始化配置
static void initColorConfs();
//输出柱状数组
static void printArr(Rectangle** rectangleArr,int len);

//数组
static ColorConf colorConfs[COLOR_SIZE] = {
	{COLOR_BLACK,COLOR_RED},
	{COLOR_BLACK,COLOR_WHITE},
	{COLOR_BLACK,COLOR_GREEN},
	{COLOR_BLACK,COLOR_YELLOW},
	{COLOR_BLACK,COLOR_BLUE},
	{COLOR_BLACK,COLOR_MAGENTA},
	{COLOR_BLACK,COLOR_CYAN},
	{COLOR_BLACK,7},
	{COLOR_BLACK,8},
	{COLOR_BLACK,9},
	{COLOR_BLACK,10},
	{COLOR_BLACK,11},
	{COLOR_BLACK,12},
	{COLOR_BLACK,13},
	{COLOR_BLACK,14}
};

int main(int argc,char** args){
	setlocale(LC_ALL,"");	
	initscr();
	curs_set(0);
	//开启颜色
	start_color();
	//关闭行缓冲
	cbreak();
	//关闭回显
	noecho();
	Rectangle** recArrays;
	recArrays = randomRectangleArrays();
	printArr(recArrays,RECTANGLE_ARR_SIZE);
	getch();
	//排序
	for(int i=0;i<RECTANGLE_ARR_SIZE;i++){
		for(int j=i+1;j<RECTANGLE_ARR_SIZE;j++){
			recArrays[i]->compare(recArrays[i],recArrays[j]);
			if(recArrays[i]->value > recArrays[j]->value){
				recArrays[i]->swap(recArrays[i],recArrays[j]);
				Rectangle* temp = recArrays[i];
				recArrays[i] = recArrays[j];
				recArrays[j] = temp;
			}
		}

	}
	printArr(recArrays,RECTANGLE_ARR_SIZE);
	getch();
	endwin();
	return 0;

}

//输出柱状数组
static void printArr(Rectangle** arr,int len){

	for(int i=0;i<len;i++){
		beep();
		arr[i]->del(arr[i]);
		usleep(1000 * 70);
		arr[i]->draw(arr[i],false);
		usleep(1000 * 60);
	}


}

//生成随机矩形数组
static Rectangle** randomRectangleArrays(){
	srand(time(NULL));
	//高度单元
	int heightUnit = (LINES - SHARP_LIMIT_Y) / RANDOM_VALUE_RANGE;
	int widthUnit = COLS / RECTANGLE_ARR_SIZE;
	Rectangle** recArrays;
	recArrays = malloc(sizeof(Rectangle*)*RECTANGLE_ARR_SIZE);
	for(int i = 0;i < RECTANGLE_ARR_SIZE; i++){
		ColorConf* colConf = colorConfs+i;
		int value = rand() % RANDOM_VALUE_RANGE + 1;
		Rectangle* rec;
		/**
		 *创建矩形
		 *createRec(
		 *,int x坐标
		 *,int Y坐标
		 *,int 宽度
		 *,int 高度
		 *,int 高度
		 *,int 前景色
		 *,int 背景色
		 *,int 值
		 *);
		 * */
		rec = createRec(i*widthUnit,LINES,widthUnit,heightUnit*value,colConf->frontColor,colConf->backColor,value);
		recArrays[i] = rec;
	}
	
	return recArrays;
}

