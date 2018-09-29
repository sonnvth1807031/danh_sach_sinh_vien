#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
    char ten[50],ma_sinh_vien[5],phone[10];
} Student;
Student profiles[1];
void luu_thong_tin_sv(int i, Student profiles[]) {
    int j;
    FILE *fp = fopen("danhsachsinhvien.txt", "w");
    fprintf(fp, "-%-20s|%-20s|%s", "Mã sinh viên", "Tên sinh viên", "Số điện thoại");
    for (j = 0; j < i; j++) {
        fprintf(fp, "\n-%-18s|%-18s|%s", profiles[j].ma_sinh_vien, profiles[j].ten, profiles[j].phone);
    }
    fclose(fp);
}
void doc_danh_sach() {
    FILE *f = fopen("danhsachsinhvien.txt", "r");
    int bufferSize = 225;
    char buffer[bufferSize];
    while (fgets(buffer, bufferSize, f) != NULL) {
        printf("%s", buffer);
    }
}
void main() {
    Student profiles[1];
    int lua_chon;
    printf("Vui long nhap lua chon trong danh sach menu \n"
           " Nhan phim 1: Them sinh vien \n "
           "Nhan phim 2: Hien thi danh sach sv \n "
           "Nhan phim 3: Luu danh sach sv ra file\n "
           "Nhan phim 4: Doc danh sach sv tu file\n "
           "Nhan phim 5: Thoat \n");
    printf("Ban muon su dung:");
    scanf("%d", &lua_chon);
    if (lua_chon == 1) {
        for (int i = 0; i < 1;i++) {
            printf("Vui long nhap ma sinh vien %d:",i+1);
            fgetc(stdin);
            fgets(profiles[i].ma_sinh_vien,10, stdin);
            if ((unsigned) strlen(profiles[i].ma_sinh_vien) != 5) {
            } else {
                printf("ma sinh vien sai, ma sinh vien phai co day du 5 ki tu\n");
                printf("Vui long nhap lai ma sinh vien %d:",i+1);
                fgetc(stdin);
                scanf("%s", profiles[i].ma_sinh_vien);
            }
            printf("Vui long nhap ten cua sinh vien %d:",i+1);
            fgetc(stdin);
            scanf("%s", profiles[i].ten);
            printf("Vui long nhap so dien thoai cua sinh vien %d:",i+1);
            fgetc(stdin);
            scanf("%s", profiles[i].phone);
        }
        printf("danh sach sv da day\n");
        printf("Vui long nhap lua chon tiep trong menu: \n"
               " 2: Hien thi danh sach sv \n"
               " 3: Luu danh sach sv ra file\n"
               " 4: Doc danh sach sv tu file\n "
               "5:Thoat :");
        scanf("%d", &lua_chon);
    }
    if (lua_chon == 2) {
        printf("-%-20s|%-20s|%s", "Mã sinh viên", "Tên sinh viên", "Số điện thoại");
        for (int j = 0; j < 1; j++) {
            printf("\n-%-18s|%-18s|%s", profiles[j].ma_sinh_vien, profiles[j].ten, profiles[j].phone);
        }
    }
    if (lua_chon == 3) {
        int i =0;
        printf("thong tin da duoc luu vao file (danhsachsinhvien.txt)\n");
        luu_thong_tin_sv(i,profiles);
    }
    if (lua_chon == 4) {
        printf("danh sach sinh vien trong file la:\n");
        doc_danh_sach();
    }
    if (lua_chon == 5) {
        printf("good bye! cam on da su dung dich vu cua chung toi!");
        exit("thoat");
    }
};
