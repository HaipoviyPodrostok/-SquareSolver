#include <TXLib.h>
#include <stdio.h>
#define EPSILON 1e-6
int InputCoefficients (double * a, double * b, double * c);
void CalculateDiscriminant (double a, double b, double c, double * D);
int SolveSquare (double a, double b, double c, double * x1, double * x2, double D);
int PrintRoots(double a, double b, double c, double * x1, double * x2, double D );
bool isEqual(double x, double y);

int main() {

    double a = 0,b = 0,c = 0, D = 0;
    double x1 = 0,x2 = 0;  //fabs, bool, double comparison, NAN,с одной буквы функции, вынести switch, названия функций

    if (InputCoefficients(&a,&b,&c)) {
        return 0;
    }

    CalculateDiscriminant(a,b,c,&D);

    PrintRoots(a,b,c,&x1,&x2,D);

}

int InputCoefficients(double * a , double * b,double * c) {

    printf ("Введите коэффициенты a,b,c (через запятую) для квадаратного уравнения вида ax^2+bx+c \n");

        if ( scanf ("%lg,%lg,%lg", a,b,c) != 3 ) {
            printf("Неверно введенное значение");
            return 1;
        }
        return 0;
}

int SolveSquare (double a, double b, double c, double * x1, double * x2, double D) {

        if (D < 0) {
            return 0;              // отрубить до деления на 0, отдельно расмотреть а=0
        }

        if (isEqual(D,0)) {        // раздельная компиляция
            *x1 = (-b) / (2 * a);
            return 1;
        }

        if (D > 0) {
            *x1 = (-b - sqrt(D)) / (2 * a);
            *x2 = (-b + sqrt(D)) / (2 * a);
            return 2;
        }

        if (isEqual(a,0) &&
            isEqual(b,0) &&
            isEqual(c,0) ) {
            return 3;
        }
}

void CalculateDiscriminant(double a, double b, double c, double * D) //evaluate
    {
    *D = b*b - 4*a*c;
    }

int PrintRoots(double a, double b, double c, double * x1, double * x2, double D) {      // объявление?

    int nRoots = SolveSquare (a, b, c, x1, x2, D);

        switch (nRoots) {
            case 0:
                printf("Нет корней\n");
                break;

            case 1:
                printf("x=%lg\n", *x1);
                break;

            case 2:
                printf("x1=%lg, x2=%lg\n", *x1, *x2);
                break;

            case 3:
                printf("Любое число/n");
                break;

            default:
                printf("main(): ERROR: nRoots = %d\n",nRoots);
                return 1;
        }


}
bool isEqual(double x, double y) {
    return fabs(x - y) < EPSILON;
}
























