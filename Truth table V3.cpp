//Hamza Khan Tariq
// registration number    04072313050

#include <iostream>
# include <string>
using namespace std;



bool AND(bool p, bool q) {
    if (p == 1 && q == 1)
        return  true;
    else
        return false;

}
bool OR(bool p, bool q) {
    return (p || q);
}
bool  IMP(bool p, bool q) {
    return (!p || q);   // as p->q is logically equilance to !p||q
}
bool neegation(bool p) {
    return !p;
}
bool bicondition(bool p, bool q) {
    return (p == q);
}
bool XOR(bool p, bool q) {
    return (p != q);
}


bool identify_expression(bool p, bool q, bool r, string sign1, string sign2) {
    if (sign1 == "&&") {
        if (sign2 == "||")
        {
            return OR(AND(p, q), r);
        }
        else if (sign2 == "&&") {
            return AND(AND(p, q), r);
        }
        else if (sign2 == "->")
        {
            return  IMP(AND(p, q), r);

        }
        else if (sign2 == "xor") {
            return XOR(AND(p, q), r);
        }
        else if (sign2 == "<->") {
            return bicondition(AND(p, q), r);
        }


    }
    if (sign1 == "||") {
        if (sign2 == "||")
        {
            return OR(OR(p, q), r);
        }
        else if (sign2 == "&&") {
            return AND(OR(p, q), r);
        }
        else if (sign2 == "->")
        {
            return  IMP(OR(p, q), r);

        }
        else if (sign2 == "<->") {
            return bicondition(OR(p, q), r);
        }
        else if (sign2 == "xor") {
            return XOR(OR(p, q), r);
        }
    }
    if (sign1 == "xor") {
        if (sign2 == "||")
        {
            return OR(XOR(p, q), r);
        }
        else if (sign2 == "&&") {
            return AND(XOR(p, q), r);
        }
        else if (sign2 == "->")
        {
            return  IMP(XOR(p, q), r);

        }
        else if (sign2 == "<->") {
            return bicondition(XOR(p, q), r);
        }
        else if (sign2 == "xor") {
            return XOR(XOR(p, q), r);
        }
    }
    if (sign1 == "->") {
        if (sign2 == "||")
        {
            return OR(IMP(p, q), r);
        }
        else if (sign2 == "&&") {
            return AND(IMP(p, q), r);
        }
        else if (sign2 == "->")
        {
            return  IMP(IMP(p, q), r);

        }
        else if (sign2 == "<->") {
            return bicondition(IMP(p, q), r);
        }
        else if (sign2 == "xor") {
            return XOR(IMP(p, q), r);
        }
    }
    if (sign1 == "<->") {
        if (sign2 == "||")
        {
            return OR(bicondition(p, q), r);
        }
        else if (sign2 == "&&") {
            return AND(bicondition(p, q), r);
        }
        else if (sign2 == "->")
        {
            return  IMP(bicondition(p, q), r);

        }
        else if (sign2 == "<->") {
            return bicondition(bicondition(p, q), r);
        }
        else if (sign2 == "xor") {
            return XOR(bicondition(p, q), r);

        }


    }
    return false;
}


int main() {
    string exp1, exp2, exp3;   // for storing three variables 
    string sign1, sign2;       // for storing signs like &&, ||, !, xor, ->, <-> 

    cout << "=============================================" << endl;
    cout << "          Logical Expression Evaluator       " << endl;
    cout << "=============================================" << endl;

    cout << "Enter logical expressions using variables p, q, and r." << endl << endl;
    cout << "Limitations: - brackets cant be read     - variable duplication cant be done         -variable interchange" << endl << endl;

    cout << "Use any of the following:\n"
        << "  - &&  : Logical AND\n"
        << "  - ||  : Logical OR\n"
        << "  - !   : Negation\n"
        << "  - ->  : Implication\n"
        << "  - <-> : Biconditional\n";
       

    cout << "-------------------------------------------------" << endl;

    // Gather user input for expressions and operators
    cout << "1. First variable (p or !p): ";
    cin >> exp1;
    cout << "2. Second variable (q or !q): ";
    cin >> exp2;
    cout << "3. Operator between 1st and 2nd variable (&&, ||, ->, <->): ";
    cin >> sign1;
    cout << "4. Third variable (r or !r): ";
    cin >> exp3;
    cout << "5. Operator between 2nd and 3rd variable (&&, ||, ->, <->): ";
    cin >> sign2;

    cout << "-------------------------------------------------" << endl;
    cout << "Your logical expression is: "
        << exp1 << " " << sign1 << " "
        << exp2 << " " << sign2 << " "
        << exp3 << endl;
    cout << "-------------------------------------------------" << endl;

    // Print table headers
    cout << "Truth Table:" << endl;
    cout << " p\t q\t r\t Result" << endl;
    cout << "------------------------------" << endl;

    // Generate and display truth table
    for (int i = 0; i <= 1; i++) {
        for (int j = 0; j <= 1; j++) {
            for (int k = 0; k <= 1; k++) {
                bool p = i, q = j, r = k;  // Assign boolean values

                // Handle negation
                if (exp1.find("!") != string::npos) {
                    p = neegation(p);
                }
                if (exp2.find("!") != string::npos) {
                    q = neegation(q);
                }
                if (exp3.find("!") != string::npos) {
                    r = neegation(r);
                }

                bool result = identify_expression(p, q, r, sign1, sign2);

                // Display results in a structured format
                cout << " " << p << "\t " << q << "\t " << r << "\t " << result << endl;
            }
        }
    }

    cout << "=============================================" << endl;
    cout << "          Evaluation Complete                 " << endl;
    cout << "=============================================" << endl;

    return 0;
}

