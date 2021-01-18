#include <stdio.h>

int check_diag(int *tab, int col, int val)
{
	int a;
        int i;

        i = 0;
        while (i < col)
        {
                a = col - i; 
                if (val == tab[i] + a || val == tab[i] - a)
                        return (0);
                i++;
        }
        return (1);
}

int check_col(int *tab, int col, int min, int n)
{
	int i;
	int j;

	i = 0;
	while (++i < n + 1)
	{
		j = -1;
		while (++j < col)
			if (tab[j] == i)
				break ;
		if (j == col && i > min)
			return (i);
	}
	return (-1);
}

int check(int *tab, int col, int min, int n)
{
	while (!check_diag(tab, col, check_col(tab, col, min, n)))
	{
		min = check_col(tab, col, min, n);
		if (min == -1)
			return (-1);
	}
	return (check_col(tab, col, min, n));
}

int nb_sol(int *tab, int col, int *r, int n)
{
        int l;

        l = check(tab, col, 0, n);
        while (l != -1)
        {
                tab[col] = l;
                if (col == n - 1)
                {
                    (*r)++;
                    return (0);
                }
                if (nb_sol(tab, col + 1, r, n))
                        return (1);
                else
                        l = check(tab, col, l, n);
        }
        return (0);
}


int ft_eight_queens_puzzle(int n)
{
        int tab[n];
        int i;
        int r;
        
        r = 0;
        i = -1;
        while (++i < n)
                tab[i] = 0;
        
        i = nb_sol(tab, 0, &r, n);
        return (r);
}

int     main()
{
        int num;
	printf("enter the n : ");
	scanf("%d", &num);
	printf("i = %d\n",ft_eight_queens_puzzle(num));
        return (0);
}
