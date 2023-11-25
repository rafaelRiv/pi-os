unsigned char * uart = (unsigned char *)0x10000000; 

void putchar(char c) {
	*uart = c;
	return;
}
 
void print(const char * str) {
	while(*str != '\0') {
		putchar(*str);
		str++;
	}
	return;
}

void print_address_hex(void* p0) {
    int i;
    int p = (int)p0;

    putchar('0'); putchar('x');
    for(i = (sizeof(p) << 3) - 4; i>=0; i -= 4) {
      putchar(hex_digit((p >> i) & 0xf));
    }
}



