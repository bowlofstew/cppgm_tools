// jimon, 2014
// small posix proxy to test cppgm course on windows

#ifdef LIBDLL_EXPORTS
	#define LIBDLL_API __declspec(dllexport)
#else
	#define LIBDLL_API __declspec(dllimport)
#endif

// System Call Numbers
#define SN_READ 0
#define SN_WRITE 1
#define SN_OPEN 2
#define SN_CLOSE 3
#define SN_STAT 4
#define SN_FSTAT 5
#define SN_LSTAT 6
#define SN_POLL 7
#define SN_LSEEK 8
#define SN_MMAP 9
#define SN_MPROTECT 10
#define SN_MUNMAP 11
#define SN_BRK 12
#define SN_RT_SIGACTION 13
#define SN_RT_SIGPROCMASK 14
#define SN_RT_SIGRETURN 15
#define SN_IOCTL 16
#define SN_PREAD64 17
#define SN_PWRITE64 18
#define SN_READV 19
#define SN_WRITEV 20
#define SN_ACCESS 21
#define SN_PIPE 22
#define SN_SELECT 23
#define SN_SCHED_YIELD 24
#define SN_MREMAP 25
#define SN_MSYNC 26
#define SN_MINCORE 27
#define SN_MADVISE 28
#define SN_SHMGET 29
#define SN_SHMAT 30
#define SN_SHMCTL 31
#define SN_DUP 32
#define SN_DUP2 33
#define SN_PAUSE 34
#define SN_NANOSLEEP 35
#define SN_GETITIMER 36
#define SN_ALARM 37
#define SN_SETITIMER 38
#define SN_GETPID 39
#define SN_SENDFILE 40
#define SN_SOCKET 41
#define SN_CONNECT 42
#define SN_ACCEPT 43
#define SN_SENDTO 44
#define SN_RECVFROM 45
#define SN_SENDMSG 46
#define SN_RECVMSG 47
#define SN_SHUTDOWN 48
#define SN_BIND 49
#define SN_LISTEN 50
#define SN_GETSOCKNAME 51
#define SN_GETPEERNAME 52
#define SN_SOCKETPAIR 53
#define SN_SETSOCKOPT 54
#define SN_GETSOCKOPT 55
#define SN_CLONE 56
#define SN_FORK 57
#define SN_VFORK 58
#define SN_EXECVE 59
#define SN_EXIT 60
#define SN_WAIT4 61
#define SN_KILL 62
#define SN_UNAME 63
#define SN_SEMGET 64
#define SN_SEMOP 65
#define SN_SEMCTL 66
#define SN_SHMDT 67
#define SN_MSGGET 68
#define SN_MSGSND 69
#define SN_MSGRCV 70
#define SN_MSGCTL 71
#define SN_FCNTL 72
#define SN_FLOCK 73
#define SN_FSYNC 74
#define SN_FDATASYNC 75
#define SN_TRUNCATE 76
#define SN_FTRUNCATE 77
#define SN_GETDENTS 78
#define SN_GETCWD 79
#define SN_CHDIR 80
#define SN_FCHDIR 81
#define SN_RENAME 82
#define SN_MKDIR 83
#define SN_RMDIR 84
#define SN_CREAT 85
#define SN_LINK 86
#define SN_UNLINK 87
#define SN_SYMLINK 88
#define SN_READLINK 89
#define SN_CHMOD 90
#define SN_FCHMOD 91
#define SN_CHOWN 92
#define SN_FCHOWN 93
#define SN_LCHOWN 94
#define SN_UMASK 95
#define SN_GETTIMEOFDAY 96
#define SN_GETRLIMIT 97
#define SN_GETRUSAGE 98
#define SN_SYSINFO 99
#define SN_TIMES 100
#define SN_PTRACE 101
#define SN_GETUID 102
#define SN_SYSLOG 103
#define SN_GETGID 104
#define SN_SETUID 105
#define SN_SETGID 106
#define SN_GETEUID 107
#define SN_GETEGID 108
#define SN_SETPGID 109
#define SN_GETPPID 110
#define SN_GETPGRP 111
#define SN_SETSID 112
#define SN_SETREUID 113
#define SN_SETREGID 114
#define SN_GETGROUPS 115
#define SN_SETGROUPS 116
#define SN_SETRESUID 117
#define SN_GETRESUID 118
#define SN_SETRESGID 119
#define SN_GETRESGID 120
#define SN_GETPGID 121
#define SN_SETFSUID 122
#define SN_SETFSGID 123
#define SN_GETSID 124
#define SN_CAPGET 125
#define SN_CAPSET 126
#define SN_RT_SIGPENDING 127
#define SN_RT_SIGTIMEDWAIT 128
#define SN_RT_SIGQUEUEINFO 129
#define SN_RT_SIGSUSPEND 130
#define SN_SIGALTSTACK 131
#define SN_UTIME 132
#define SN_MKNOD 133
#define SN_USELIB 134
#define SN_PERSONALITY 135
#define SN_USTAT 136
#define SN_STATFS 137
#define SN_FSTATFS 138
#define SN_SYSFS 139
#define SN_GETPRIORITY 140
#define SN_SETPRIORITY 141
#define SN_SCHED_SETPARAM 142
#define SN_SCHED_GETPARAM 143
#define SN_SCHED_SETSCHEDULER 144
#define SN_SCHED_GETSCHEDULER 145
#define SN_SCHED_GET_PRIORITY_MAX 146
#define SN_SCHED_GET_PRIORITY_MIN 147
#define SN_SCHED_RR_GET_INTERVAL 148
#define SN_MLOCK 149
#define SN_MUNLOCK 150
#define SN_MLOCKALL 151
#define SN_MUNLOCKALL 152
#define SN_VHANGUP 153
#define SN_MODIFY_LDT 154
#define SN_PIVOT_ROOT 155
#define SN__SYSCTL 156
#define SN_PRCTL 157
#define SN_ARCH_PRCTL 158
#define SN_ADJTIMEX 159
#define SN_SETRLIMIT 160
#define SN_CHROOT 161
#define SN_SYNC 162
#define SN_ACCT 163
#define SN_SETTIMEOFDAY 164
#define SN_MOUNT 165
#define SN_UMOUNT2 166
#define SN_SWAPON 167
#define SN_SWAPOFF 168
#define SN_REBOOT 169
#define SN_SETHOSTNAME 170
#define SN_SETDOMAINNAME 171
#define SN_IOPL 172
#define SN_IOPERM 173
#define SN_CREATE_MODULE 174
#define SN_INIT_MODULE 175
#define SN_DELETE_MODULE 176
#define SN_GET_KERNEL_SYMS 177
#define SN_QUERY_MODULE 178
#define SN_QUOTACTL 179
#define SN_NFSSERVCTL 180
#define SN_GETPMSG 181
#define SN_PUTPMSG 182
#define SN_AFS_SYSCALL 183
#define SN_TUXCALL 184
#define SN_SECURITY 185
#define SN_GETTID 186
#define SN_READAHEAD 187
#define SN_SETXATTR 188
#define SN_LSETXATTR 189
#define SN_FSETXATTR 190
#define SN_GETXATTR 191
#define SN_LGETXATTR 192
#define SN_FGETXATTR 193
#define SN_LISTXATTR 194
#define SN_LLISTXATTR 195
#define SN_FLISTXATTR 196
#define SN_REMOVEXATTR 197
#define SN_LREMOVEXATTR 198
#define SN_FREMOVEXATTR 199
#define SN_TKILL 200
#define SN_TIME 201
#define SN_FUTEX 202
#define SN_SCHED_SETAFFINITY 203
#define SN_SCHED_GETAFFINITY 204
#define SN_SET_THREAD_AREA 205
#define SN_IO_SETUP 206
#define SN_IO_DESTROY 207
#define SN_IO_GETEVENTS 208
#define SN_IO_SUBMIT 209
#define SN_IO_CANCEL 210
#define SN_GET_THREAD_AREA 211
#define SN_LOOKUP_DCOOKIE 212
#define SN_EPOLL_CREATE 213
#define SN_EPOLL_CTL_OLD 214
#define SN_EPOLL_WAIT_OLD 215
#define SN_REMAP_FILE_PAGES 216
#define SN_GETDENTS64 217
#define SN_SET_TID_ADDRESS 218
#define SN_RESTART_SYSCALL 219
#define SN_SEMTIMEDOP 220
#define SN_FADVISE64 221
#define SN_TIMER_CREATE 222
#define SN_TIMER_SETTIME 223
#define SN_TIMER_GETTIME 224
#define SN_TIMER_GETOVERRUN 225
#define SN_TIMER_DELETE 226
#define SN_CLOCK_SETTIME 227
#define SN_CLOCK_GETTIME 228
#define SN_CLOCK_GETRES 229
#define SN_CLOCK_NANOSLEEP 230
#define SN_EXIT_GROUP 231
#define SN_EPOLL_WAIT 232
#define SN_EPOLL_CTL 233
#define SN_TGKILL 234
#define SN_UTIMES 235
#define SN_VSERVER 236
#define SN_MBIND 237
#define SN_SET_MEMPOLICY 238
#define SN_GET_MEMPOLICY 239
#define SN_MQ_OPEN 240
#define SN_MQ_UNLINK 241
#define SN_MQ_TIMEDSEND 242
#define SN_MQ_TIMEDRECEIVE 243
#define SN_MQ_NOTIFY 244
#define SN_MQ_GETSETATTR 245
#define SN_KEXEC_LOAD 246
#define SN_WAITID 247
#define SN_ADD_KEY 248
#define SN_REQUEST_KEY 249
#define SN_KEYCTL 250
#define SN_IOPRIO_SET 251
#define SN_IOPRIO_GET 252
#define SN_INOTIFY_INIT 253
#define SN_INOTIFY_ADD_WATCH 254
#define SN_INOTIFY_RM_WATCH 255
#define SN_MIGRATE_PAGES 256
#define SN_OPENAT 257
#define SN_MKDIRAT 258
#define SN_MKNODAT 259
#define SN_FCHOWNAT 260
#define SN_FUTIMESAT 261
#define SN_NEWFSTATAT 262
#define SN_UNLINKAT 263
#define SN_RENAMEAT 264
#define SN_LINKAT 265
#define SN_SYMLINKAT 266
#define SN_READLINKAT 267
#define SN_FCHMODAT 268
#define SN_FACCESSAT 269
#define SN_PSELECT6 270
#define SN_PPOLL 271
#define SN_UNSHARE 272
#define SN_SET_ROBUST_LIST 273
#define SN_GET_ROBUST_LIST 274
#define SN_SPLICE 275
#define SN_TEE 276
#define SN_SYNC_FILE_RANGE 277
#define SN_VMSPLICE 278
#define SN_MOVE_PAGES 279
#define SN_UTIMENSAT 280
#define SN_EPOLL_PWAIT 281
#define SN_SIGNALFD 282
#define SN_TIMERFD_CREATE 283
#define SN_EVENTFD 284
#define SN_FALLOCATE 285
#define SN_TIMERFD_SETTIME 286
#define SN_TIMERFD_GETTIME 287
#define SN_ACCEPT4 288
#define SN_SIGNALFD4 289
#define SN_EVENTFD2 290
#define SN_EPOLL_CREATE1 291
#define SN_DUP3 292
#define SN_PIPE2 293
#define SN_INOTIFY_INIT1 294
#define SN_PREADV 295
#define SN_PWRITEV 296
#define SN_RT_TGSIGQUEUEINFO 297
#define SN_PERF_EVENT_OPEN 298
#define SN_RECVMMSG 299
#define SN_FANOTIFY_INIT 300
#define SN_FANOTIFY_MARK 301
#define SN_PRLIMIT64 302
#define SN_NAME_TO_HANDLE_AT 303
#define SN_OPEN_BY_HANDLE_AT 304
#define SN_CLOCK_ADJTIME 305
#define SN_SYNCFS 306
#define SN_SENDMMSG 307
#define SN_SETNS 308
#define SN_GETCPU 309
#define SN_PROCESS_VM_READV 310
#define SN_PROCESS_VM_WRITEV 311
#define SN_KCMP 312

