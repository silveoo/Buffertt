#include <iostream>
#include <vector>
#include "Buffer.h"

int main() {
    std::vector<char> buf(20);
    Buffer buffer(buf.data());

    buffer.putdata(0, 11, -5);
    std::cout << buffer.getdata(0, 11) << std::endl; // ������� -5

    buffer.putdata(11, 6, 4);
    std::cout << buffer.getdata(11, 6) << std::endl; // ������� 4

    Buffer anotherBuffer(buf.data() + 10); //�������� �� 10 ����

    anotherBuffer.putdata(0, 11, -3);
    std::cout << anotherBuffer.getdata(0, 11) << std::endl; // ������� -3

    anotherBuffer.putdata(11, 6, 2);
    std::cout << anotherBuffer.getdata(11, 6) << std::endl; // ������� 2

    return 0;
}