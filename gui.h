#ifndef GUI_H
#define GUI_H

#include <ncurses.h>
#include <menu.h>
#include <stdlib.h>
#include "sortItem.h"

typedef struct sortGUI SortGUI;

struct sortGUI{
	MENU *menu;//菜单对象
	void (*initMenu)(SortGUI* sortGUI);//初始化菜单
	void (*showMenu)(SortGUI* sortGUI);//显示菜单
	void (*hiddenMenu)(SortGUI* sortGUI);//隐藏菜单
	void (*destroyMenu)(SortGUI* sortGUI);//销毁菜单
	void (*destroyGUI)(SortGUI* sortGUI);//销毁GUI
};

//初始化GUI
SortGUI* initGUI();
//初始化菜单
void initMenu(SortGUI* sortGUI);
//显示菜单
void showMenu(SortGUI* sortGUI);
//隐藏菜单
void hiddenMenu(SortGUI* sortGUI);
//销毁菜单
void destroyMenu(SortGUI* sortGUI);
//销毁GUI
void destroyGUI(SortGUI* sortGUI);

#endif
