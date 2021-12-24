//
// Created by HUAWEI on 2021/10/13.
//

#include "CHashTable.h"

Status InitHash(CHashTable &H, int size, int (*hash)(KeyType,int))
{   //��ʼ����ϣ��
    int i;
    H.rcd = (Node**)malloc(sizeof(Node *)*size);
    if(nullptr==H.rcd)
        return OVERFLOW;
    for(i=0; i<size; i++)
        H.rcd[i] = nullptr;
    H.size = size;
    H.hash = hash;
    H.count = 0;
    return OK;
}

Node* SearchHash(CHashTable H, KeyType key)
{
    int p = H.hash(key, H.size);
    Node* np;
    for(np = H.rcd[p]; np!=nullptr; np = np->next)
        if(np->r.key==key)
            return np;
    return nullptr;
}

Status InsertHash(CHashTable &H, RcdType e)
{
    //�����¼e
    int p;
    Node *np;
    if((np = SearchHash(H, e.key))==nullptr)
    { // ���Ҳ��ɹ�ʱ���뵽��ͷ
        p = H.hash(e.key, H.size);
        np = (Node*)malloc(sizeof(Node));
        if(np==nullptr)
            return OVERFLOW;
        np->r = e;
        np->next = H.rcd[p];
        H.rcd[p] = np;
        H.count++;
        return OK;
    }
    else
        return ERROR;
}

Status deleteHash(CHashTable &H, KeyType key, RcdType &e)
{

    //ɾ��������ͬ����ͷ�ڵ������ɾ������
    int p;
    Node *np;
    Node *temp;
    if((np = SearchHash(H,key)) == nullptr)
    {
        printf("Search Error!");
        return ERROR;
    }
    //���������ڵĻ�����ɾ����¼
    if ((np = SearchHash(H,key))!=nullptr)
    {
        p = H.hash(key,H.size);
        np = H.rcd[p];
    }
    if(np->r.key == key)
    {
        temp = np;
        H.rcd[p] = temp->next;
        e = temp->r;
        free(temp);
        H.count--;
        return OK;
    }
    else
    {
        for(;np!=nullptr;np++)
        {
            if(np->next->r.key == key)
            {

            }
        }
    }

    //�ҵ�Ҫɾ��Ԫ�ص��±�
    for (int i = 0;i < H.size;i++)
    {
        np = SearchHash(H,i);
        if(np->r.key == key) {
            e.key = i;//�����±�
            break;
        }
    }
}











