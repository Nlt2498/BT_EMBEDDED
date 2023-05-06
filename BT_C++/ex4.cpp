#include <stdio.h>
#include <string>

using namespace std;

class Animal {
   private:
      string name; // tên động vật
      int age; // tuổi của động vật
      double weight; // trọng lượng của động vật
      double bmi; // chỉ số BMI của động vật

   public:
      Animal(string n, int a, double w) {
         name = n;
         age = a;
         weight = w;
      }

      double getBMI() {
         bmi = weight / ((double)age * (double)age);
         return bmi;
      }

      int compareAge(Animal a) {
         if (age < a.age) {
            return -1;
         }
         else if (age > a.age) {
            return 1;
         }
         else {
            return 0;
         }
      }

      int compareWeight(Animal a) {
         if (weight < a.weight) {
            return -1;
         }
         else if (weight > a.weight) {
            return 1;
         }
         else {
            return 0;
         }
      }

      string getName() {
         return name;
      }
};


int main(int argc, char const *argv[])
{
   Animal cat("Meo", 3, 5.5);
   Animal dog("Cho", 2, 8.2);
   Animal rabbit("Tho", 1, 2.3);

   printf("Chi so BMI cua %s la: %lf\n", cat.getName().c_str(), cat.getBMI());
   printf("Chi so BMI cua %s la: %lf\n", dog.getName().c_str(), dog.getBMI());
   printf("Chi so BMI cua %s la: %lf\n", rabbit.getName().c_str(), rabbit.getBMI());
   printf("------------------------------------------\n");
   printf("So sanh tuoi giua %s va %s : %d\n",cat.getName().c_str(), dog.getName().c_str(),cat.compareAge(dog));
   printf("So sanh tuoi giua %s va %s : %d\n",dog.getName().c_str(), rabbit.getName().c_str(),dog.compareAge(rabbit));
   printf("------------------------------------------\n");
   printf("So sanh trong luong giua %s va %s : %d\n",cat.getName().c_str(), dog.getName().c_str(),cat.compareWeight(dog));
   printf("So sanh trong luong giua %s va %s : %d\n",dog.getName().c_str(), rabbit.getName().c_str(),dog.compareWeight(rabbit));
   return 0;
}
