#include <iostream>
#include <unistd.h>

#include "shm_iface.h"

int main()
{
    shm_buffer* buf;
    ShmIface shm_iface("./shm");
    shm_iface.create_shm(&buf);
    std::cout << "buffer: " << buf << std::endl;
    while(1)
    {
        sleep(1);
        shm_iface.lock(&buf->futex_word);
        std::cout << "lock acquire: " << &buf->futex_word << ":" << buf->futex_word << std::endl;
        if (buf->access)
            continue;

        buf->access = true;

        if (buf->access == false) {
            std::cout << "race condition: " << buf->access << std::endl;
            break;
        }

        buf->access = false;
        sleep(3);
        std::cout << "lock release: " << &buf->futex_word << ":" << buf->futex_word << std::endl;
        shm_iface.unlock(&buf->futex_word);
    }
    std::cout << "buffer content: " << buf->buf << std::endl;
}
