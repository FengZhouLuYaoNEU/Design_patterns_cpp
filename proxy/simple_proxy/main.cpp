#include <iostream>
#include "client.h"
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
    NorthKoreaClient client;
    ProxyServer  * japanVpn = new JapanVPN;
    client.buyVpnService(100,japanVpn);
    std::cout<<client.visitFaceBook()<<std::endl;
    delete japanVpn;
    return 0;
}
