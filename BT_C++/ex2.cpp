#include <stdio.h>
#include <math.h>

class HinhChuNhat 
{
    private:
       float chieudai;
       float chieurong;
    public:
        HinhChuNhat() {
           chieudai = 0;
           chieurong = 0;
        }

        HinhChuNhat(float cd, float cr) {
            chieudai = cd;
            chieurong = cr;
        }

    float tinhChuVi() {
        return 2 * (chieudai + chieurong);
    }

    float tinhDienTich() {
        return chieudai * chieurong;
    }

    float tinhDuongCheo() {
        return sqrt(pow(chieudai, 2) + pow(chieurong, 2));
    }

    bool kiemTraHinhVuong() {
        if (chieudai == chieurong) {
            return true;
        }
        else {
            return false;
        }
    }
};




int main(int argc, char const *argv[])
{
    HinhChuNhat hcn1(5, 7);

    printf("Chu vi hinh chu nhat: %f\n", hcn1.tinhChuVi());
    printf("Dien tich hinh chu nhat: %f\n", hcn1.tinhDienTich());
    printf("Duong cheo hinh chu nhat: %f\n", hcn1.tinhDuongCheo());

    if (hcn1.kiemTraHinhVuong()) {
        printf("Day la hinh vuong");
    }
    else {
        printf("Day khong phai la hinh vuong");
    }

    return 0;
}
