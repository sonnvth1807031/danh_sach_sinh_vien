#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct {
    char ma_sinh_vien[10];
    char ten_sinh_vien[50];
    char so_dien_thoai[50];
} danhsachsinhvien;

void themsinhvien(int i, danhsachsinhvien sv[]) {
    printf("Vui lòng nhập mã sinh viên:");
    while (1 == 1) {
        fgetc(stdin);
        scanf("%s",sv[i].ma_sinh_vien);
        if (strlen(sv[i].ma_sinh_vien) != 5) {
            printf("Vui lòng nhập đủ 5 kí tự!\nVui lòng nhập lại:");
        } else break;
    }
    fgetc(stdin);
    printf("Vui lòng nhập tên sinh viên: ");
    scanf("%[^\n]", sv[i].ten_sinh_vien);
    fgetc(stdin);
    printf("Vui lòng nhập số điện thoại sinh viên: ");
    scanf("%s", sv[i].so_dien_thoai);
    fgetc(stdin);
}
void indanhsachsinhvien(int dssv, danhsachsinhvien sv[]) {
    int j;
    printf("-%-20s|%-20s|%s", "Mã sinh viên", "Tên sinh viên", "Số điện thoại");
    for (j = 0; j < dssv; j++) {
        printf("\n-%-18s|%-18s|%s", sv[j].ma_sinh_vien, sv[j].ten_sinh_vien, sv[j].so_dien_thoai);
    }
}

void luudanhsachsinhvien(int luu, danhsachsinhvien sv[]) {
    int j;
    FILE *fp = fopen("danhsachsinhvien.txt", "w");
    fprintf(fp, "-%-20s|%-20s|%s", "Mã sinh viên", "Tên sinh viên", "Số điện thoại");
    for (j = 0; j < luu; j++) {
        fprintf(fp, "\n-%-18s|%-18s|%s", sv[j].ma_sinh_vien, sv[j].ten_sinh_vien, sv[j].so_dien_thoai);
    }
    fclose(fp);
}
void menu() {
    printf("Vui lòng chọn từ menu bên dưới:\n");
    printf("Phím 1.Thêm 1 sinh viên. \n");
    printf("Phím 2.Hiển thị danh sách sinh viên. \n");
    printf("Phím 3.Lưu danh sách sinh viên ra file. \n");
    printf("Phím 4. Đọc danh sách sinh viên từ file.\n");
    printf("Phím 5.Thoát chương trình. \n");
}
void menu2(){
     printf("Phím 2.Hiển thị danh sách sinh viên. \n");
     printf("Phím 3.Lưu danh sách sinh viên ra file. \n");
     printf("Phím 4. Đọc danh sách sinh viên từ file.\n");
     printf("Phím 5.Thoát chương trình. \n");

}

void docdssv() {
    FILE *f = fopen("danhsachsinhvien.txt", "r");
    int bufferSize = 225;
    char buffer[bufferSize];
    while (fgets(buffer, bufferSize, f) != NULL) {
        printf("%s", buffer);
    }
}
int main() {
    int choice;
    int i=0;
    int max_sv = 10;
    danhsachsinhvien sv[10];
    menu();
    do {
        printf("\nVui lòng nhập lựa chọn của bạn: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                themsinhvien(i, sv);
                i++;
                if (i == max_sv ) {
                     printf("\nVui lòng nhập lựa chọn của bạn: ");
                     scanf("%d", &choice);

                     switch (choice) {
                         case 1:
                             printf("danh sach da day");
                             menu2();
                             break;
                     }
                     if(choice == 5){
                         printf("Thoát");
                         break;
                     }
                }
                break;
            case 2:
                printf("Danh sách sinh viên:\n");
                indanhsachsinhvien (i, sv);
                break;
            case 3:
                printf("Lưa vào file (danhsachsinhvien.txt) thành công!\n ");
                luudanhsachsinhvien(i, sv);
                break;
            case 4:
                printf("Danh sách sinh viên lấy từ file (danhsachsinhvien.txt): \n");
                docdssv();
                break;
            case 5:
                printf("Thoát!");
                exit("exit");

        }
    }
    while (max_sv = 10);


}