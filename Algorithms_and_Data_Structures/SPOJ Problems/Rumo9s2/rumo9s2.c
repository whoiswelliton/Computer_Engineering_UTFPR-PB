#include <iostream>
#include <vector>

int degree9(int n)
{
    int r = 0;
    if (n == 9)
    {
        return 1;
    }
    if (n % 9 == 0)
    {
        while (n > 0)
        {
            r += n%10;
            n /= 10;
        }
        return 1 + degree9(r);
    }
    else
    {
        return 0;
    }

}

int main()
{
    string n;
    gets("%s",&n);

        for (int i = 0; i < n.size(); i++)

        int d9 = degree9(number);
        if (d9 == 0)
        {
            prinf("%d is not a multiple of 9.",n);
        }
        else
        {
            printf("%d is a multiple of 9 and %d has 9-degree ",n,d9);
        }

 return 0;
}
