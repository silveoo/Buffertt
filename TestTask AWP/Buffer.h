#ifndef BUFFER_H
#define BUFFER_H

class Buffer {
public:
    Buffer(char* buf);
    Buffer(const Buffer& other, int offset);
    short getdata(int start, int len);
    void putdata(int start, int len, short value);

private:
    char* buf_;
};

#endif // BUFFER_H
