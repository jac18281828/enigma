#pragma once

#include <string>

namespace secret {

    class enigma {
    private:
        
        static const std::string alpha;
        static const std::string rotor[3];
        static const std::string reflector;
        std::string key;

        inline long mod26(const long a) {
            return (a%26+26)%26;
        }

        inline int li(char l) {
            return l - 'A';
        }

        std::size_t index_of(std::string const& str, int find) {

            const int N = str.length();
            for(std::size_t i=0; i<N; ++i) {
                if(str[i] == find) {
                    return i;
                }
            }
            return -1;
        }
        
    public:
        enigma(std::string const& key);
        
        std::string crypt(std::string const& ct);
    };

}
