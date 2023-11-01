#include <atomic>
#include <iostream>
#include <fcntl.h>
#include <assert.h>
#include <unistd.h>
#include <sys/mman.h>
#include <string.h>
#include <sys/syscall.h>
#include <linux/futex.h>

#include "shm_iface.h"

ShmIface::ShmIface(const char* shm_path)
{
    m_shm_path = shm_path;
    std::cout << "Shared memory map file path: " << m_shm_path << std::endl;
}

ShmIface::~ShmIface()
{}

void ShmIface::create_shm(shm_buffer** buf)
{
    int ret;

    m_shm_fd = open(m_shm_path, O_CREAT | O_RDWR, 0666);
    if (m_shm_fd == -1)
        perror("open sniper2sw shm file failed");
    assert(m_shm_fd != -1);

    ret = ftruncate(m_shm_fd, sizeof(shm_buffer));
    assert(ret != -1);

    *buf = (shm_buffer *)mmap(NULL, sizeof(shm_buffer), PROT_READ | PROT_WRITE,
                             MAP_SHARED | MAP_POPULATE, m_shm_fd, 0);

    memset((void*) *buf, 0, sizeof(shm_buffer));
    std::cout << "Create shm buffer: " << *buf << std::endl;
}

void ShmIface::open_shm(shm_buffer** buf)
{
    m_shm_fd = open(m_shm_path, O_CREAT | O_RDWR, 0666);
    assert(m_shm_fd);
    *buf = (shm_buffer *)mmap(NULL, sizeof(shm_buffer), PROT_READ | PROT_WRITE,
                             MAP_SHARED | MAP_POPULATE, m_shm_fd, 0);
    std::cout << "Open shm buffer: " << *buf << std::endl;
}

void ShmIface::lock(int* futex)
{
    if (!__sync_bool_compare_and_swap(futex, 0, 1))
    {
        if (__atomic_load_n (futex, __ATOMIC_RELAXED) == 2)
            goto futex;

        while (__atomic_exchange_n (futex, 2, __ATOMIC_ACQUIRE) != 0)
        {
        futex:
            syscall(SYS_futex, futex, FUTEX_WAIT, 2, 0, 0, 0);
        }
    }
}

void ShmIface::unlock(int* futex)
{
    int old_val = __atomic_exchange_n(futex, 0, __ATOMIC_RELAXED);
    if (old_val > 1)
    {
        syscall(SYS_futex, futex, FUTEX_WAKE, 1, 0, 0, 0);
    }
}
