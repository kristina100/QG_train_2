#include "RcdSqList.h"

Status InitList_Sq(RcdSqList &L, long size, long increment){
   L.rcd = (RcdType*)malloc(size*sizeof(RcdType));
   if(nullptr==L.rcd) return OVERFLOW;
   L.length = 0;       // ÖÃLÎª¿ÕÕ»±í
   L.size = size; 
   L.increment = increment; 
   return OK;
}

Status Append_Sq(RcdSqList &L, RcdType e){
   RcdType *newbase;
   if(L.length + 1>=L.size){//À©ÈÝ
	   newbase = (RcdType*)realloc(L.rcd, (L.size+L.increment)*sizeof(RcdType));
       if(nullptr==newbase) return OVERFLOW;
       L.rcd = newbase;
       L.size += L.increment;
    }
    L.length++;
    L.rcd[L.length] = e; 
	return OK;
}

Status DeleteLast_Sq(RcdSqList &L, RcdType &e){
	if (0 == L.length) return ERROR;
	e = L.rcd[L.length];
	L.length--;
	return OK;
}


Status DestroyList_Sq(RcdSqList &L){
	free(L.rcd);
	return OK;
}

