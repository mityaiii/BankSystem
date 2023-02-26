#pragma comment(lib, "ws2_32.lib")

#include "Server.h"

#include <winsock2.h>
#include <iostream>

int main(int argc, char** argv) {
  WSAData wsa_data{};
  WORD dli_version = MAKEWORD(2, 1);
  if(WSAStartup(dli_version, &wsa_data) != 0) {
    std::cout << "Error" << std::endl;

    return EXIT_FAILURE;
  }

  SOCKADDR_IN addr;
  addr.sin_addr.s_addr = inet_addr("127.0.0.1");
  addr.sin_port = htons(8888);
  addr.sin_family = AF_INET;

  SOCKET s_listen = socket(AF_INET, SOCK_STREAM, 0);
  bind(s_listen, (SOCKADDR*)&addr, sizeof(addr));
  listen(s_listen, SOMAXCONN);

  int size_of_addr = sizeof(addr);
  SOCKET new_connection;
  new_connection = accept(s_listen, (SOCKADDR*)&addr, &size_of_addr);

  if (new_connection == 0) {
    std::cout << "Error #2" << std::endl;

    return EXIT_FAILURE;
  }

  std::cout << "Client connected!" << std::endl;

  return EXIT_SUCCESS;
}
