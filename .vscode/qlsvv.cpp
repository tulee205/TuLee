#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int maso;
    char ten[50];
    float diemtoan;
    float diemly;
    float diemhoa;
} sinhvien;

void nhapsinhvien(sinhvien *sv) {
    printf("Nhap ma so sinh vien: ");
    scanf("%d", &sv->maso);
    printf("Nhap ten sinh vien: ");
    getchar();
    fgets(sv->ten, 50, stdin);
    sv->ten[strcspn(sv->ten, "\n")] = '\0';
    printf("Nhap diem Toan: ");
    scanf("%f", &sv->diemtoan);
    printf("Nhap diem Ly: ");
    scanf("%f", &sv->diemly);
    printf("Nhap diem Hoa: ");
    scanf("%f", &sv->diemhoa);
}

void hientsinhvien(sinhvien sv) {
    printf("\nMa so: %d\n", sv.maso);
    printf("Ten: %s\n", sv.ten);
    printf("Diem Toan: %.2f\n", sv.diemtoan);
    printf("Diem Ly: %.2f\n", sv.diemly);
    printf("Diem Hoa: %.2f\n", sv.diemhoa);
}

void themsinhvien(sinhvien *danhsach, int *soluong) {
    printf("\nThem sinh vien thu %d:\n", *soluong + 1);
    nhapsinhvien(&danhsach[*soluong]);
    (*soluong)++;
}

void hienthidanhsach(sinhvien *danhsach, int soluong) {
    for (int i = 0; i < soluong; i++) {
        printf("\n--- Sinh vien thu %d ---", i + 1);
        hientsinhvien(danhsach[i]);
    }
}

void timkiemsinhvien(sinhvien *danhsach, int soluong, int masocantim) {
    int timthay = 0;
    for (int i = 0; i < soluong; i++) {
        if (danhsach[i].maso == masocantim) {
            printf("\nSinh vien voi ma so %d duoc tim thay:\n", masocantim);
            hientsinhvien(danhsach[i]);
            timthay = 1;
            break;
        }
    }
    if (!timthay) {
        printf("\nKhong tim thay sinh vien voi ma so %d.\n", masocantim);
    }
}

int main() {
    sinhvien *danhsach;
    int soluong = 0;
    int luachon, masocantim;

    danhsach = (sinhvien *)malloc(100 * sizeof(sinhvien));

    luachon = 0;
    while (luachon != 0) {
        printf("\n===== MENU QUAN LY SINH VIEN =====\n");
        printf("1. Them sinh vien\n");
        printf("2. Hien thi danh sach sinh vien\n");
        printf("3. Tim kiem sinh vien theo ma so\n");
        printf("0. Thoat\n");
        printf("Lua chon: ");
        scanf("%d", &luachon);

        switch (luachon) {
            case 1:
                themsinhvien(danhsach, &soluong);
                break;
            case 2:
                hienthidanhsach(danhsach, soluong);
                break;
            case 3:
                printf("Nhap ma so sinh vien can tim: ");
                scanf("%d", &masocantim);
                timkiemsinhvien(danhsach, soluong, masocantim);
                break;
            case 0:
                printf("Thoat chuong trinh.\n");
                break;
            default:
                printf("Lua chon khong hop le!\n");
        }
    }

    free(danhsach);
    return 0;
}
