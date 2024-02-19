#include "Buffer.h"

Buffer::Buffer(char* buf) : buf_(buf) {} //конструктор из массива байт

Buffer::Buffer(const Buffer& other, int offset) : buf_(other.buf_ + offset) {} //из существующего экземпл€ра

short Buffer::getdata(int start, int len) {
    short value = 0;
    for (int i = start; i < start + len; ++i) {
        int byteIndex = i / 8;
        int bitIndex = i % 8;
        value |= ((buf_[byteIndex] >> bitIndex) & 1) << (i - start);
    }
    if ((value >> (len - 1)) & 1) { // если старший бит равен 1, то число отрицательное
        value |= ~((1 << len) - 1); // расшир€ем знак
    }
    return value;
}

void Buffer::putdata(int start, int len, short value) {
    for (int i = start; i < start + len; ++i) {
        int byteIndex = i / 8;
        int bitIndex = i % 8;
        buf_[byteIndex] &= ~(1 << bitIndex); // сбрасываем бит
        buf_[byteIndex] |= ((value >> (i - start)) & 1) << bitIndex; // устанавливаем новое значение бита
    }
}
