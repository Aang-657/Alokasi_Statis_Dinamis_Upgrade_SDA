// list.c (Implementation File)
#include "list.h"

void initList(Node *list) {
    list = NULL;
}

Node* createNode(char *data) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    strcpy(newNode->data, data);
    newNode->next = NULL;
    return newNode;
}

void insertLast(Node **list, Node *newNode) {
    if (*list == NULL) {
        *list = newNode;
        return;
    }
    Node *temp = *list;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

void printList(Node *list) {
    Node *temp = list;
    while (temp) {
        printf("- %s\n", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

void deleteAll(Node *list) {
    Node *temp = list;
    while (temp) {
        Node *toDelete = temp;
        temp = temp->next;
        free(toDelete);
    }
    list = NULL;
}

void deleteAfterValue(Node *list, char *target) {
    Node *temp = list, *prev = NULL;
    while (temp && strcmp(temp->data, target) != 0) {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Nama tidak ada.\n");
        return;
    }
    if (prev == NULL){
        list = temp->next;
    } else {
        prev->next = temp->next;
    }
    free(temp);
}
/*
mohon maaf pak saya membuat code yang lain menjadi komentar karena sebelumnya
ketika saya compile ada error, berupa konflik pada type data
di mana fungsi yang tidak di pakai harus diganti juga parameternya menjadi type data char
maaf bila tidak sesuai dengan yang diinginkan, karena lebih cepat megubah fungsi yang tidak dipakai
menjadi comentar ketimbang harus mengubah semua fungsi yang ada.
*/
/*
void insertAwal(LinkedList *list, Node *newNode) {
    newNode->next = list->head;
    list->head = newNode;
}

void insertAfterValue(LinkedList *list, int target, Node *newNode) {
    Node *temp = list->head;
    while (temp && temp->data != target) {
        temp = temp->next;
    }
    if (temp) {
        newNode->next = temp->next;
        temp->next = newNode;
    }
}

void insertBeforeValue(LinkedList *list, int target, Node *newNode) {
    if (list->head && list->head->data == target) {
        insertAwal(list, newNode);
        return;
    }
    Node *temp = list->head;
    while (temp->next && temp->next->data != target) {
        temp = temp->next;
    }
    if (temp->next) {
        newNode->next = temp->next;
        temp->next = newNode;
    }
}

void insertBetween(LinkedList *list, Node *newNode) {
    int count = 0;
    Node *temp = list->head;
    while (temp) {
        count++;
        temp = temp->next;
    }
    if (count % 2 == 0) {
        int mid = count / 2;
        temp = list->head;
        for (int i = 1; i < mid; i++) {
            temp = temp->next;
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }
}

void insertAfterBetween(LinkedList *list, Node *newNode) {
    int count = 0;
    Node *temp = list->head;
    while (temp) {
        count++;
        temp = temp->next;
    }
    if (count % 2 != 0) {
        int mid = count / 2;
        temp = list->head;
        for (int i = 0; i < mid; i++) {
            temp = temp->next;
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }
}

void insertBeforeBetween(LinkedList *list, Node *newNode) {
    int count = 0;
    Node *temp = list->head;
    
    // Hitung jumlah elemen dalam linked list
    while (temp) {
        count++;
        temp = temp->next;
    }

    // Pastikan jumlah elemen ganjil
    if (count % 2 != 0) {
        int mid = count / 2;

        // Jika mid == 0, berarti hanya ada 1 elemen, jadi masukkan di awal
        if (mid == 0) {
            insertAwal(list, newNode);
            return;
        }

        // Cari node sebelum node tengah
        temp = list->head;
        for (int i = 0; i < mid - 1; i++) {
            temp = temp->next;
        }

        // Sisipkan newNode sebelum node tengah
        newNode->next = temp->next;
        temp->next = newNode;
    }
}


void deleteAwal(LinkedList *list) {
    if (list->head) {
        Node *temp = list->head;
        list->head = list->head->next;
        free(temp);
    }
}

void deleteLast(LinkedList *list) {
    if (!list->head) return;
    if (!list->head->next) {
        free(list->head);
        list->head = NULL;
        return;
    }
    Node *temp = list->head;
    while (temp->next->next) {
        temp = temp->next;
    }
    free(temp->next);
    temp->next = NULL;
}

void deleteBetween(LinkedList *list) {
    int count = 0;
    Node *temp = list->head;
    while (temp) {
        count++;
        temp = temp->next;
    }
    if (count % 2 == 0) {
        int mid = count / 2;
        temp = list->head;
        for (int i = 1; i < mid - 1; i++) {
            temp = temp->next;
        }
        Node *toDelete = temp->next;
        temp->next = toDelete->next;
        free(toDelete);
    }
}

void deleteAfterBetween(LinkedList *list) {
    int count = 0;
    Node *temp = list->head;
    while (temp) {
        count++;
        temp = temp->next;
    }
    if (count % 2 != 0) {
        int mid = count / 2;
        temp = list->head;
        for (int i = 0; i < mid; i++) {
            temp = temp->next;
        }
        Node *toDelete = temp->next;
        if (toDelete) {
            temp->next = toDelete->next;
            free(toDelete);
        }
    }
}

void deleteBeforeBetween(LinkedList *list) {
    int count = 0;
    Node *temp = list->head;
    while (temp) {
        count++;
        temp = temp->next;
    }
    if (count % 2 != 0) {
        int mid = count / 2 - 1;
        if (mid == 0) {
            deleteAwal(list);
            return;
        }
        temp = list->head;
        for (int i = 1; i < mid - 1; i++) {
            temp = temp->next;
        }
        Node *toDelete = temp->next;
        temp->next = toDelete->next;
        free(toDelete);
    }
}

void deleteAfterValue(LinkedList *list, int target) {
    Node *temp = list->head;
    while (temp && temp->data != target) {
        temp = temp->next;
    }
    if (temp && temp->next) {
        Node *toDelete = temp->next;
        temp->next = toDelete->next;
        free(toDelete);
    }
}

void deleteBeforeValue(LinkedList *list, int target) {
    if (!list->head || !list->head->next) return;
    if (list->head->next->data == target) {
        deleteAwal(list);
        return;
    }
    Node *prev = NULL, *temp = list->head;
    while (temp->next && temp->next->next && temp->next->next->data != target) {
        temp = temp->next;
    }
    if (temp->next && temp->next->next) {
        Node *toDelete = temp->next;
        temp->next = toDelete->next;
        free(toDelete);
    }
}

void modifyFirst(LinkedList *list, int newData) {
    if (list->head) {
        list->head->data = newData;
    }
}

void modifyLast(LinkedList *list, int newData) {
    if (!list->head) return;
    Node *temp = list->head;
    while (temp->next) {
        temp = temp->next;
    }
    temp->data = newData;
}

void modifyBetween(LinkedList *list, int newData) {
    int count = 0;
    Node *temp = list->head;
    while (temp) {
        count++;
        temp = temp->next;
    }
    if (count % 2 == 0) {
        int mid = count / 2;
        temp = list->head;
        for (int i = 1; i < mid; i++) {
            temp = temp->next;
        }
        if (temp) temp->data = newData;
    }
}

void modifyAfterBetween(LinkedList *list, int newData) {
    int count = 0;
    Node *temp = list->head;
    while (temp) {
        count++;
        temp = temp->next;
    }
    if (count % 2 != 0) {
        int mid = count / 2;
        temp = list->head;
        for (int i = 0; i < mid; i++) {
            temp = temp->next;
        }
        if (temp->next) {
            temp->next->data = newData;
        }
    }
}

void modifyBeforeBetween(LinkedList *list, int newData) {
    int count = 0;
    Node *temp = list->head;
    while (temp) {
        count++;
        temp = temp->next;
    }
    if (count % 2 != 0) {
        int mid = count / 2;
        if (mid == 0) {
            modifyFirst(list, newData);
            return;
        }
        temp = list->head;
        for (int i = 1; i < mid; i++) {
            temp = temp->next;
        }
        if (temp->next) {
            temp->data = newData;
        }
    }
}

void modifyAfterValue(LinkedList *list, int target, int newData) {
    Node *temp = list->head;
    while (temp && temp->data != target) {
        temp = temp->next;
    }
    if (temp && temp->next) {
        temp->next->data = newData;
    }
}

void modifyBeforeValue(LinkedList *list, int target, int newData) {
    if (!list->head || !list->head->next) return;
    if (list->head->data == target) return;
    Node *prev = NULL, *temp = list->head;
    while (temp->next && temp->next->data != target) {
        temp = temp->next;
    }
    if (temp->next) {
        temp->data = newData;
    }
}
*/