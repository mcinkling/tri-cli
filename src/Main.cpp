#include <iostream>
#include <cmath>

#define TAU 6.283185307
using namespace std;

int main() {
    long double alpha {0.0f};
    long double beta {0.0f};
    long double a {0.0f}; // Gegenkathete von alpha; aK von beta
    long double b {0.0f}; // Ankathete von alpha; gK von beta
    long double c {0.0f};
    cout.precision(5);


    cout << "     β=? \n" \
            "      \\   \n" \
            "      /|   \n" \
            " c=? / | a=? \n" \
            "  \\ /  |/   \n" \
            "   /  .|   \n" \
            "  |----    \n" \
            " α=? \\     \n" \
            "      b=?  \n\n";

    cout << "Bitte geben Sie die bekannten Werte ein.\n";
    cout << "Enter für nicht bekannt.\n\n";

    {
        string input;
        cout << "Winkel α     = ";
        getline(cin, input);
        if (!input.empty()) {
            alpha = stold(input);
        }
    }
    {
        string input;
        cout << "Winkel β     = ";
        getline(cin, input);
        if (!input.empty()) {
            beta = stold(input);
        }
    }
    {
        string input;
        cout << "Kathete a    = ";
        getline(cin, input);
        if (!input.empty()) {
            a = stold(input);
        }
    }
    {
        string input;
        cout << "Kathete b    = ";
        getline(cin, input);
        if (!input.empty()) {
            b = stold(input);
        }
    }
    {
        string input;
        cout << "Hypotenuse c = ";
        getline(cin, input);
        if (!input.empty()) {
            c = stold(input);
        }
    }

    cout << "\n-----------------------------\n\n";

    for (short i {0}; i < 1; i++) {
        if (a == 0) {
            if (b != 0 && c != 0) {
                a = sqrt(c*c-b*b);
                goto adone;
            }
            if (alpha != 0 && c != 0) {
            a = sin(alpha*TAU/360)*c;
            goto adone;
            }
            if (alpha != 0 && b != 0) {
            a = tan(alpha*TAU/360)*b;
            goto adone;
            }
        }
        adone:

        if (b == 0) {
            if (a != 0 && c != 0) {
                b = sqrt(c*c-a*a);
                goto bdone;
            }
            if (alpha != 0 && c != 0) {
            b = cos(alpha*TAU/360)*c;
            goto bdone;
            }
            if (alpha != 0 && a != 0) {
            b = a/tan(alpha*TAU/360);
            goto bdone;
            }
        }
        bdone:

        if (c == 0) {
            if (a != 0 && b != 0) {
                c = sqrt(a*a+b*b);
                goto cdone;
            }
            if (alpha != 0 && a != 0) {
            c = a/sin(alpha*TAU/360);
            goto cdone;
            }
            if (alpha != 0 && b != 0) {
            c = b/cos(alpha*TAU/360);
            goto cdone;
            }
        }
        cdone:

        if (alpha == 0) {
            if (beta != 0) {
                alpha = 90-beta;
                goto alphadone;
            }
            if (a != 0 && c != 0) {
                alpha = asin(a/c)*360/TAU;
                goto alphadone;
            }
            if (b != 0 && c != 0) {
                alpha = acos(b/c)*360/TAU;
                goto alphadone;
            }
            if (a != 0 && b != 0) {
                alpha = atan(a/b)*360/TAU;
                goto alphadone;
            }
        }
        alphadone:

        if (beta == 0) {
            if (alpha != 0) {
                beta = 90-alpha;
                goto betadone;
            }
            if (b != 0 && c != 0) {
                beta = asin(b/c)*360/TAU;
                goto betadone;
            }
            if (a != 0 && c != 0) {
                beta = acos(a/c)*360/TAU;
                goto betadone;
            }
            if (a != 0 && b != 0) {
                beta = atan(b/a)*360/TAU;
                goto betadone;
            }
        }
        betadone:
        NULL;
    }

    cout << "Winkel α     = " << alpha << "°\n";
    cout << "Winkel β     = " << beta << "°\n";
    cout << "Kathete a    = " << a << '\n';
    cout << "Kathete b    = " << b << '\n';
    cout << "Hypotenuse c = " << c << '\n';

    if (alpha == 0 || beta == 0 || a == 0 || b == 0 || c == 0) {
    cout << "\nKonnte nicht alle Werte berechnen;\n";
    cout << "bitte geben Sie mindestens 2 Werte ein, davon min. 1 Länge.";
    }
    
    cout << "\nEnter zum Verlassen...";
    cin.ignore();
    return 0;
}
