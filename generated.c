#include <stdio.h>
#include <string.h>
int main() {
    int age = 0;
    float height = 0.0;
    char name[100];
    printf("Enter your age: ");
    scanf("%d", &age);
    while (getchar() != '\n');
    printf("Enter your height: ");
    scanf("%f", &height);
    while (getchar() != '\n');
    printf("Enter your name: ");
    scanf("%99[^\n]", name);
    while (getchar() != '\n');
    printf("%s%d%s", "Age: ",age,"\n");
    printf("%s%f%s", "Height: ",height,"\n");
    printf("%s%s%s", "Name: ",name,"\n");
    return 0;
    return 0;
}
