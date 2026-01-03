#include<stdio.h>
#include<math.h>
int main()
{
    double i,j,t;
    scanf("%lf %lf %lf", &t, &i, &j);
    double ans = pow(i,2) - (4)*(t)*(j);
    if(ans<0)
    {
        printf("%d", 0);
        return 0;
    }
    if(t==0)
    {
        printf("%d", -1);
        return 0;
    }
    printf("%d\n", 2);
    double ans1= (-i+(sqrt(ans))) / (2*t);
    double ans2=  (-i-(sqrt(ans))) / (2*t);
    if(ans1>ans2)
    {
        printf("%.10lf\n", ans2);
        printf("%.10lf\n", ans1);
    }
    else
    {
        printf("%.10lf\n", ans1);
        if(ans==-0)
            printf("%.10lf\n", abs(ans2));
        else
            printf("%.10lf\n", ans2);
    }
}