//
// Created by pavel on 26.03.2017.
//
//test
int main() {
    BigInt b1; //= "1037812047196842163142241";
    BigInt b0; // = -10009;
    std::cin >> b1;
    std::cin >> b0;
    b1.print();
    b0.print();
    std::cout << "sqrt(b1) = " << sqrt(b1) << std::endl;
    std::cout << "sqrt(b0) = " << sqrt(b0) << std::endl;
    std::cout << "NOD(b1, b0) = " << nod(b1, b0) << std::endl;
    std::cout << "b1 * b0 = " << b1 * b0<< std::endl;
    std::cout << "b1 / b0 = " << b1 / b0 << std::endl;
}
//M
int main() {
    BigInt a;
    BigInt b;
    std::cin >> a >> b;
    std::cout << a + b;
}

//N
int main() {
    BigInt a;
    BigInt b;
    std::cin >> a >> b;
    std::cout << a - b;
}

//O
int main() {
    BigInt a;
    BigInt b;
    std::cin >> a >> b;
    std::cout << a * b;
}

//P
int main() {
    BigInt a;
    BigInt b;
    std::cin >> a >> b;
    std::cout << a / b << ' ' << a % b;
}

//R
int main() {
    BigInt a;
    std::cin >> a;
    std::cout << sqrt(a);
}