#include <stdio.h>
#include <algorithm>
bool desc(int, int);
int main()
{
    int k;
    int s[13]={0,};
    int mask[13]={0,};
    while(1)
    {
        scanf("%d", &k);
        if(k == 0)
            return 0;
        for(int i=0; i<k; i++)
        {
            scanf("%d", &s[i]);
            if(i<6)
                mask[i] = 1;
            else    
                mask[i] = 0;
        }
        std::sort(mask, mask+k, desc);
        do{
            for(int i=0; i<k; i++)
            {
                if(mask[i])
                    printf("%d ", s[i]);
            }
            printf("\n");
        }while(std::prev_permutation(mask, mask+k));
        printf("\n");
    }
}
bool desc(int a, int b){
    return a > b;
}
