#ifndef SHM_IFACE_H_
#define SHM_IFACE_H_

#include <array>
#include <atomic>

struct shm_buffer
{
    int buf;
    int futex_word;
    bool access;
};

class ShmIface
{
    public:
        ShmIface(const char* shm_path);
        ~ShmIface();

        void create_shm(shm_buffer** buf);
        void open_shm(shm_buffer** buf);
        void get_shm_buffer(shm_buffer* buf);
        void set_shm_buffer(shm_buffer* buf);
        void lock(int* futex);
        void unlock(int* futex);

    private:
        int m_shm_fd;
        const char* m_shm_path;
};

#endif // SHM_IFACE_H_
