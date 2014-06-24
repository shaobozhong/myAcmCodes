#include<stdio.h>
#include<time.h>

int num_prime = 0, prime[120000];
bool flag[120000];
/*
    得到1-100000之间的所有素数 
*/
void get_prime()
{
    int i, j;
    for(i = 3; i <= 100000; i += 2)
    {
        flag[i] = true;
    }
    prime[num_prime ++] = 2;
    int max;
    for(i = 3; i < 400; i +=2)
    {
        if(flag[i])
        {
            prime[num_prime ++] = i;
            max = 100000 / i;
            for(j = i; j <= max; j += 2)
            {
                flag[j * i] = false;
            }
        }
    }
    for(; i < 100000; i ++)
    {
        if(flag[i])
        {
            prime[num_prime ++] = i;
        }
    }
}


long long Euler(long long n)
{
    long long ans = 1;
    for(int i = 0; i < num_prime && prime[i] <= n; i ++)
    {
        if(n % prime[i] == 0)
        {
            ans *= (prime[i] - 1);
            n /= prime[i];
        }
        while(n % prime[i] == 0)
        {
            ans *= prime[i];
            n /= prime[i];
        }
    }
    if(n > 1)
    {
        ans *= (n - 1);
    }
    return ans;
}
int main()
{
    int test;
    scanf("%d", &test);
    get_prime();
    long long n;
    while(test --)
    {
        scanf("%lld", &n);
        printf("%lld\n", Euler(n));
    }
    return  0;
}
