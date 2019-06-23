#include "gui.h"

//初始化GUI对象
SortGUI* initGUI(){
	SortGUI* gui;
	gui = malloc(sizeof(SortGUI));
	gui->menu = (MENU*)NULL;
	gui->initMenu = initMenu;
	gui->showMenu = showMenu;
	gui->hiddenMenu = hiddenMenu;
	gui->destroyMenu = destroyMenu;
	gui->destroyGUI = destroyGUI;
	return gui;
}

	

//初始化菜单
void initMenu(SortGUI* sortGUI){
	

}
//显示菜单
void showMenu(SortGUI* sortGUI){


}
//隐藏菜单
void hiddenMenu(SortGUI* sortGUI){

}
//销毁菜单
void destroyMenu(SortGUI* sortGUI){


}
//销毁菜单
void destroyGUI(SortGUI* sortGUI){

}
