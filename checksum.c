#include <stdio.h>


int main()
{
	int i;

	unsigned short int byte_grp, checksum;
	unsigned char header[20] = { 0x45, 0x00, 0x00, 0x30, 0x0f, 0x41, 0x40, 0x00, 0x80, 0x06, 0x00, 0x00, 0x91, 0xfe, 0xa0, 0xed, 0x41, 0xd0, 0xe4, 0xdf };
	unsigned int sum = 0;
	for (i = 0; i < 10; i++)
	{
		byte_grp = (header[2 * i] << 8) + header[2 * i + 1];
		sum += byte_grp;
	}

	while (sum > 0xFFFF)	sum = (sum - ((sum >> 16) << 16)) + (sum >> 16);

	checksum = ~sum;

	printf("%04x", checksum);
	getchar();
}