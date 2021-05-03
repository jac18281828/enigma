#include <ctype.h>

#include "enigma3.h"

using namespace secret;

const std::string enigma3::alpha = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

const std::string enigma3::rotor[3] = {
    "EKMFLGDQVZNTOWYHXUSPAIBRCJ",
    "AJDKSIRUXBLHWTMCQGZNPYFVOE",
    "BDFHJLCPRTXVZNYEIWGAKMUSQO"
}; 

const std::string enigma3::reflector = "YRUHQSLDPXNGOKMIEBFZCWVJAT";

enigma3::enigma3(std::string const& key) : key(key) { }

// issues
// rotors are constant - not variable
// only R is being rotated
// lookup is linear search

std::string enigma3::crypt(std::string const& ct) {

    int const L = li(key[0]);
    int const M = li(key[1]);
    int R = li(key[2]);

    std::string result;

    for(std::string::const_iterator x = ct.begin(); x != ct.end(); ++x) {

        const char X = ::toupper(*x);

        const int ct_letter = li(X);

        R = static_cast<int>(mod26(R + 1));

        const char a = rotor[2][mod26(R + ct_letter)];
        const char b = rotor[1][mod26(M + li(a) - R)];
        const char c = rotor[0][mod26(L + li(b) - M)];

        const char ref = reflector[mod26(li(c) - L)];

        // inverse pass
        const int d = mod26(rotor[0].find(alpha[mod26(li(ref) + L)]) - L);
        const int e = mod26(rotor[1].find(alpha[mod26(d + M)]) - M);
        const char f = alpha[mod26(rotor[2].find(alpha[mod26(e + R)]) - R)];

        result += f;
    }

    return result;
}

