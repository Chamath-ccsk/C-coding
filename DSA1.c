 #include <stdio.h>
#include <stdlib.h>


struct Node {
    int data;           // the value stored in this node
    struct Node *next;  // pointer/address of the NEXT node (NULL if last)
};

struct LinkedList {
   
    struct Node *head;
};


struct LinkedList createList() {
    struct LinkedList list;
    list.head = NULL;   // NULL head = "this list currently has 0 nodes"
    return list;
} 



struct Node* createNode(int value) {
  .
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));

    newNode->data = value;  // store the value the caller wants
    newNode->next = NULL;   // by default this node points to nothing —
                             // the caller decides where it connects
    return newNode;          // give the address back to the caller
}


void traverse(struct LinkedList *list) {
   

    if (temp == NULL) {
        printf("List is empty\n");
        return;   // nothing to print, exit early
    }

    printf("List: ");
    while (temp != NULL) {          // stop when we fall off the end
        printf("%d -> ", temp->data);  // visit (print) current node's data
        temp = temp->next;             // step forward to the next node
    }
    printf("NULL\n");   // shows the list terminates, just like the slides
}



int search(struct LinkedList *list, int key) {
    struct Node *temp = list->head;
    int position = 1;   // we count positions starting at 1, not 0 

    while (temp != NULL) {
        if (temp->data == key) {
            return position;   // match found — stop and report where
        }
        temp = temp->next;   // not a match, move to next node
        position++;          // and increase the position counter
    }

    return -1;   // loop finished without finding key -> not present
}


void insertFront(struct LinkedList *list, int value) {
    struct Node *newNode = createNode(value);
    newNode->next = list->head;   // new node now points to old first node
    list->head = newNode;         // head now points to the new node
    printf("Element inserted at front\n");
}


void insertRear(struct LinkedList *list, int value) {
    struct Node *newNode = createNode(value);

    // Special case: list is currently empty, so the new node
    // becomes both the first AND last node.
    if (list->head == NULL) {
        list->head = newNode;
        printf("Element inserted at rear\n");
        return;
    }

    // Walk until temp is sitting ON the last node
    // (we stop BEFORE temp becomes NULL, so temp->next is still valid to check)
    struct Node *temp = list->head;
    while (temp->next != NULL) {
        temp = temp->next;
    }

    // temp is now the last node -> attach the new node after it
    temp->next = newNode;
    printf("Element inserted at rear\n");
}



void insertMiddle(struct LinkedList *list, int value, int position) {
    if (position <= 1) {
        printf("Invalid position. Use insertFront().\n");
        return;
    }

    struct Node *temp = list->head;
    int i = 1;
    while (temp != NULL && i < position - 1) {
        temp = temp->next;
        i++;
    }

    // If temp became NULL, the requested position doesn't exist
    // (the list is shorter than the position asked for).
    if (temp == NULL) {
        printf("Position out of bounds\n");
        return;
    }

    struct Node *newNode = createNode(value);

    // Rewire: new node takes over "temp's old next"...
    newNode->next = temp->next;
    temp->next = newNode;

    printf("Element inserted at position %d\n", position);
}


void deleteFront(struct LinkedList *list) {
    if (list->head == NULL) {
        printf("List is empty\n");
        return;   // nothing to delete
    }

    struct Node *temp = list->head;   // remember the node we're deleting,
    list->head = list->head->next;    // head now skips over it -> points
    free(temp);                       // release the old first node's memory
    printf("Element deleted successfully\n");
}



void deleteRear(struct LinkedList *list) {
    if (list->head == NULL) {
        printf("List is empty\n"); 
        return;
    }

 
    if (list->head->next == NULL) {
        free(list->head);
        list->head = NULL;   // list is now empty
        printf("Element deleted successfully\n");
        return;
    }

    struct Node *temp = list->head;

    while (temp->next->next != NULL) {
        temp = temp->next;
    }

    free(temp->next);   // free the actual last node
    temp->next = NULL;  // temp is now the new last node, so it must

    printf("Element deleted successfully\n");
}



