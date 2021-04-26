#ifndef UNTITLED1_LIBRARY_H
#define UNTITLED1_LIBRARY_H

//
// Created by eke_l on 2021/4/21.
//

#define succeed 1
#define failed 0
#define Status int

typedef int ElemType;
//for recursion
typedef struct Node{  // Node structure for recursion
    ElemType value;   // Node data
    struct Node *left, *right;
}Node, *NodePtr;

/**
 * Custom function
 */
/* Detect user input function */
Status InputCheck(ElemType *info);

/* MENU */
void Menu0();
/* Exit system */
void Quit();


/* for level reverse --- Queue*/
typedef struct SeqQueue
{
    NodeStackPtr back;
    NodeStackPtr front;
    int count;
}SeqQueue, *SeqQueuePtr;

Status init_queue(SeqQueuePtr Q);
Status push_queue(SeqQueuePtr Q, NodePtr T);
NodePtr pop_queue(SeqQueuePtr Q);

/* for no recursion --- Stack */
typedef struct NodeStack
{
    NodePtr	data;            // Node structure for no recursion
    struct NodeStack* next;
}NodeStack, *NodeStackPtr;

typedef struct SeqStack
{
    NodeStackPtr top;
    int	count;
}SeqStack, *SeqStackPtr;

Status init_stack(SeqStackPtr S);

/* Stack structure operation: push into the stack. */
Status push_stack(SeqStackPtr S, NodePtr T);
/* Stack structure operation: pop. */
NodePtr pop_stack(SeqStackPtr S);
NodePtr top_stack(SeqStackPtr S);
/* free */
Status free_stack0(NodeStackPtr node);
/* print */
Status print_stack0(NodeStackPtr node);


/* Tree preparation */
NodePtr FindElem_insert(NodePtr T, ElemType e);

/**
 * BST initialize
 * @param BinarySortTreePtr BST
 * @return is complete
 */
Status BST_init(NodePtr *T);
/**
 * BST insert
 * @param BinarySortTreePtr BST
 * @param ElemType value to insert
 * @return is successful
 */
Status BST_insert(NodePtr *T, ElemType e);

/**
 * BST delete
 * @param BinarySortTreePtr BST
 * @param ElemType the value for Node which will be deleted
 * @return is successful
 */
Status BST_delete0(NodePtr *T);
Status BST_delete1(NodePtr *T, ElemType e);

/**
 * BST search
 * @param BinarySortTreePtr BST
 * @param ElemType the value to search
 * @return is exist
 */
Status BST_search(NodePtr *T, ElemType e);

/**
 * BST preorder traversal without recursion
 * @param BinarySortTreePtr BST
 * @param (*visit) callback
 * @return is successful
 */
Status BST_preorderR(NodePtr T);

/**
 * BST preorder traversal with recursion
 * @param BinarySortTreePtr BST
 * @param (*visit) callback
 * @return is successful
 */
Status BST_preorderI(NodePtr T);

/**
 * BST inorder traversal without recursion
 * @param BinarySortTreePtr BST
 * @param (*visit) callback
 * @return is successful
 */
Status BST_inorderR(NodePtr T);

/**
 * BST inorder traversal with recursion
 * @param BinarySortTreePtr BST
 * @param (*visit) callback
 * @return is successful
 */
Status BST_inorderI(NodePtr T);

/**
 * BST preorder traversal without recursion
 * @param BinarySortTreePtr BST
 * @param (*visit) callback
 * @return is successful
 */
Status BST_postorderR(NodePtr T);

/**
 * BST postorder traversal with recursion
 * @param BinarySortTreePtr BST
 * @param (*visit) callback
 * @return is successful
 */
Status BST_postorderI(NodePtr T);

/**
 * BST level order traversal
 * @param BinarySortTreePtr BST
 * @param (*visit) callback
 * @return is successful
 */
Status BST_levelOrder(NodePtr T);

#endif //UNTITLED1_LIBRARY_H
