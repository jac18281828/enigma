#include <unistd.h>
#include <iostream>

#include "enigma.h"

using namespace std;

int main(int argc, char *argv[]) {

    secret::enigma e("ABC");

    for(int i=1; i<argc; i++) {
        std::cout << e.crypt(argv[i]) << std::endl;
    }

    /*
    for(int i=0; i<1000000; i++) {
        e.crypt("ORANGE ORANGE PINEAPPLE ORANGE");
    }
    */

    return EXIT_SUCCESS;
}
