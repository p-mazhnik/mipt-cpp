#include "String.h"

int main()
{
    char s[] = "Hello";
    char c = '!';
    String a;
    std::cin >> a;
    String b;
    b = " ,people;)";
    b.append(c);
    std::cout << s + a + b<< std::endl;
    std::cout << a[0] << std::endl;
    std::cout << a << std::endl;
    a.append(s);
    a.append(c);
    std::cout << a << std::endl;
    std::cout << int(a) << std::endl;
    std::cout << a.length() << std::endl;
    std::cout << a.find('l') << std::endl;
    std::cout << a.substring() << std::endl;
    char *f = a;
    std::cout << f << std::endl;
    return 0;
}
