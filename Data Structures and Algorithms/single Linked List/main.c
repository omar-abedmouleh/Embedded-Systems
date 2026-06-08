#include <stdio.h>
#include <stdlib.h>

typedef unsigned int uint32;
typedef signed int sint32;
typedef unsigned char uint8;
typedef unsigned short uint16;

typedef struct node {
  uint32 node_data;
  struct node *node_link;
} node_t;

void insert_node_at_beginning(node_t **list);
void insert_node_at_end(node_t **list);
void insert_node_after(node_t *list);
void delete_node_at_beginning(node_t **list);
void delete_node(node_t *list);
void display_list(node_t *list);
uint32 Get_Length(node_t *list);

node_t *list = NULL;

int main() {
  printf("hello to single linked List \n");

  uint32 choice;

  while (1) {
    printf("\n");
    printf("================================\n");
    printf("-> 1) insert_node_at_beginning\n");
    printf("-> 2) insert_node_at_end\n");
    printf("-> 3) insert_node_after\n");
    printf("-> 4) delete_node_at_beginning\n");
    printf("-> 5) delete_node\n");
    printf("-> 6) display_list\n");
    printf("-> 7) Get_Length\n");
    printf("-> 8) exit Single Linked List\n");
    printf("================================\n");
    printf("enter choice\n");

    scanf("%u", &choice);

    switch (choice) {
      case 1:
        insert_node_at_beginning(&list);
        break;

      case 2:
        insert_node_at_end(&list);
        break;

      case 3:
        insert_node_after(list);
        break;

      case 4:
        delete_node_at_beginning(&list);
        break;

      case 5:
        delete_node(list);
        break;

      case 6:
        display_list(list);
        break;

      case 7:
        printf("Length = %u\n", Get_Length(list));
        break;

      case 8:
        printf("Bye Single Linked List\n");
        exit(0);
        break;

      default:
        printf("User Choice out of range !!\n");
        break;
    }
  }

  return 0;
}

void insert_node_at_beginning(node_t **list) {
  node_t *new_node = NULL;
  uint32 value = 0;

  new_node = (node_t *)malloc(sizeof(node_t));

  if (new_node == NULL) {
    printf("Memory allocation failed!\n");
    return;
  }

  printf("enter the value of the node you want to add at the Beginning\n");
  scanf("%u", &value);

  new_node->node_data = value;
  new_node->node_link = *list;
  *list = new_node;
}

void insert_node_at_end(node_t **list) {
  node_t *new_node = NULL;
  node_t *intermediate_node = *list;
  uint32 value = 0;

  new_node = (node_t *)malloc(sizeof(node_t));

  if (new_node == NULL) {
    printf("Memory allocation failed!\n");
    return;
  }

  printf("enter the value of the node you want to add at the End \n");
  scanf("%u", &value);

  new_node->node_data = value;
  new_node->node_link = NULL;

  if (*list == NULL) {
    *list = new_node;
  } else {
    while (intermediate_node->node_link != NULL) {
      intermediate_node = intermediate_node->node_link;
    }

    intermediate_node->node_link = new_node;
  }
}

void insert_node_after(node_t *list) {
  node_t *new_node = NULL;
  node_t *intermediate = list;

  uint32 data = 0;
  uint16 position = 0;
  uint16 counter = 1;

  if (list == NULL) {
    printf("List is empty!\n");
    return;
  }

  new_node = (node_t *)malloc(sizeof(node_t));

  if (new_node == NULL) {
    printf("Memory allocation failed!\n");
    return;
  }

  printf("enter the Data of the new Node: ");
  scanf("%u", &data);

  printf(
      "enter the position of the new Node, the new node will be added after "
      "the given Position:\n");
  scanf("%hu", &position);

  if (position == 0) {
    printf("Invalid position!\n");
    free(new_node);
    return;
  }

  while ((counter < position) && (intermediate != NULL)) {
    counter++;
    intermediate = intermediate->node_link;
  }

  if (intermediate == NULL) {
    printf("Position out of range!\n");
    free(new_node);
    return;
  }

  new_node->node_data = data;
  new_node->node_link = intermediate->node_link;
  intermediate->node_link = new_node;
}

void delete_node_at_beginning(node_t **list) {
  node_t *intermediate = NULL;

  if (*list != NULL) {
    intermediate = *list;
    *list = intermediate->node_link;
    intermediate->node_link = NULL;
    free(intermediate);
  } else {
    printf("List is already empty!\n");
  }
}

void delete_node(node_t *list) {
  node_t *intermediat = list;
  node_t *intermediat_1 = NULL;

  uint16 counter = 1;
  uint16 position = 0;

  if (list == NULL) {
    printf("List is already empty!\n");
    return;
  }

  printf("enter the position of the Node to delete \n");
  scanf("%hu", &position);

  if (position <= 1) {
    printf("Use delete_node_at_beginning for position 1.\n");
    return;
  }

  while ((counter < position - 1) && (intermediat != NULL)) {
    counter++;
    intermediat = intermediat->node_link;
  }

  if ((intermediat == NULL) || (intermediat->node_link == NULL)) {
    printf("Position out of range!\n");
    return;
  }

  intermediat_1 = intermediat->node_link;
  intermediat->node_link = intermediat_1->node_link;
  intermediat_1->node_link = NULL;
  free(intermediat_1);
}

void display_list(node_t *list) {
  node_t *intermediate = list;

  if (list == NULL) {
    printf("Empty list!\n");
  } else {
    while (intermediate != NULL) {
      printf("%u -> ", intermediate->node_data);
      intermediate = intermediate->node_link;
    }

    printf("NULL\n");
  }
}

uint32 Get_Length(node_t *list) {
  node_t *intermediate = list;
  uint32 counter = 0;

  while (intermediate != NULL) {
    counter++;
    intermediate = intermediate->node_link;
  }

  return counter;
}