void deleteMiddle(struct LinkedList  *list, int position) {
    if (list->head == NULL) {
        printf("List is empty\n");
        return;
    }

    if (position == 1) {
        printf("Invalid position. Use deleteFront().\n");
        return;
    }

    struct Node *prev = list->head;       // starts at position 1
    struct Node *current = list->head->next; // starts at position 2
    int i = 2;   // 'current' is already sitting at position 2

    // Advance BOTH pointers together, one step behind the other,
    // until 'current' reaches the target position.
    while (current != NULL && i < position) {
        prev = current;
        current = current->next;
        i++;
    }

    // current became NULL -> we walked off the end -> position doesn't exist
    if (current == NULL) {
        printf("Invalid position\n");
        return;
    }

 
    if (current->next == NULL) {
        printf("Invalid position. Use deleteRear().\n");
        return;
    }

    // Bypass 'current': prev now links directly to whatever came after it
    prev->next = current->next;
    free(current);   // safe to free now — nothing points to it anymore
    printf("Element deleted successfully\n");
}

struct Node* findNode(struct LinkedList *list, int value) {
    struct Node *current = list->head;

    while (current != NULL) {
        if (current->data == value) {
            return current;   // hand back the node's address itself
        }
        current = current->next;
    }

    return NULL;   // walked the whole list, value never matched
}

void updateFront(struct LinkedList *list, int newVal) {
    if (list->head == NULL) { 
        printf("List is empty\n");
        return;
    }

    list->head->data = newVal;   // overwrite the value stored in the node
    printf("Element updated successfully\n");
}



void updateRear(struct LinkedList *list, int newVal) {
    if (list->head == NULL) {
        printf("List is empty\n");
        return;
    }

    struct Node *temp = list->head;
    while (temp->next != NULL) {   // walk until temp IS the last node
        temp = temp->next;
    }
    temp->data = newVal;
    printf("Element updated successfully\n");
}



void updateMiddle(struct LinkedList *list, int position, int newVal) {
    struct Node *temp = list->head;
    int i = 1;

    // Walk exactly to the target position (no need to stop one early,
    // since we're not rewiring pointers this time)
    while (temp != NULL && i < position) {
        temp = temp->next;
        i++;
    }

    if (temp == NULL) {
        printf("Position out of bounds\n");
        return;
    }

    temp->data = newVal;
    printf("Element updated successfully\n");
}



void update(struct LinkedList *list, int oldVal, int newVal) {
    struct Node *node = findNode (list, oldVal);   // reuse our helper

    if (node != NULL) {
        node->data = newVal;
        printf("Element updated successfully\n");
    } else {
        printf("Element not found\n");
    }
}


// Count number of nodes -> O(n), classic "counter + traverse" pattern
int length(struct LinkedList *list) {
    int count = 0;
    struct Node *temp = list->head;

    while (temp != NULL) {
        count++;          // one more node visited
        temp = temp->next; // move forward
    }
 
    return count;
}

int getAt(struct LinkedList *list, int position) {
    struct Node *temp = list->head;
    int i = 1;

    while (temp != NULL && i < position) {
        temp = temp->next;
        i++;
    }

    if (temp == NULL) {
        printf("Position out of bounds\n");
        return -1;   // sentinel value indicating failure
    }

    return temp->data;
}

void freeList(struct LinkedList *list) {
    struct Node *temp = list->head;
    struct Node *next;

    while (temp != NULL) {

        next = temp->next;
        free(temp);
        temp = next;   // now safely move on to the saved next node
    }

    list->head = NULL;   // list is now empty and safe to reuse
}


int main() {
    // Step 1: create the list itself (an empty container, head = NULL)
    struct LinkedList list = createList();

    // Step 2: start adding nodes to it
    insertFront(&list, 10);      // 10
    insertRear(&list, 30);       // 10 -> 30
    insertMiddle(&list, 20, 2);  // 10 -> 20 -> 30   (inserted between them)
    traverse(&list);

    int pos = search(&list, 20);
    if (pos != -1)
        printf("Element found at position %d\n", pos);
    else
        printf("Element not found in the list\n");

    updateMiddle(&list, 2, 25);  // 10 -> 25 -> 30
    traverse(&list);

    update(&list, 30, 99);       // 10 -> 25 -> 99
    traverse(&list);

    deleteMiddle(&list, 2);      // 10 -> 99
    traverse(&list);

    deleteFront(&list);          // 99
     traverse(&list);

    deleteRear(&list);           // (empty)
    traverse(&list);

    freeList(&list);

    return 0;
}
