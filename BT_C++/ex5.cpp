#include <stdio.h>
#include <string>

using namespace std;

class Person {
private:
    string name;
    int age;
    string address;
public:
    Person(string name, int age, string address);
    void printInfo();
    int getAge(int currentYear);
};

Person::Person(string name, int age, string address) {
    this->name = name;
    this->age = age;
    this->address = address;
}

void Person::printInfo() {
    printf("Name: %s\n", name.c_str());
    printf("Age: %d\n", age);
    printf("Address: %s\n", address.c_str());
}

int Person::getAge(int currentYear) {
    int birthYear = currentYear - age;
    return birthYear;
}

int main(int argc, char const *argv[])
{
    int currentYear;
    printf("Enter year currently: ");
    scanf("%d",&currentYear);

    Person person("Thanh", 22, " Thu Duc - Ho Chi Minh ");
    person.printInfo();

    printf("Birth year: %d \n", person.getAge(currentYear));

    return 0;
}
