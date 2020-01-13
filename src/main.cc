#include <cstdlib>
#include <iostream>

#include "enigma3.h"

using namespace std;

int main(const int argc, char const* argv[]) {

    secret::enigma3 e("IVR");

    for(int i=1; i<argc; i++) {
        std::cout << e.crypt(argv[i]) << std::endl;
    }

    return EXIT_SUCCESS;
}
