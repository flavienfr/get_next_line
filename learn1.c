#include <stdio.h>


int		main()
{
   	char ch = 'A';
   	char str[20] = "abcdef";
   	int no = 150;
   	int hex = 0X96;
   	unsigned int ui= 123456789;

	printf("Char							%c \n", ch);
   	printf("String							%s \n" , str);
   	printf("Address							%p \n", str);
   	printf("Integer							%d\n" , no);
   	printf("Int (0 ou 0x)						%i \n", hex);
   	printf("Unsignied int						%u \n", ui);
   	printf("Hexadecimal unsign int (lower-case)			%x \n", no);
   	printf("Hexadecimal unsign int (upper-case)			%X \n", no);
   	//printf("Prints a literal %% character  				%% \n");
	
	printf("---------------FLAG'-0.*’-----------\n");
	//printf("%.*s\n", 3, "abcdef");
	//printf("--%010s--\n", "abcdef");

/*lag width to reach complete with ' '(digit compris) .  digit to reach complete with '0'
	//printf("c===%2.4c=== \n", ch);
   	printf("s===%.2s== \n" , str);  // . number of digit no completion
   	//printf("p===%2.4p== \n", str);
   	printf("d===%.*== \n", 2, no); //     00150
   	printf("i===%.2i== \n", hex);
   	printf("ui===%.2u== \n", ui);
   	printf("x===%.2x== \n", no);
   	printf("X===%.2X=== \n\n", no);

//Flag 0   0 digit complete avec '0'
	//printf("c===%040c=== \n", ch);
   	//printf("s===%0*s== \n", 20 , str);
   	//printf("p===%1p== \n", str);
   	printf("d===%04d== \n", no);
   	printf("i===%03i== \n", hex);
   	printf("ui===%03u== \n", ui);
   	printf("x===%03x== \n", no);
   	printf("X===%03X=== \n", no);

Flag -
	printf("c===%.40c=== \n", ch);
   	printf("s===%.*s== \n", 40 , str);
   	printf("p===%.40p== \n", str);
   	printf("d===%.40d== \n", no);
   	printf("i===%.40i== \n", hex);
   	printf("ui===%.40u== \n", ui);
   	printf("x===%.40x== \n", no);
   	printf("X===%.40X=== \n", no);
*/
   return 0;
}

