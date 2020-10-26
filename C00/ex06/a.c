#	include <unistd.h>

void print_int(int num)
{
	char c1 ,c2;

	c1 = num / 10 + '0';
	c2 = num % 10 + '0';
	write(1, &c1, 1);
	write(1, &c2, 1);
	
}

void	asd(void)
{
	int a, b;
	a=0;
	b=0;
	
	while (a <= 98)
	{
		b = a + 1;
		while (b <= 99)
		{
			print_int(a);
			write(1, " ", 1);
			print_int(b);
			if (a < 98)
				write(1, ", ", 2);
			b++;
		}
		a++;
	}
}

int main()
{
	asd();
	return 0;
}
