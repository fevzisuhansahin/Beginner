// CHAT GPT YAZDI BİRAZ DÜZELTTİM

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SERVICE_COUNT (sizeof(AVAILABLE_SERVICES) / sizeof(AVAILABLE_SERVICES[0]))

typedef struct service {
    char* name;
} Service;

typedef struct member {
    char* name;
    int age;
    Service services[2];
    int serviceCount;
    struct member* next;
} Member;

const char* AVAILABLE_SERVICES[] = {
    "Yuzme",
    "Gym",
    "Tenis",
    "Yoga&Pilates",
    "Beslenme&Diyet"
};

Member* head = NULL;

Member* createMember(const char* name, int age, int* selectedServices, int serviceCount) {
    Member* newMember = (Member*)malloc(sizeof(Member));

    newMember->name = (char*)malloc((strlen(name)+1)*sizeof(char));
    strcpy(newMember->name, name);
    newMember->age = age;
    newMember->serviceCount = serviceCount;

    for (int i = 0; i < serviceCount; i++) {
        const char *serviceName = AVAILABLE_SERVICES[selectedServices[i] - 1];
        newMember->services[i].name = (char*)malloc((strlen(serviceName)+1)*sizeof(char));
        strcpy(newMember->services[i].name, serviceName);
    }

    newMember->next = NULL;
    return newMember;
}

void addMember() {
    char tempName[100];
    int age, serviceCount = 0, selected[2];

    printf("Uye ismini girin: ");
    scanf(" %[^\n]", tempName);
    printf("Yasini girin: ");
    scanf("%d", &age);

    printf("Hizmetler:\n");
    for (int i = 0; i < SERVICE_COUNT; i++) {
        printf("%d: %s\n", i + 1, AVAILABLE_SERVICES[i]);
    }

    int k=1;
    while (k) {
        printf("Kac hizmet secmek istiyorsunuz? (1 veya 2): ");
        scanf("%d", &serviceCount);
        if (serviceCount == 1 || serviceCount == 2){
            for (int i = 0; i < serviceCount; i++) {
                printf("%d. hizmet numarasini girin: ", i + 1);
                scanf("%d", &selected[i]);
                if (selected[i] < 1 || selected[i] > SERVICE_COUNT) {
                    printf("Gecersiz hizmet numarasi!\n");
                    return;
                }
            }
            k=0;
        }
        else
            printf("En fazla 2 hizmet secebilirsiniz!\n");
    }

    Member* newMember = createMember(tempName, age, selected, serviceCount);
    newMember->next = head;
    head = newMember;

    printf("Uye basariyla eklendi.\n");
}

void searchMember() {
    char name[100];
    printf("Aranacak uyenin ismini girin: ");
    scanf(" %[^\n]", name);

    Member* temp = head;
    while (temp != NULL) {
        if (strcmp(temp->name, name) == 0) {
            printf("Uye bulundu:\n");
            printf("Ad: %s, Yas: %d\n", temp->name, temp->age);
            printf("Aldigi hizmetler:\n");
            for (int i = 0; i < temp->serviceCount; i++) {
                printf("- %s\n", temp->services[i].name);
            }
            return;
        }
        temp = temp->next;
    }
    printf("Uye bulunamadi.\n");
}

void deleteMember() {
    char name[100];
    printf("Silinecek uyenin ismini girin: ");
    scanf(" %[^\n]", name);

    Member* temp = head;
    Member* prev = NULL;

    while (temp) {
        if (strcmp(temp->name, name) == 0) {
            if (prev == NULL) {
                head = temp->next;
            } else {
                prev->next = temp->next;
            }

            free(temp->name);
            for (int i = 0; i < temp->serviceCount; i++) {
                free(temp->services[i].name);
            }
            free(temp);

            printf("Uye silindi.\n");
            return;
        }
        prev = temp;
        temp = temp->next;
    }
    printf("Uye bulunamadi.\n");
}

void listMembers() {
    if (!head) {
        printf("Hic uye yok.\n");
        return;
    }

    Member* temp = head;
    printf("Tum uyeler:\n");
    while (temp) {
        printf("Ad: %s, Yas: %d\n", temp->name, temp->age);
        printf("Hizmetler:\n");
        for (int i = 0; i < temp->serviceCount; i++) {
            printf("- %s\n", temp->services[i].name);
        }
        printf("-----------------------\n");
        temp = temp->next;
    }
}

void freeAllMembers() {
    Member* temp = head;
    while (temp) {
        Member* toFree = temp;
        temp = temp->next;
        free(toFree->name);
        for (int i = 0; i < toFree->serviceCount; i++) {
            free(toFree->services[i].name);
        }
        free(toFree);
    }
}

void menu() {
    int choice;
    do {
        printf("\n=== SPOR MERKEZI UYE YONETIMI ===\n");
        printf("1. Uye Ekle\n");
        printf("2. Uye Ara\n");
        printf("3. Uye Sil\n");
        printf("4. Tum Uyeleri Listele\n");
        printf("5. Cikis\n");
        printf("Seciminiz: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: 
                addMember(); 
                break;
            case 2: 
                searchMember(); 
                break;
            case 3: 
                deleteMember(); 
                break;
            case 4: 
                listMembers(); 
                break;
            case 5:
                freeAllMembers();
                printf("Programdan cikiliyor, bellek temizlendi.\n");
                break;
            default:
                printf("Gecersiz secim!\n");
        }
    } while (choice != 5);
}

int main() {
    menu();
    return 0;
}
