#include<stdio.h>
#include<stdlib.h>

struct person {
    char name[100];
    int age;
};

void getPersonInfo(struct person p) {
    printf("%s\n", p.name);
    printf("%d\n", p.age);
}

void changeNameOfPerson(struct person *p, char newName[]) {
    strcpy(p->name, newName);
}

void main() {
    struct person p = {"Somebody Random", 45};
    getPersonInfo(p);
    char newName[100] = "Name changed";
    changeNameOfPerson(&p,newName);
    getPersonInfo(p);
}