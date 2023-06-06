/*
* File: ex1.cpp
* Author: Nguyen Thanh
* Date: 31/4/2023
* Description: This is file for calculate distance and area of triangle in 2D Space
*/

#include <stdio.h>
#include <stdint.h>
#include <cmath>

/***********************************Class Point**************************************/
class Diem{
    private:
        int8_t toaDoX;
        int8_t toaDoY;
    public:
        Diem(int8_t _toaDoX = 0, int8_t _toaDoY = 0);
        int8_t getToaDoX();
        int8_t getToaDoY();
};

Diem::Diem(int8_t _toaDoX, int8_t _toaDoY){
    Diem::toaDoX = _toaDoX;
    Diem::toaDoY = _toaDoY;
}

int8_t Diem::getToaDoX(){
    return Diem::toaDoX;
}

int8_t Diem::getToaDoY(){
    return Diem::toaDoY;
}

class PhepToanOXY{
    private:
        Diem diemA;
        Diem diemB;
        Diem diemC;
        typedef enum{
            KHOANG_CACH,
            DIEN_TICH
        }PhepToan;
        PhepToan checkPhepToan;
    public:
        PhepToanOXY(Diem diemA, Diem diemB);
        PhepToanOXY(Diem diemA, Diem diemB, Diem diemC);
        double khoangCach2Diem();
        double dienTichTamGiac();
};

PhepToanOXY::PhepToanOXY(Diem diemA, Diem diemB){
    PhepToanOXY::diemA = diemA;
    PhepToanOXY::diemB = diemB;
    PhepToanOXY::checkPhepToan = KHOANG_CACH;
}

PhepToanOXY::PhepToanOXY(Diem diemA, Diem diemB, Diem diemC){
    PhepToanOXY::diemA = diemA;
    PhepToanOXY::diemB = diemB;
    PhepToanOXY::diemC = diemC;
    PhepToanOXY::checkPhepToan = DIEN_TICH;
}

double PhepToanOXY::khoangCach2Diem(){
    double x1;
    double x2;
    double khoangcach;
    if(PhepToanOXY::checkPhepToan == KHOANG_CACH){
        x1 = diemA.getToaDoX() - diemB.getToaDoX(); 
        x2 = diemA.getToaDoY() - diemB.getToaDoY();
        khoangcach = sqrt(x1*x1 + x2*x2);
        return khoangcach;
    }
    else{
        printf("Khong phai chuong trinh checkPhepToan!");
    }
}


double PhepToanOXY::dienTichTamGiac(){
    double khoangcachAB;
    double khoangcachAC;
    double khoangcachBC;
    double chuvi;
    double dientich;
    if (PhepToanOXY::checkPhepToan == DIEN_TICH){
        khoangcachAB = sqrt(((diemA.getToaDoX() - diemB.getToaDoX()) * (diemA.getToaDoX() - diemB.getToaDoX())) + ((diemA.getToaDoY() - diemB.getToaDoY()) * (diemA.getToaDoY() - diemB.getToaDoY())));
        khoangcachBC = sqrt(((diemB.getToaDoX() - diemC.getToaDoX()) * (diemB.getToaDoX() - diemC.getToaDoX())) + ((diemB.getToaDoY() - diemC.getToaDoY()) * (diemB.getToaDoY() - diemC.getToaDoY())));
        khoangcachAC = sqrt(((diemA.getToaDoX() - diemC.getToaDoX()) * (diemA.getToaDoX() - diemC.getToaDoX())) + ((diemA.getToaDoY() - diemC.getToaDoY()) * (diemA.getToaDoY() - diemC.getToaDoY())));
        chuvi = (khoangcachAB + khoangcachAC + khoangcachBC) / 2;
        dientich = sqrt(chuvi * (chuvi - khoangcachAB) * (chuvi - khoangcachBC) * (chuvi - khoangcachAC));
        return dientich; 
    }
    else{
        printf("Khong phai chuong trinh checkPhepToan!");
    }  
}

int main(int argc, char const *argv[])
{
    Diem diemA = {1, 2};
    Diem diemB = {3, 4};
    Diem diemC = {5, 6};

    PhepToanOXY tinh1(diemA, diemB);
    PhepToanOXY tinh2(diemA, diemB, diemC);

    printf("Khoang cach giua 2 diem A va B = %f\n", tinh1.khoangCach2Diem());
    printf("Dien tich tam giac = %f\n", tinh2.dienTichTamGiac());
    
    return 0;
}
