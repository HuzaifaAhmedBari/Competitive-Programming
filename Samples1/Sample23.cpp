#include <stdio.h>
#include <time.h>

int main()
{
	char buffer[40];
    time_t currentTime;
    time(&currentTime);

    struct tm *localTime = localtime(&currentTime);

    printf("%02lld", localtime->tm_days);
    
    return 0;
}

