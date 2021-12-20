#include <stdio.h>
struct Distance
{
    float km;
    float m;
} dist1, dist2, dif;

int main()
{
    printf("1st distance\n");
    printf("Enter km: ");
    scanf("%f", &dist1.km);

    printf("Enter m: ");
    scanf("%f", &dist1.m);
    printf("2nd distance\n");

    printf("Enter km: ");
    scanf("%f", &dist2.km);

    printf("Enter m: ");
    scanf("%f", &dist2.m);

    float d1 = dist1.km + dist1.m/1000;
    float d2 = dist2.km + dist2.m/1000;

    

    printf("Diff of distances = %.3f KM", d1-d2);
    return 0;
}