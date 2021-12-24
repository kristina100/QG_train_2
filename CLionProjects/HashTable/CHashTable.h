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
	  int size;// ��ϣ������
      int count; // ��ǰ���к��еļ�¼����
      int (*hash)(KeyType key, int);  // ����ָ�����������ѡȡ�Ĺ�ϣ����
} CHashTable; 

Status InitHash(CHashTable &H, int size, int (*hash)(KeyType,int));  // ��ʼ����ϣ��
Status DestroyHash(CHashTable &H); // ���ٹ�ϣ��
Node* SearchHash(CHashTable H, KeyType key); // ����
Status InsertHash(CHashTable &H, RcdType e); // ����
Status deleteHash(CHashTable &H, KeyType key, RcdType &e); // ɾ��