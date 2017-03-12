//
// Created by pavel on 07.03.2017.
//

#include <iostream>
#include "List.h"

int main() {
    List *list = new ArrayList(1);
    for (int i = 0; i < 10; ++i) {
        list->add(i * i);
    }

    std::cout << list->contains(3) << " " << list->contains(16) << std::endl;

    for (size_t j = 0; j < list->size(); ++j) {
        std::cout << list->get(j) << std::endl;
    }
}

