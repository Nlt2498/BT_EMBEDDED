#include <stdio.h>
#include <string>
#include <stdint.h>

using namespace std;

class Student{
    private:
       uint8_t id;
       string name;
       uint8_t age;
       typedef enum{
         MALE,     
         FEMALE
       }Sex;
       Sex sex;
       float math;
       float physics;
       float chemistry;
       float average;
       typedef enum{
         EXCELLENT,
         GOOD,
         AVERAGE,
         WEAK
       }Rank;
       Rank rank;
    public:
       Student(string name, uint8_t age, Sex sex, float math, float physics, float chemistry);
       void setName(string name);
       void setAge(uint8_t age);
       string getName();
       uint8_t getId();
       float getAverage();
       Rank getRank();0

};

int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}
