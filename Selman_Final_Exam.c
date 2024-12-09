#include <stdio.h>
#define taxRate 0.08625
#define employees 25

int i;
int payCode;
int id[employees];
float hoursWorked[employees];
float payRate;
float weeklySales;
float grossPay[employees];
float taxWithholding[employees];
float netPay[employees];
float totalPay;

void hourly(float *grossPay, float *hoursWorked, float num1, int num2);
void comm(float *grossPay, float num1, int num2);
void taxes(float *taxWithholding, float *grossPay, float *netPay, int num2);

int main (void)
{
	for(i = 0; i < employees; i++)
	{
		printf("Pay code: ");
		scanf("%d", &payCode);
		
		switch(payCode)
		{
			case 3:
				printf("Weekly sales: ");
				scanf("%f", &weeklySales);
				
				comm(grossPay, weeklySales, i);
				taxes(taxWithholding, grossPay, netPay, i);
				break;
			case 2:
				printf("Employee pay rate: ");
				scanf("%f", &payRate);
				
				printf("Hours worked: ");
				scanf("%f", &hoursWorked[i]);
				
				hourly (grossPay, hoursWorked, payRate, i);
				taxes(taxWithholding, grossPay, netPay, i);
				break;
			default:
				printf("Weekly salary: ");
				scanf("%f", &grossPay[i]);
				taxes(taxWithholding, grossPay, netPay, i);
		}
	}
	for(i = 0; i < employees; i++)
	{
		printf("Employee ID: %d\tHours worked: %.2f\tGross pay: %.2f\tTax withholdings: %.2f\tNet pay: %.2f\n", id[i], hoursWorked[i], grossPay[i], taxWithholding[i], netPay[i]);
		totalPay += grossPay[i];
	}
	
	printf("Total weekly pay: %.2f", totalPay);
}

void hourly (float *grossPay, float *hoursWorked, float num2, int num3)
{
	grossPay[num3] = hoursWorked[i] * payRate;
	
	if(hoursWorked[i] > 40)
	{
		grossPay[num3] += (hoursWorked[i] - 40) * (payRate * .5);
	}
}

void comm(float *grossPay, float num1, int num2)
{
	grossPay[i] = 375 + (num1 * .072);
}

void taxes (float *taxWithholding, float *grossPay, float *netPay, int num1)
{
	taxWithholding[num1] = grossPay[num1] * taxRate;
	netPay[num1] = grossPay[num1] - taxWithholding[num1];
}