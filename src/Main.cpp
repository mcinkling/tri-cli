#include <iostream>
#include <cmath>

#define TAU 6.283185307
using namespace std;

int main() {
    long double alpha {0.0f};
    long double beta {0.0f};
    long double gamma {0.0f};
    long double a {0.0f}; 
    long double b {0.0f};
    long double c {0.0f};
    cout.precision(5);


    cout << "     γ=?\n" \
            "      \\\n" \
            "      /\\\n" \
            " b=? /  \\ a=?\n" \
            "  \\ /    \\/\n" \
            "   /      \\\n" \
            "  |--------|\n" \
            " α=?  \\    β=?\n" \
            "      c=?\n\n";

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
        cout << "Winkel γ     = ";
        getline(cin, input);
        if (!input.empty()) {
            gamma = stold(input);
        }
    }
    {
        string input;
        cout << "Seite a    = ";
        getline(cin, input);
        if (!input.empty()) {
            a = stold(input);
        }
    }
    {
        string input;
        cout << "Seite b    = ";
        getline(cin, input);
        if (!input.empty()) {
            b = stold(input);
        }
    }
    {
        string input;
        cout << "Seite c = ";
        getline(cin, input);
        if (!input.empty()) {
            c = stold(input);
        }
    }

    cout << "\n-----------------------------\n\n";

    for (short i {0}; i < 5; i++) {
        if (a == 0) {
            if (b != 0 && c != 0 && alpha != 0) {
                a = sqrt(b*b+c*c-2.0*b*c*cos(alpha*TAU/360));
                goto adone;
            }
            if (alpha != 0) {
                if (b != 0 && beta != 0) {
                    a = (b/sin(beta*TAU/360))*sin(alpha*TAU/360);
                    goto adone;
                }
                if (c != 0 && gamma != 0) {
                    a = (c/sin(gamma*TAU/360))*sin(alpha*TAU/360);
                    goto adone;
                }
            }
        }
        adone:

        if (b == 0) {
            if (a != 0 && c != 0 && beta != 0) {
                b = sqrt(a*a+c*c-2.0*a*c*cos(beta*TAU/360));
                goto bdone;    
            }
            if (beta != 0) {
                if (a != 0 && alpha != 0) {
                    b = (a/sin(alpha*TAU/360))*sin(beta*TAU/360);
                    goto bdone;
                }
                if (c != 0 && gamma != 0) {
                    b = (c/sin(gamma*TAU/360))*sin(beta*TAU/360);
                    goto bdone;
                }
            }
        }
        bdone:

        if (c == 0) {
            if (a != 0 && b != 0 && gamma != 0) {
                c = sqrt(a*a+b*b-2.0*a*b*cos(gamma*TAU/360));
                goto cdone;
            }
            if (gamma != 0) {
                if (a != 0 && alpha != 0) {
                    c = (a/sin(alpha*TAU/360))*sin(gamma*TAU/360);
                    goto cdone;
                }
                if (b != 0 && beta != 0) {
                    c = (b/sin(beta*TAU/360))*sin(gamma*TAU/360);
                    goto cdone;
                }
            }
        }
        cdone:

        if (alpha == 0) {
            if (beta != 0 && gamma != 0) {
                alpha = 180-beta-gamma;
                goto alphadone;
            }
            if (a != 0) {
                if (b != 0 && beta != 0) {
                    alpha = asin(a/(b/sin(beta*TAU/360)))*360/TAU;
                    goto alphadone;
                }
                if (c != 0 && gamma != 0) {
                    alpha = asin(a/(c/sin(gamma*TAU/360)))*360/TAU;
                    goto alphadone;
                }
                if (a != 0 && b != 0 && c != 0) {
                    alpha = acos((-a*a+b*b+c*c)/2/b/c)*360/TAU;
                    goto alphadone;
                }
            }
        }
        alphadone:

        if (beta == 0) {
            if (alpha != 0 && gamma != 0) {
                beta = 180-alpha-gamma;
                goto betadone;
            }
            if (b != 0) {
                if (a != 0 && alpha != 0) {
                    beta = asin(b/(a/sin(alpha*TAU/360)))*360/TAU;
                    goto betadone;
                }
                if (c != 0 && gamma != 0) {
                    beta = asin(b/(c/sin(gamma*TAU/360)))*360/TAU;
                    goto betadone;
                }
                if (a != 0 && b != 0 && c != 0) {
                    goto betadone;
                }
            }
        }
        betadone:
        
        if (gamma == 0) {
            if (alpha != 0 && beta != 0) {
                gamma = 180-alpha-beta;
                goto gammadone;
            }
            if (c != 0) {
                if (a != 0 && alpha != 0) {
                    gamma = asin(c/(a/sin(alpha*TAU/360)))*360/TAU;
                    goto gammadone;
                }
                if (b != 0 && beta != 0) {
                    gamma = asin(c/(b/sin(beta*TAU/360)))*360/TAU;
                    goto gammadone;
                }
                if (a != 0 && b != 0 && c != 0) {
                    goto gammadone;
                }
            }
        }
        gammadone:
        NULL;
    }

    cout << "Winkel α        = " << alpha << "°\n";
    cout << "Winkel β        = " << beta << "°\n";
    cout << "Winkel γ        = " << gamma << "°\n";
    cout << "Kathete a       = " << a << '\n';
    cout << "Kathete b       = " << b << '\n';
    cout << "Hypotenuse c    = " << c << '\n';
    
    cout << "\nFlächeninhalt A = " << 0.5*b*c*sin(alpha*TAU/360) << '\n';
    

    if (alpha == 0 || beta == 0 || gamma == 0 || a == 0 || b == 0 || c == 0) {
    cout << "\nKonnte nicht alle Werte berechnen;\n";
    cout << "bitte geben Sie mindestens 3 Werte ein, davon min. 1 Länge.\n";
    cout << "Ein rechter Winkel muß auch eingetragen werden.";
    }
    
    cout << "\nEnter zum Verlassen...";
    cin.ignore();
    return 0;
}
