#include <stdio.h>
#include <cs50.h>

bool luhn(long number);
int len(long number);
void card_type(long number);

int main(void) {

    long number;
    number = get_long("What is your card number?\n");

    if (luhn(number) == false) {

        printf("INVALID\n");
    }

    else {

        card_type(number);
    }
}

bool luhn(long number) {

    int sum1;
    int sum2;

    long num1 = number;
    long num2 = number;

    num1 = num1 / 10;

    for (sum1 = 0; num1 > 0;) {

        int last_digit = num1 % 10;
        if (2*last_digit <= 9){

            sum1 = sum1 + 2*last_digit;
        }

        else {

            sum1 = sum1 + 2*last_digit - 9;
        }

        num1 = num1 / 100;
     }

     for (sum2 = 0; num2 > 0;) {

        int last_digit = num2 % 10;
        sum2 = sum2 + last_digit;
        num2 = num2 / 100;
     }

     if ((sum1 + sum2) % 10 == 0) {

        return true;
     }

     else return false;

}

int len(long number) {

    int counter;

    for (counter = 1; number > 9; counter++) {

        number = number / 10;
    }

    return counter;
}

void card_type(long number) {

    long original = number;

    for (int length = len(number); length > 2;) {

        number = number / 10;
        length = len(number);
    }

    if ((number == 34 || number == 37) && len(original) == 15) {

        printf("AMEX\n");
    }

    else if ((51 <= number && number <= 55) && len(original) == 16) {

        printf("MASTERCARD\n");
    }

    else if (number / 10 == 4 && (len(original) == 13 || len(original) == 16)) {

        printf("VISA\n");

    }

    else {printf("INVALID\n");}
}
