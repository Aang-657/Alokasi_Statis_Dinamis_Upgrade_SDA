#ifndef LOGIC_H
#define LOGIC_H
#include "list.h"

typedef struct kota {
    char namaKota[20];
    Node *daftarNama;
    struct kota *next;
} kota;

kota* createkota(char *namaKota);
void entryData(kota **head);
void deleteKota(kota **head);
void deleteNamaDariKota(kota *head);
void tampilkanData(kota *head);

#endif