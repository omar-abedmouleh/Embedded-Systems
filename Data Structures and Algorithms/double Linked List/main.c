#include <stdio.h>
#include <stdlib.h>

typedef unsigned int uint32;
typedef unsigned short uint16;
typedef unsigned char uint8;

#define DELETE_NODE_AT_BEGINNING

struct Node {
  uint32 NodeData;
  struct Node *LeftNodeLink;
  struct Node *RightNodeLink;
};

struct Node *DLL_1 = NULL;

void Insert_Node_At_Beginning(struct Node **List, uint32 Data);
void Insert_Node_At_End(struct Node *List, uint32 Data);
void Insert_Node_After(struct Node *List, uint32 Data, uint32 position);
void Insert_Node_Before(struct Node **List, uint32 Data, uint32 position);
void Delete_Node_At_Beginning(struct Node **List);
void Delete_Node_At_End(struct Node *List);
void Delete_Node_At_Intermediate(struct Node *List, uint32 position);
void Display_All_Nodes_Forward(struct Node *List);
void Display_All_Nodes_Reverse(struct Node *List);

int main() {
  Insert_Node_At_Beginning(&DLL_1, 11);
  Display_All_Nodes_Reverse(DLL_1);
  Insert_Node_At_Beginning(&DLL_1, 22);
  Display_All_Nodes_Reverse(DLL_1);
  Insert_Node_At_Beginning(&DLL_1, 33);
  Display_All_Nodes_Reverse(DLL_1);
  printf("----------------------\n");
  Insert_Node_At_End(DLL_1, 99);
  Display_All_Nodes_Reverse(DLL_1);
  Insert_Node_At_End(DLL_1, 100);
  Display_All_Nodes_Reverse(DLL_1);
  printf("----------------------\n");

  Insert_Node_After(DLL_1, 44, 2);
  Display_All_Nodes_Reverse(DLL_1);
  Insert_Node_After(DLL_1, 55, 3);
  Display_All_Nodes_Reverse(DLL_1);
  Insert_Node_After(DLL_1, 66, 5);
  Display_All_Nodes_Reverse(DLL_1);
  printf("----------------------\n");
  Insert_Node_Before(&DLL_1, 77, 3);
  Display_All_Nodes_Reverse(DLL_1);
  Insert_Node_Before(&DLL_1, 88, 1);
  Display_All_Nodes_Reverse(DLL_1);
  printf("----------------------\n");
  Delete_Node_At_Beginning(&DLL_1);
  Display_All_Nodes_Reverse(DLL_1);
  Delete_Node_At_Beginning(&DLL_1);
  Display_All_Nodes_Reverse(DLL_1);
  printf("----------------------\n");
  Delete_Node_At_End(DLL_1);
  Display_All_Nodes_Reverse(DLL_1);
  Delete_Node_At_End(DLL_1);
  Display_All_Nodes_Reverse(DLL_1);
  printf("----------------------\n");
  Delete_Node_At_Intermediate(DLL_1, 2);
  Display_All_Nodes_Reverse(DLL_1);
  Delete_Node_At_Intermediate(DLL_1, 3);
  Display_All_Nodes_Reverse(DLL_1);

  return 0;
}

void Insert_Node_At_Beginning(struct Node **List, uint32 Data)
{
    struct Node *intermediate = NULL;

    intermediate = (struct Node *)malloc(sizeof(struct Node));

    if (intermediate != NULL)
    {
        intermediate->NodeData = Data;

        if (*List == NULL)
        {
            intermediate->LeftNodeLink = NULL;
            intermediate->RightNodeLink = NULL;
            *List = intermediate;
        }
        else
        {
            intermediate->RightNodeLink = *List;
            intermediate->LeftNodeLink = NULL;
            (*List)->LeftNodeLink = intermediate;
            *List = intermediate;
        }
    }
    else
    {
        printf("Error Null pointer\n");
    }
}
void Insert_Node_At_End(struct Node *List, uint32 Data)
{
    struct Node *intermediate = NULL;
    struct Node *intermediate_1 = List;

    if (List == NULL)
    {
        printf("List is empty!\n");
        return;
    }

    intermediate = (struct Node *)malloc(sizeof(struct Node));

    if (intermediate != NULL)
    {
        intermediate->NodeData = Data;
        intermediate->RightNodeLink = NULL;

        while (intermediate_1->RightNodeLink != NULL)
        {
            intermediate_1 = intermediate_1->RightNodeLink;
        }

        intermediate_1->RightNodeLink = intermediate;
        intermediate->LeftNodeLink = intermediate_1;
    }
    else
    {
        printf("Error Null pointer\n");
    }
}
void Insert_Node_After(struct Node *List, uint32 Data, uint32 position) {
  struct Node *intermediate_left = List;
  struct Node *intermediate_right = NULL;
  struct Node *new_node = NULL;

  new_node = (struct Node *)malloc(sizeof(struct Node));

  if (new_node != NULL) {
    new_node->NodeData = Data;

    while (position > 1) {
      position--;
      intermediate_left = intermediate_left->RightNodeLink;
    }

    if (intermediate_left->RightNodeLink == NULL) {
      intermediate_left->RightNodeLink = new_node;
      new_node->LeftNodeLink = intermediate_left;
      new_node->RightNodeLink = NULL;
    } else {
      intermediate_right = intermediate_left->RightNodeLink;

      new_node->LeftNodeLink = intermediate_left;
      new_node->RightNodeLink = intermediate_right;

      intermediate_left->RightNodeLink = new_node;
      intermediate_right->LeftNodeLink = new_node;
    }
  } else {
    printf("Error Null pointer\n");
  }
}

