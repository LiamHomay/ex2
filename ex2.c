/******************
Name: Liam Homay
ID: 333087807
Assignment: ex2
*******************/

#include <stdio.h>

int main() {
    int option;

    do {
        printf("Choose an option:\n");
        printf("    1. Happy Face\n");
        printf("    2. Balanced Number\n");
        printf("    3. Generous Number\n");
        printf("    4. Circle Of Joy\n");
        printf("    5. Happy Numbers\n");
        printf("    6. Festival Of Laughter\n");
        printf("    7. Exit\n");

        scanf("%d", &option);

        switch (option) {
            case 1: {
                while (getchar() != '\n');

                char eyeSymbol, noseSymbol, mouthSymbol;
                int faceSize;

                printf("Enter symbols for the eyes, nose, and mouth:\n");
                scanf(" %c %c %c", &eyeSymbol, &noseSymbol, &mouthSymbol);

                printf("Enter face size:\n");
                do {
                    scanf("%d", &faceSize);
                    if (faceSize <= 0 || faceSize % 2 == 0) {
                        printf("The face's size must be an odd and positive number, please try again:\n");
                    }
                } while (faceSize <= 0 || faceSize % 2 == 0);

                printf("%c", eyeSymbol);
                for (int i = 0; i < faceSize; i++) {
                    printf(" ");
                }
                printf("%c\n", eyeSymbol);

                for (int i = 0; i < faceSize / 2 + 1; i++) {
                    printf(" ");
                }
                printf("%c\n", noseSymbol);

                printf("\\");
                for (int i = 0; i < faceSize; i++) {
                    printf("%c", mouthSymbol);
                }
                printf("/\n");

                break;
            }

            case 2: {
                while (getchar() != '\n');

                int number;
                printf("Enter a number:\n");

                do {
                    scanf("%d", &number);
                    if (number <= 0) {
                        printf("Only positive number is allowed, please try again:\n");
                    }
                } while (number <= 0);

                int temp = number;
                int numDigits = 0;

                while (temp > 0) {
                    temp /= 10;
                    numDigits++;
                }

                int leftSum = 0, rightSum = 0;

                for (int i = 1; i <= numDigits; i++) {
                    int digit = number;
                    for (int j = 1; j < numDigits - i + 1; j++) {
                        digit /= 10;
                    }
                    digit %= 10;

                    if (numDigits % 2 == 0) {
                        if (i <= numDigits / 2) {
                            leftSum += digit;
                        } else {
                            rightSum += digit;
                        }
                    } else {
                        if (i < (numDigits + 1) / 2) {
                            leftSum += digit;
                        } else if (i > (numDigits + 1) / 2) {
                            rightSum += digit;
                        }
                    }
                }

                if (leftSum == rightSum) {
                    printf("This number is balanced and brings harmony!\n");
                } else {
                    printf("This number isn't balanced and destroys harmony.\n");
                }

                break;
            }

            case 3: {
                while (getchar() != '\n');

                int number;
                printf("Enter a number:\n");

                do {
                    scanf("%d", &number);
                    if (number <= 0) {
                        printf("Only positive number is allowed, please try again:\n");
                    }
                } while (number <= 0);

                int sum = 0;

                for (int i = 1; i < number; i++) {
                    if (number % i == 0) {
                        sum += i;
                    }
                }

                if (sum > number) {
                    printf("This number is generous!\n");
                } else {
                    printf("This number does not share.\n");
                }

                break;
            }

            case 4: {
                while (getchar() != '\n');
                int number;
                printf("Enter a number:\n");

                do {
                    scanf("%d", &number);
                    if (number <= 0) {
                        printf("Only positive number is allowed, please try again:\n");
                    }
                } while (number <= 0);

                int isPrimeOriginal = 1;
                if (number <= 1) {
                    isPrimeOriginal = 0;
                } else {
                    for (int i = 2; i < number; i++) {
                        if (number % i == 0) {
                            isPrimeOriginal = 0;
                            break;
                        }
                    }
                }

                int reversed = 0;
                int temp = number;
                while (temp > 0) {
                    reversed = reversed * 10 + temp % 10;
                    temp /= 10;
                }

                int isPrimeReversed = 1;
                if (reversed <= 1) {
                    isPrimeReversed = 0;
                } else {
                    for (int i = 2; i < reversed; i++) {
                        if (reversed % i == 0) {
                            isPrimeReversed = 0;
                            break;
                        }
                    }
                }

                if (isPrimeOriginal && isPrimeReversed) {
                    printf("This number completes the circle of joy!\n");
                } else {
                    printf("The circle remains incomplete.\n");
                }

                break;
            }

            case 5: {
                while (getchar() != '\n');

                int number;
                printf("Enter a number:\n");

                do {
                    scanf("%d", &number);
                    if (number <= 0) {
                        printf("Only positive number is allowed, please try again:\n");
                    }
                } while (number <= 0);

                printf("Between 1 and %d only these numbers bring happiness:", number);

                for (int i = 1; i <= number; i++) {
                    int isHappy = 0;
                    int num = i;

                    while (1) {
                        int sum = 0;
                        int temp = num;

                        while (temp > 0) {
                            int digit = temp % 10;
                            sum += digit * digit;
                            temp /= 10;
                        }

                        if (sum == 1) {
                            isHappy = 1;
                            break;
                        }

                        if (sum == 4) { // Infinite loop indicator
                            break;
                        }

                        num = sum;
                    }

                    if (isHappy) {
                        printf(" %d", i);
                    }
                }

                printf("\n");

                break;
            }

            case 6: {
                while (getchar() != '\n');

                int smile = -1, cheer = -1;
                printf("Enter a smile and cheer number:\n");

                do {
                    smile = cheer = -1;
                    scanf("smile: %d, cheer: %d", &smile, &cheer);

                    if (smile <= 0 || cheer <= 0 || smile == cheer) {
                        while (getchar() != '\n');
                        printf("Only 2 different positive numbers in the given format are allowed for the festival, please try again:\n");
                    }

                } while (smile <= 0 || cheer <= 0 || smile == cheer);

                int maxNum = -1;
                printf("Enter maximum number for the festival:\n");

                do {
                    maxNum = -1;
                    scanf("%d", &maxNum);

                    if (maxNum <= 0) {
                        while (getchar() != '\n');
                        printf("Only positive maximum number is allowed, please try again:\n");
                    }
                } while (maxNum <= 0);

                for (int i = 1; i <= maxNum; i++) {
                    if (i % smile == 0 && i % cheer == 0) {
                        printf("Festival!\n");
                    } else if (i % smile == 0) {
                        printf("Smile!\n");
                    } else if (i % cheer == 0) {
                        printf("Cheer!\n");
                    } else {
                        printf("%d\n", i);
                    }
                }

                break;
            }


            case 7:
                while (getchar() != '\n');
                printf("Thank you for your journey through Numeria!\n");
                break;

            default:
                while (getchar() != '\n');
                printf("This option is not available, please try again.\n");
        }
    } while (option != 7);

    return 0;
}