#include <stdint.h>
#include <stdbool.h>

LIBDLL_API int64_t syscall_msg(int64_t arg);

LIBDLL_API int64_t syscall_prv(
		int64_t func,
		int64_t arg0,
		int64_t arg1,
		int64_t arg2,
		int64_t arg3,
		int64_t arg4,
		int64_t arg5);

LIBDLL_API int64_t syscall0(
		int64_t func);

LIBDLL_API int64_t syscall1(
		int64_t func,
		int64_t arg0);

LIBDLL_API int64_t syscall2(
		int64_t func,
		int64_t arg0,
		int64_t arg1
		);

LIBDLL_API int64_t syscall3(
		int64_t func,
		int64_t arg0,
		int64_t arg1,
		int64_t arg2
		);

LIBDLL_API int64_t syscall4(
		int64_t func,
		int64_t arg0,
		int64_t arg1,
		int64_t arg2,
		int64_t arg3
		);

LIBDLL_API int64_t syscall5(
		int64_t func,
		int64_t arg0,
		int64_t arg1,
		int64_t arg2,
		int64_t arg3,
		int64_t arg4
		);

LIBDLL_API int64_t syscall6(
		int64_t func,
		int64_t arg0,
		int64_t arg1,
		int64_t arg2,
		int64_t arg3,
		int64_t arg4,
		int64_t arg5
		);

