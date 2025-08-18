#include <iostream>
#include <string>
#include <bitset>
#include <array>

struct Network {
    std::string ip;
    int networkMask;

    Network(std::string ip, int mask) {
        this->ip = ip;
        this->networkMask = (mask > 32) ? 24 : mask;
    }

    std::string networkMaskDecimal() {
        std::bitset<32> mask;
        for (int i = 0; i < networkMask; i++) {
            mask.set(31 - i, true);
        }

        std::string maskStr = mask.to_string();
        std::array<int,4> octetos;

        for (int i = 0; i < 4; i++) {
            std::string oct = maskStr.substr(i*8, 8);
            octetos[i] = std::bitset<8>(oct).to_ulong();
        }

        return std::to_string(octetos[0]) + "." +
               std::to_string(octetos[1]) + "." +
               std::to_string(octetos[2]) + "." +
               std::to_string(octetos[3]);
    }
};

int main() {
    Network net("192.168.0.1", 24);

    std::cout << "IP: " << net.ip << "\n";
    std::cout << "Mascara CIDR: /" << net.networkMask << "\n";
    std::cout << "Mascara decimal: " << net.networkMaskDecimal() << "\n";

    return 0;
}