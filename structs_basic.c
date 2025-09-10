
#include <string.h>
#include <stdio.h>

typedef struct Planets
{
    char name[20];
    long distance;
    int moons;

} Planets;

int main()
{
    Planets earth = {"earth", 1234567890, 3};
    Planets venus = {"earth", 1234567890, 3};
    printf("Planet name:%s\n Distance:%ld\n Moons:%d", earth.name, earth.distance, earth.moons);
}
