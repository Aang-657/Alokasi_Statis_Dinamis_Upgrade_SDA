#include "logic.h"

kota* createkota(char *namaKota) {
    kota *newKota = (kota*)malloc(sizeof(kota));
    strcpy(newKota->namaKota, namaKota);
    newKota->daftarNama = NULL;
    newKota->next = NULL;
    return newKota;
}

void entryData(kota **head) {
    char namaKota[20], nama[20];
    printf("Masukkan nama kota: ");
    scanf("%s", namaKota);

    kota *newKota = createkota(namaKota);
    newKota->next = *head;
    *head = newKota;

    int jumlah;
    printf("Masukkan jumlah nama yang ingin ditambahkan: ");
    scanf("%d", &jumlah);
    for (int i = 0; i < jumlah; i++) {
        printf("Masukkan nama ke-%d: ", i + 1);
        scanf("%s", nama);
        Node *newNode = createNode(nama);
        insertLast(&newKota->daftarNama, newNode);
    }
}

void deleteKota(kota **head) {
    char targetKota[20];
    printf("Masukkan nama kota yang ingin dihapus: ");
    scanf("%s", targetKota);

    kota *temp = *head, *prev = NULL;
    while (temp != NULL && strcmp(temp->namaKota, targetKota) != 0) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Kota tidak ditemukan.\n");
        return;
    }

    if (prev == NULL) {
        *head = temp->next;
    } else {
        prev->next = temp->next;
    }
    
    free(temp);
    printf("Kota %s telah dihapus.\n", targetKota);
}

void tampilkanData(kota *head) {    
    while (head != NULL) {
        printf("Kota: %s\n", head->namaKota);
        printf("Daftar Nama:\n");
        printList(head->daftarNama);
        head = head->next;
    }
}


void deleteNamaDariKota(kota *head) {
    char targetKota[20], targetNama[20];
    printf("Masukkan nama kota: ");
    scanf("%s", targetKota);
    printf("Masukkan nama yang ingin dihapus: ");
    scanf("%s", targetNama);

    kota *temp = head;
    while (temp != NULL && strcmp(temp->namaKota, targetKota) != 0) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Kota tidak ditemukan.\n");
        return;
    }
    if (temp->daftarNama == NULL) {
        printf("Tidak ada nama yang terdaftar di kota %s.\n", targetKota);
        return;
    }

    deleteAfterValue(temp->daftarNama, targetNama);
    if (temp->daftarNama == NULL) {
        printf("Semua nama di kota %s telah dihapus.\n", targetKota);
    } else {
        printf("Nama %s telah dihapus dari kota %s.\n", targetNama, targetKota);
    }
}