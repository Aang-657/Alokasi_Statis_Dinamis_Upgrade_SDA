// File: main.c
#include "logic.h"

int main() {
    int pilihan;
    bool isRunning = true;
    kota *head = NULL;

    while (isRunning) {
        printf("\nMenu:\n");
        printf("1. Entry data kota dan nama\n");
        printf("2. Delete kota\n");
        printf("3. Delete nama dari kota tertentu\n");
        printf("4. Tampilkan semua data\n");
        printf("5. Keluar\n");
        printf("Pilihan: ");
        scanf("%d", &pilihan);

        switch (pilihan) {
            case 1:
                entryData(&head);
                break;
            case 2:
                deleteKota(&head);
                break;
            case 3:
                deleteNamaDariKota(head);
                break;
            case 4:
                tampilkanData(head);
                break;
            case 5:
                isRunning = false;
                printf("Program selesai.\n");
                break;
            default:
                printf("Pilihan tidak valid.\n");
        }
    }
    return 0;
}
