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
    getchar(); // Xoa bo nho dem
    scanf("%[^\n]s",&sv->ten); 
    printf("Nhap diem Toan: ");
    scanf("%f", &sv->diemtoan);
    printf("Nhap diem Ly: ");
    scanf("%f", &sv->diemly);
    printf("Nhap diem Hoa: ");
    scanf("%f", &sv->diemhoa);
}

void hienthisinhvien(sinhvien sv) {
    printf("\nMa so: %d\n", sv.maso);
    printf("Ten: %s\n", sv.ten);
    printf("Diem Toan: %.2f\n", sv.diemtoan);
    printf("Diem Ly: %.2f\n", sv.diemly);
    printf("Diem Hoa: %.2f\n", sv.diemhoa);
}

void themsinhvien(sinhvien *danhsach, int *soluong) {
    printf("Them sinh vien thu %d\n", *soluong + 1);
    nhapsinhvien(&danhsach[*soluong]);
    (*soluong)++;
}

void hienthidanhsach(sinhvien *danhsach, int soluong) {
    for (int i = 0; i < soluong; i++) {
        printf("\nSinh vien thu %d\n", i + 1);
        hienthisinhvien(danhsach[i]);
    }
}

int main() {
    sinhvien *danhsach;
    int soluong = 0; // Khai bao va khoi tao bien soluong
    int luachon = 0;

    danhsach = (sinhvien*)malloc(sizeof(sinhvien) * 100);

    while (luachon != 0) {
        printf("\n==== Menu lua chon ====\n");
        printf("1. Them sinh vien\n");
        printf("2. Hien thi danh sach sinh vien\n");
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
            case 0:
                printf("Thoat chuong trinh\n");
                break;
            default:
                printf("Khong hop le\n");
        }
    }

    free(danhsach);
    return 0;
}
