
#include <string.h>
#include <stdio.h>

typedef struct Planets
{
    char name[20];
    long distance;
    int moons;

} Planets;
void input(Planets planet[], int size)
{

    for (int i = 0; i < size; i++)
    {
        getchar();
        printf("Enter the name of the planet\n");
        fgets(planet[i].name, sizeof(planet[i].name), stdin);
        planet[i].name[strcspn(planet[i].name, "\n")] = '\0';
        printf("Enter the distance\n");
        scanf("%ld", &planet[i].distance);
        printf("Enter the  no of moons\n");
        scanf("%d", &planet[i].moons);
    }
}
void display(Planets planet[], int size)
{
    printf("Display\n");
    for (int i = 0; i < size; i++)
    {
        printf("Planet:%d\n", i + 1);
        printf("Name:%s\n", planet[i].name);
        printf("Distance:%ld\n", planet[i].distance);
        printf("Moons:%d\n", planet[i].moons);
    }
}
int main()
{
    int n;
    printf("Enter size of the solar system: ");
    scanf("%d", &n);
    Planets planet[n];
    input(planet, n);
    display(planet, n);
}
