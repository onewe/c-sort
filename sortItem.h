#ifndef SORT_ITEM_H
#define SORT_ITEM_H

#include "rectangle.h"

typedef struct sortItem SortItem;

struct sortItem{

	char* desc;//描述
	
	void (*sort)(Rectangle** recArray);//排序 
};
#endif
