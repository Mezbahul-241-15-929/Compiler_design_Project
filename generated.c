#include <stdio.h>
int main() {
    int age = 23;
    float cgpa = 3.34;
    char c = 'a';
    char *name = "Mezbahul Islam";
    printf("Hello world\n");
    printf("%c\n", c);
    printf("%d\n", age);
    printf("%f\n", cgpa);
    printf("%s\n", name);
    printf("%s%s%s%d%s%f", "My name is ",name,". I am ",age," years old.My Average CGPA: ",cgpa);
    return 0;
}
