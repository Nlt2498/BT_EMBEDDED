#include <stdio.h>

class Circle {
   private:
      double radius; // bán kính của hình tròn
      const double PI = 3.14159; // hằng số PI
   public:
      void setRadius(double r) {
         radius = r;
      }
      
      double getRadius() {
         return radius;
      }
      
      double getArea() {
         return PI * radius * radius;
      }
      
      double getCircumference() {
         return 2 * PI * radius;
      }
};

int main(int argc, char const *argv[])
{
    Circle htron;
    double ban_kinh;

    printf("Nhap ban kinh cua hinh tron: ");
    scanf("%lf",&ban_kinh);
    
    htron.setRadius(ban_kinh);
    printf("Ban kinh cua hinh tron la: %lf\n", htron.getRadius());
    printf("Dien tich cua hinh tron: %lf\n", htron.getArea());
    printf("Chu vi cua hinh tron: %lf\n", htron.getCircumference());

    return 0;
}

