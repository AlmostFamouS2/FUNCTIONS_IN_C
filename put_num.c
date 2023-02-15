#include <unistd.h>

void put_num(unsigned long long int num)
{
	char arr[21] = {0}, v=0;
	int count = 1;

	while (num){
		v = (num)%10;
		num /= 10;

		arr[21-count] = v+0x30;
		count++;
	}

	write(1, &arr[21-count], count);
}

int main(void)
{
	put_num(12345692939495);
	return 0;
}