void Insert_Node_Before(struct Node **List, uint32 Data, uint32 position) {
  struct Node *intermediate_right = NULL;
  struct Node *intermediate_left = NULL;
  struct Node *new_node = NULL;

  if (List == NULL) {
    printf("Invalid list pointer!\n");
    return;
  }

  if (position == 0) {
    printf("Invalid position!\n");
    return;
  }

  new_node = (struct Node *)malloc(sizeof(struct Node));

  if (new_node == NULL) {
    printf("Error Null pointer\n");
    return;
  }

  new_node->NodeData = Data;

  if (position == 1) {
    new_node->RightNodeLink = *List;
    new_node->LeftNodeLink = NULL;

    if (*List != NULL) {
      (*List)->LeftNodeLink = new_node;
    }

    *List = new_node;
  } else {
    intermediate_right = *List;

    while (position > 1 && intermediate_right != NULL) {
      position--;
      intermediate_right = intermediate_right->RightNodeLink;
    }

    if (intermediate_right == NULL) {
      printf("Position out of range!\n");
      free(new_node);
      return;
    }

    intermediate_left = intermediate_right->LeftNodeLink;

    intermediate_left->RightNodeLink = new_node;
    intermediate_right->LeftNodeLink = new_node;

    new_node->LeftNodeLink = intermediate_left;
    new_node->RightNodeLink = intermediate_right;
  }
}
void Delete_Node_At_Beginning(struct Node **List){
    struct Node *TempNode = *List; /* Points to the node that we need to delete */

#ifdef DELETE_NODE_AT_BEGINNING
    /* Update the head node */
    *List = (*List)->RightNodeLink;
    (*List)->LeftNodeLink = NULL;
    /* Free the first node */
    free(TempNode);
    TempNode = NULL;
#else
    *List = (*List)->RightNodeLink;
    free((*List)->LeftNodeLink);
    (*List)->LeftNodeLink = NULL;
#endif
}

void Delete_Node_At_End(struct Node *List){
    struct Node *NodeListCounterOne = NULL;
    struct Node *NodeListCounterTwo = NULL;

    NodeListCounterOne = List;
    while(NodeListCounterOne->RightNodeLink != NULL){
        NodeListCounterOne = NodeListCounterOne->RightNodeLink;
    }
    NodeListCounterTwo = NodeListCounterOne->LeftNodeLink;
    NodeListCounterTwo->RightNodeLink = NULL;
    free(NodeListCounterOne);
    NodeListCounterOne = NULL;
}

void Delete_Node_At_Intermediate(struct Node *List, uint32 position){
    struct Node *NodeListCounterOne = NULL;
    struct Node *NodeListCounterTwo = NULL;
    uint32 NodePosition = position;

    if(1 == NodePosition){
        printf("Please use the Delete_Node_At_Beginning !! \n");
    }
    else{
        NodeListCounterOne = List;
        while(NodePosition > 1){
            NodeListCounterOne = NodeListCounterOne->RightNodeLink;
            NodePosition--;
        }

        NodeListCounterTwo = NodeListCounterOne->LeftNodeLink;
        NodeListCounterTwo->RightNodeLink = NodeListCounterOne->RightNodeLink;
        NodeListCounterOne->RightNodeLink->LeftNodeLink = NodeListCounterTwo;
        free(NodeListCounterOne);
        NodeListCounterOne = NULL;
    }
}

void Display_All_Nodes_Forward(struct Node *List){
    struct Node *TempNode = List;

    printf("\nTraversal in forward direction ==> ");
    printf("Data : ");
    printf("%d -> ", TempNode->NodeData);
    while(TempNode->RightNodeLink != NULL){
        TempNode = TempNode->RightNodeLink;
        printf("%d -> ", TempNode->NodeData);
    }
    if(NULL == TempNode->RightNodeLink){
        printf("NULL");
    }
    printf("\n");
}

void Display_All_Nodes_Reverse(struct Node *List){
    struct Node *TempNode = List;

    printf("\nTraversal in reverse direction ==> ");
    printf("Data : ");
    while(TempNode->RightNodeLink != NULL){
        TempNode = TempNode->RightNodeLink;
    }
    while(TempNode != NULL){
        printf("%d -> ", TempNode->NodeData);
        TempNode = TempNode->LeftNodeLink;
    }
    if(NULL == TempNode){
        printf("NULL");
    }
    printf("\n");
}








