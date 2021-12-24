#include "Common.h"
#include "HashTable.h"

typedef struct Node
{
     RcdType r;
     struct Node *next;
 } Node;

typedef struct
{
      Node **rcd;
	  int size;// 哈希表容量
      int count; // 当前表中含有的记录个数
      int (*hash)(KeyType key, int);  // 函数指针变量，用于选取的哈希函数
} CHashTable; 

Status InitHash(CHashTable &H, int size, int (*hash)(KeyType,int));  // 初始化哈希表
Status DestroyHash(CHashTable &H); // 销毁哈希表
Node* SearchHash(CHashTable H, KeyType key); // 查找
Status InsertHash(CHashTable &H, RcdType e); // 插入
Status deleteHash(CHashTable &H, KeyType key, RcdType &e); // 删除