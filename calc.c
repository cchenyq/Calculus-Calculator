#include <stdio.h>
#include <stdlib.h>

struct term {
  int power;
  float coeff;
};
typedef struct term term;

term integrate(term var);
int differentiate(term var, term *deriv);

term integrate(term var) {
  term integral;
  integral.coeff = var.coeff/(var.power+1.0);
  integral.power = var.power+1;
  return integral;
}

int differentiate(term var, term *deriv) {
  deriv->coeff = (float)var.power * var.coeff;
  deriv->power = var.power-1;
  return 0;
}

int main(void) {
  term var;
  float m;
  int n;
  term integral;
  term deriv;
  
  printf("Enter the coefficient: \n");
  scanf("%8f",&m);
  var.coeff = m;
  
  printf("Enter the exponent: \n");
  scanf("%d",&n);
  var.power = n;
  
  printf("Original polynomial is %8fy^(%d)\n", var.coeff, var.power);
  
  integral = integrate(var);
  printf("Integral: %8fy^(%d)\n", integral.coeff, integral.power);
  
  differentiate(var, &deriv);
  printf("Derivative: %8fy^(%d)\n", deriv.coeff, deriv.power);
  
  return 0;
}
