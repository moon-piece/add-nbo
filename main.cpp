#include <stddef.h> // for size_t
#include <stdint.h> // for uint32_t
#include <stdio.h> // for printf
#include <netinet/in.h> // ntohl

int main(int argc, char **argv) {
	uint32_t n1;
	uint32_t n2;
	if (argc != 3) {
		printf("command error\nPlease input : ./add-nbo <file> <file2>"); //1
		return -1;
	} else {
		FILE* fp1 = fopen(argv[1], "rb");
		FILE* fp2 = fopen(argv[2], "rb");
		if (fp1 == NULL || fp2 == NULL) {
			printf("file open error"); //2
		} else {
			fread(&n1, sizeof(n1), 1, fp1);
			fread(&n2, sizeof(n2), 1, fp2);
			if (ftell(fp1) < 4 || ftell(fp2) < 4) {
				printf("file size error"); //3
				return -1;
			} else {
				int r1 = ntohl(n1);
				int r2 = ntohl(n2);
				printf("%d(0x%x) + %d(0x%x) = %d(0x%x)", r1, r1, r2, r2, r1 + r2, r1 + r2);
			}
		}
		fclose(fp1);
		fclose(fp2);
	}
}

