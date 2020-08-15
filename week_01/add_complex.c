#include<stdio.h>
struct complex_numbers {
    float real;
    float imag;
 };

int add_complex_numbers(struct complex_numbers c1, struct complex_numbers c2);

int add_complex_numbers(struct complex_numbers c1, struct complex_numbers c2)
{
  printf("The addition of two complex numbers is: %f + %fi", (c1.real + c2.real), (c1.imag + c2.imag));
  return 0;
}

int main()
{
    struct complex_numbers c1, c2;
    printf("Enter real and imaginary parts of first complex number:");
    scanf("%f%f",&c1.real,&c1.imag);
    printf("Enter real and imaginary parts of second complex number:");
    scanf("%f%f",&c2.real,&c2.imag);
    add_complex_numbers(c1,c2);
    return 0;
}