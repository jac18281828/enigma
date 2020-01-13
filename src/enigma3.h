#pragma once

#include <string>

namespace secret {

    class enigma3 {
    private:
        
        static const std::string alpha;
        static const std::string rotor[3];
        static const std::string reflector;

        const std::string key;

        inline int mod26(const int a) {
            return (a%26+26)%26;
        }

        inline int li(char l) {
            return l - 'A';
        }
        
    public:
        enigma3(std::string const& key);
        
        std::string crypt(std::string const& ct);
    };

}
