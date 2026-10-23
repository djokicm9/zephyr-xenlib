#ifndef XENLIB_OSAL_H
#define XENLIB_OSAL_H

#include <xenlib_osal_platform.h>
#include <xenlib_osal_list.h>
#include <xenlib_osal_log.h>
#include <xenlib_osal_assert.h>
#include <xenlib_osal_thread.h>
#include <xenlib_osal_atomic.h>
#include <xenlib_osal_barrier.h>
#include <xenlib_osal_time.h>
#include <xenlib_osal_shell.h>

extern int xenlib_osal_mutex_init(xenlib_osal_mutex_t *mutex);
extern int xenlib_osal_mutex_lock(xenlib_osal_mutex_t *mutex,
						          xenlib_osal_timeout_t timeout);
extern int xenlib_osal_mutex_unlock(xenlib_osal_mutex_t *mutex);

extern int xenlib_osal_semaphore_init(xenlib_osal_semaphore_t *sem, int max_count,
                                      int init_count);
extern int xenlib_osal_semaphore_wait(xenlib_osal_semaphore_t *sem,
                                      xenlib_osal_timeout_t timeout);
extern int xenlib_osal_semaphore_signal(xenlib_osal_semaphore_t *sem);

extern void *xenlib_osal_memalloc(size_t msize);

extern void *xenlib_osal_memalloc_aligned(size_t align, size_t msize);

/* Free a memory block */
extern void xenlib_osal_memfree(void *mblock);

extern int xenlib_osal_dcache_flush_and_invd_range(void *addr, size_t size);

extern uint32_t xenlib_osal_be32_to_cpu(uint32_t value);

#endif /* XENLIB_OSAL_H */
