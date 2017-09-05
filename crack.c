#define _XOPEN_SOURCE
#include <unistd.h>
#include <stdio.h>
#include <ctype.h>
#include <cs50.h>
#include <string.h>

int main(int argc , string argv[])
{
    if(argc ==1)
    {
        printf("Usage: ./crack hash\n");
        return 1;
    }
    
    string hash = argv[1];
    char password[5];
    password[0] = 'A';
    password[1] = '\0';
    char salt[2];
    int count = 0;
    int count2 = 0;
    
    for(int s = 0 ; s<2 ; s++)
    {
        salt[s]=hash[s];
    }

    for(int l = 0 ; l < 4 ; l++)
    {
        for(int i = 0 ; password[i] != '\0'  ; i++)
        {
            for(int n = 0 ; n < 26 ; n++)
            {
                count++;
                password[i] = 65 + n;
                if (crypt(password,salt) == hash)
                {
                    printf("%s\n",password);
                    return 0;
                }
                for(int j = 0 ; password[j] != '\0'  ; j++)
                {
                    if(j != i)
                    {
                        for(int o = 0 ; o < 26 ; o++)
                        {
                            count++;
                            password[j] = 65 + o;
                            if (crypt(password,salt) == hash) 
                            {
                                printf("%s\n",password);
                                return 0;
                            }
                            for(int k = 0 ; password[k] != '\0'  ; k++)
                            {
                                if(k != i && k != j)
                                {
                                    for(int p = 0 ; p < 26 ; p++)
                                    {
                                        count++;
                                        password[k] = 65 + p;
                                        if (crypt(password,salt) == hash) 
                                        {
                                            printf("%s\n",password);
                                            return 0;
                                        }
                                        for(int m = 0 ; password[m] != '\0'  ; m++)
                                        {
                                            if(m != i && m != j && m != k)
                                            {
                                                for(int q = 0 ; q < 26 ; q++)
                                                {
                                                    count++;
                                                    password[m] = 65 + q;
                                                    if (crypt(password,salt) == hash) 
                                                    {
                                                        printf("%s\n",password);
                                                        return 0;
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        printf("%i permutations\n", count);
        count2++;
        if(count2 < 3)
        {
            password[l+1] = 'A';
        }
    }
    printf("\n");
    eprintf("Error 1: Did not find password: %i Permutations checked\n",count);
    return 1;
}
