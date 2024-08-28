#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct node {
    int data;
    struct node *next;
} node;
void in(node *head) {
    while(head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}
int size(node *head) {
    int dem = 0;
    while(head != NULL) {
        ++dem;
        head = head->next;
    }
    return dem;
}
void themvaodau(node **head, int data) {
    node *newnode = (node*)malloc(sizeof(node));
    newnode->data = data;
    newnode->next = *head;
    *head = newnode;
}
void themvaogiua(node **head, int k, int data) {
    int n = size(*head);
    if(k < 1 || k > n + 1) {
        printf("Vi tri chen khong hop le\n");
        return;
    }
    if(k == 1) {
        themvaodau(head, data);
    } else {
        node *tmp = *head;
        for (int i = 1; i <= k - 2; i++) {
            tmp = tmp->next;
        }
        node *newnode = (node*)malloc(sizeof(node));
        newnode->data = data;
        newnode->next = tmp->next;
        tmp->next = newnode;
    }
}
void themvaocuoi(node **head, int data) {
    node *newnode = (node*)malloc(sizeof(node));
    newnode->data = data;
    newnode->next = NULL;
    if(*head == NULL) {
        *head = newnode;
        return;
    }
    node *tmp = *head;
    while(tmp->next != NULL) {
        tmp = tmp->next;
    }
    tmp->next = newnode;
}
void xoadau(node **head) {
    if(*head == NULL) return;
    node *tmp = *head;
    *head = (*head)->next;
    free(tmp);
}
void xoagiua(node **head,int k) {
    if(k < 1 || k > size(*head)) return;
    if (k == 1) {
        xoadau(head);
    } else {
        node *tmp = *head;
        for (int i = 1; i <= k - 2; i++) {
            tmp = tmp->next;
        }
        //luu node thu k lai
        node *knode = tmp->next;
        //cho node thu k-1 tro toi node thu k+1
        tmp->next = knode->next;
        //giai phong node thu k
        free(knode);
    }
}
void xoacuoi(node **head) {
    if(*head == NULL) return;
    if((*head)->next == NULL) {
        free(*head);
        *head = NULL;
        return;
    }
    node *tmp = *head;
    while(tmp->next->next != NULL) {
        tmp = tmp->next;
    }
    free(tmp->next);
    tmp->next = NULL;
}
int main() {
    node *head = NULL;
    int luachon, data, n, k;
    printf("Nhap so luong phan tu trong danh sach: ");
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        printf("Nhap gia tri phan tu thu %d: ", i + 1);
        scanf("%d", &data);
        themvaocuoi(&head, data);
    }
    printf("Danh sach ban dau: ");
    in(head);
    while(1) {
        printf("\n1. Them phan tu vao dau danh sach.\n");
        printf("2. Them phan tu vao cuoi danh sach.\n");
        printf("3. Xoa phan tu dau.\n");
        printf("4. Xoa phan tu cuoi.\n");
        printf("5. Them phan tu vao giua.\n");
        printf("6. Xoa phan tu giua.\n");
        printf("7. In danh sach.\n");
        printf("0. Thoat chuong trinh.\n");
        printf("Nhap lua chon: ");
        scanf("%d", &luachon);
        switch(luachon) {
            case 1:
                printf("Nhap phan tu can them: ");
                scanf("%d", &data);
                themvaodau(&head, data);
                break;
            case 2:
                printf("Nhap phan tu can them vao cuoi: ");
                scanf("%d", &data);
                themvaocuoi(&head, data);
                break;
            case 3:
                xoadau(&head);
                break;
            case 4:
                xoacuoi(&head);
                break;
            case 5:
                printf("Nhap vi tri can them vao: ");
                scanf("%d", &k);
                printf("Nhap gia tri phan tu can them: ");
                scanf("%d", &data);
                themvaogiua(&head, k, data);
                break;
            case 6:
                printf("Nhap vi tri can xoa: ");
                scanf("%d", &k);
                xoagiua(&head, k);
                break;
            case 7:
                printf("Danh sach hien tai: ");
                in(head);
                break;
            case 0:
                printf("Thoat chuong trinh\n");
                return 0;
            default:
                printf("Lua chon khong hop le, vui long nhap lai.\n");
        }
    }
}
