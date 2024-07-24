#include <stdio.h>
#include <stdint.h>


uint32_t iwantforhex(FILE *fp) {
    uint32_t value = 0;
    unsigned char buffer[4];
    fread(buffer,1, sizeof(buffer), fp); 
    value = (buffer[0] << 24) | (buffer[1] << 16) | (buffer[2] << 8) | buffer[3];
    return value;
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Please input_detail: %s <file1> <file2>\n", argv[0]);
        return -1;
    }

    FILE *fp1 = fopen(argv[1], "rb");
    FILE *fp2 = fopen(argv[2], "rb");

    if (fp1 == NULL || fp2 == NULL) {
        printf("Null Error");
        return -1;
    }

    

    uint32_t num1 = iwantforhex(fp1);
    uint32_t num2 = iwantforhex(fp2);

    fclose(fp1);
    fclose(fp2);

    uint32_t sum = num1 + num2;

    printf("%u(0x%x) + %u(0x%x) = %u(0x%x)\n", num1, num1, num2, num2, sum, sum);

    return 0;
}

