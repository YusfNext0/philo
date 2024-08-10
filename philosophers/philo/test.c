
#include <pthread.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

void *aff(void *i)
{
    printf("%d\n", (int)i);
    return NULL;
}

int main ()
{
    pthread_t th[4];
    int i = 0;
    while (i < 5)
    {
        if (pthread_create(&th[i], NULL, &aff, (void *)i))
        {
			printf("Error thread \n");
			return 1;
		}
        if (pthread_join(th[i], NULL))
        {
			printf("Error thread \n");
			return 1;
		}
        i++;
    }
}
