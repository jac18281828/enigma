#include <cstdlib>
#include <iostream>

#include "magic_test.h"
#include "enigma3.h"

using namespace std;

static bool encrypt_test(void);

static bool decrypt_test(void);

int main(const int argc, char const* argv[]) {

    std::cout << "Run tests:" << std::endl;

    MAGIC_TEST(encrypt_test());

    MAGIC_TEST(decrypt_test());

    std::cout << magic_test::nTest << " TESTS PASS" << std::endl;
    
    return EXIT_SUCCESS;
}

bool encrypt_test(void) {
    
    secret::enigma3 e("JVR");
    
    const auto r = e.crypt("ORANGEORANGEPINEAPPLEORANGE");

    return MAGIC_EQUALS(r, "FWMOMJEXDYWHCGRKTLBHIYMMHXM");
    
}

bool decrypt_test(void) {
    secret::enigma3 e("JVR");
    
    const auto r = e.crypt("FWMOMJEXDYWHCGRKTLBHIYMMHXM");

    return MAGIC_EQUALS(r, "ORANGEORANGEPINEAPPLEORANGE");

}
