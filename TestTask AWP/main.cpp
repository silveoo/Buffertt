#include <iostream>
#include <vector>
#include "Buffer.h"

int main() {
    std::vector<char> buf(20);
    Buffer buffer(buf.data());

    buffer.putdata(0, 11, -5);
    std::cout << buffer.getdata(0, 11) << std::endl; // выводит -5

    buffer.putdata(11, 6, 4);
    std::cout << buffer.getdata(11, 6) << std::endl; // выводит 4

    Buffer anotherBuffer(buf.data() + 10); //смещение на 10 байт

    anotherBuffer.putdata(0, 11, -3);
    std::cout << anotherBuffer.getdata(0, 11) << std::endl; // выводит -3

    anotherBuffer.putdata(11, 6, 2);
    std::cout << anotherBuffer.getdata(11, 6) << std::endl; // выводит 2

    return 0;
}