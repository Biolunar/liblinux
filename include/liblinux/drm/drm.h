/*
 * Copyright 2018-2020 Mahdi Khanalizadeh
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef HEADER_LIBLINUX_DRM_DRM_H_INCLUDED
#define HEADER_LIBLINUX_DRM_DRM_H_INCLUDED

#include <stdint.h>

typedef unsigned int linux_drm_handle_t;

#define linux_DRM_NAME        "drm"
#define linux_DRM_MIN_ORDER    5
#define linux_DRM_MAX_ORDER   22
#define linux_DRM_RAM_PERCENT 10

#define linux_DRM_LOCK_HELD             0x80000000U
#define linux_DRM_LOCK_CONT             0x40000000U
#define linux_DRM_LOCK_IS_HELD(lock)    ((lock) & linux_DRM_LOCK_HELD)
#define linux_DRM_LOCK_IS_CONT(lock)    ((lock) & linux_DRM_LOCK_CONT)
#define linux_DRM_LOCKING_CONTEXT(lock) ((lock) & ~(linux_DRM_LOCK_HELD | linux_DRM_LOCK_CONT))

typedef unsigned int linux_drm_context_t;
typedef unsigned int linux_drm_drawable_t;
typedef unsigned int linux_drm_magic_t;

struct linux_drm_clip_rect
{
	unsigned short x1;
	unsigned short y1;
	unsigned short x2;
	unsigned short y2;
};

struct linux_drm_drawable_info
{
	unsigned int num_rects;
	struct linux_drm_clip_rect *rects;
};

struct linux_drm_tex_region
{
	unsigned char next;
	unsigned char prev;
	unsigned char in_use;
	unsigned char _padding;
	unsigned int age;
};

struct linux_drm_hw_lock
{
	unsigned int volatile lock;
	char _padding[60];
};

struct linux_drm_version
{
	int version_major;
	int version_minor;
	int version_patchlevel;
	linux_kernel_size_t name_len;
	char* name;
	linux_kernel_size_t date_len;
	char* date;
	linux_kernel_size_t desc_len;
	char* desc;
};

struct linux_drm_unique
{
	linux_kernel_size_t unique_len;
	char* unique;
};

struct linux_drm_list
{
	int count;
	struct linux_drm_version* version;
};

struct linux_drm_block
{
	int unused;
};

struct linux_drm_control
{
	enum
	{
		linux_DRM_ADD_COMMAND,
		linux_DRM_RM_COMMAND,
		linux_DRM_INST_HANDLER,
		linux_DRM_UNINST_HANDLER,
	} func;
	int irq;
};

enum linux_drm_map_type
{
	linux_DRM_FRAME_BUFFER   = 0,
	linux_DRM_REGISTERS      = 1,
	linux_DRM_SHM            = 2,
	linux_DRM_AGP            = 3,
	linux_DRM_SCATTER_GATHER = 4,
	linux_DRM_CONSISTENT     = 5,
};

enum linux_drm_map_flags
{
	linux_DRM_RESTRICTED      = 0x01,
	linux_DRM_READ_ONLY       = 0x02,
	linux_DRM_LOCKED          = 0x04,
	linux_DRM_KERNEL          = 0x08,
	linux_DRM_WRITE_COMBINING = 0x10,
	linux_DRM_CONTAINS_LOCK   = 0x20,
	linux_DRM_REMOVABLE       = 0x40,
	linux_DRM_DRIVER          = 0x80,
};

struct linux_drm_ctx_priv_map
{
	unsigned int ctx_id;
	void* handle;
};

struct linux_drm_map
{
	unsigned long offset;
	unsigned long size;
	enum linux_drm_map_type type;
	enum linux_drm_map_flags flags;
	void* handle;
	int mtrr;
};

struct linux_drm_client
{
	int idx;
	int auth;
	unsigned long pid;
	unsigned long uid;
	unsigned long magic;
	unsigned long iocs;
};

enum linux_drm_stat_type
{
	linux_DRM_STAT_LOCK,
	linux_DRM_STAT_OPENS,
	linux_DRM_STAT_CLOSES,
	linux_DRM_STAT_IOCTLS,
	linux_DRM_STAT_LOCKS,
	linux_DRM_STAT_UNLOCKS,
	linux_DRM_STAT_VALUE,
	linux_DRM_STAT_BYTE,
	linux_DRM_STAT_COUNT,

	linux_DRM_STAT_IRQ,
	linux_DRM_STAT_PRIMARY,
	linux_DRM_STAT_SECONDARY,
	linux_DRM_STAT_DMA,
	linux_DRM_STAT_SPECIAL,
	linux_DRM_STAT_MISSED,
};

struct linux_drm_stats
{
	unsigned long count;
	struct
	{
		unsigned long value;
		enum linux_drm_stat_type type;
	} data[15];
};

enum linux_drm_lock_flags
{
	linux_DRM_LOCK_READY      = 0x01,
	linux_DRM_LOCK_QUIESCENT  = 0x02,
	linux_DRM_LOCK_FLUSH      = 0x04,
	linux_DRM_LOCK_FLUSH_ALL  = 0x08,
	linux_DRM_HALT_ALL_QUEUES = 0x10,
	linux_DRM_HALT_CUR_QUEUES = 0x20,
};

struct linux_drm_lock
{
	int context;
	enum linux_drm_lock_flags flags;
};

enum linux_drm_dma_flags
{
	linux_DRM_DMA_BLOCK        = 0x01,
	linux_DRM_DMA_WHILE_LOCKED = 0x02,
	linux_DRM_DMA_PRIORITY     = 0x04,

	linux_DRM_DMA_WAIT         = 0x10,
	linux_DRM_DMA_SMALLER_OK   = 0x20,
	linux_DRM_DMA_LARGER_OK    = 0x40,
};

struct linux_drm_buf_desc
{
	int count;
	int size;
	int low_mark;
	int high_mark;
	enum
	{
		linux_DRM_PAGE_ALIGN    = 0x01,
		linux_DRM_AGP_BUFFER    = 0x02,
		linux_DRM_SG_BUFFER     = 0x04,
		linux_DRM_FB_BUFFER     = 0x08,
		linux_DRM_PCI_BUFFER_RO = 0x10,
	} flags;
	unsigned long agp_start;
};

struct linux_drm_buf_info
{
	int count;
	struct linux_drm_buf_desc* list;
};

struct linux_drm_buf_free
{
	int count;
	int* list;
};

struct linux_drm_buf_pub
{
	int idx;
	int total;
	int used;
	void* address;
};

struct linux_drm_buf_map
{
	int count;
	void* virtual;
	struct linux_drm_buf_pub* list;
};

struct linux_drm_dma
{
	int context;
	int send_count;
	int* send_indices;
	int* send_sizes;
	enum linux_drm_dma_flags flags;
	int request_count;
	int request_size;
	int* request_indices;
	int* request_sizes;
	int granted_count;
};

enum linux_drm_ctx_flags
{
	linux_DRM_CONTEXT_PRESERVED = 0x01,
	linux_DRM_CONTEXT_2DONLY    = 0x02,
};

struct linux_drm_ctx
{
	linux_drm_context_t handle;
	enum linux_drm_ctx_flags flags;
};

struct linux_drm_ctx_res
{
	int count;
	struct linux_drm_ctx* contexts;
};

struct linux_drm_draw
{
	linux_drm_drawable_t handle;
};

typedef enum
{
	linux_DRM_DRAWABLE_CLIPRECTS,
} linux_drm_drawable_info_type_t;

struct linux_drm_update_draw
{
	linux_drm_drawable_t handle;
	unsigned int type;
	unsigned int num;
	unsigned long long data;
};

struct linux_drm_auth
{
	linux_drm_magic_t magic;
};

struct linux_drm_irq_busid
{
	int irq;
	int busnum;
	int devnum;
	int funcnum;
};

enum linux_drm_vblank_seq_type
{
	DRM_VBLANK_ABSOLUTE       = 0x00000000,
	DRM_VBLANK_RELATIVE       = 0x00000001,

	DRM_VBLANK_HIGH_CRTC_MASK = 0x0000003e,
	DRM_VBLANK_EVENT          = 0x04000000,
	DRM_VBLANK_FLIP           = 0x08000000,
	DRM_VBLANK_NEXTONMISS     = 0x10000000,
	DRM_VBLANK_SECONDARY      = 0x20000000,
	DRM_VBLANK_SIGNAL         = 0x40000000,
};
#define linux_DRM_VBLANK_HIGH_CRTC_SHIFT 1

#define linux_DRM_VBLANK_TYPES_MASK (linux_DRM_VBLANK_ABSOLUTE | linux_DRM_VBLANK_RELATIVE)
#define linux_DRM_VBLANK_FLAGS_MASK (linux_DRM_VBLANK_EVENT | linux_DRM_VBLANK_SIGNAL | linux_DRM_VBLANK_SECONDARY | linux_DRM_VBLANK_NEXTONMISS)

struct linux_drm_wait_vblank_request
{
	enum linux_drm_vblank_seq_type type;
	unsigned int sequence;
	unsigned long signal;
};

struct linux_drm_wait_vblank_reply
{
	enum linux_drm_vblank_seq_type type;
	unsigned int sequence;
	long tval_sec;
	long tval_usec;
};

union linux_drm_wait_vblank
{
	struct linux_drm_wait_vblank_request request;
	struct linux_drm_wait_vblank_reply reply;
};

#define linux_DRM_PRE_MODESET  1
#define linux_DRM_POST_MODESET 2

struct linux_drm_modeset_ctl
{
	uint32_t crtc;
	uint32_t cmd;
};

struct linux_drm_agp_mode
{
	unsigned long mode;
};

struct linux_drm_agp_buffer
{
	unsigned long size;
	unsigned long handle;
	unsigned long type;
	unsigned long physical;
};

struct linux_drm_agp_binding
{
	unsigned long handle;
	unsigned long offset;
};

struct linux_drm_agp_info
{
	int agp_version_major;
	int agp_version_minor;
	unsigned long mode;
	unsigned long aperture_base;
	unsigned long aperture_size;
	unsigned long memory_allowed;
	unsigned long memory_used;
	unsigned short id_vendor;
	unsigned short id_device;
};

struct linux_drm_scatter_gather
{
	unsigned long size;
	unsigned long handle;
};

struct linux_drm_set_version
{
	int drm_di_major;
	int drm_di_minor;
	int drm_dd_major;
	int drm_dd_minor;
};

struct linux_drm_gem_close
{
	uint32_t handle;
	uint32_t _pad;
};

struct linux_drm_gem_flink
{
	uint32_t handle;
	uint32_t name;
};

struct linux_drm_gem_open
{
	uint32_t name;
	uint32_t handle;
	uint64_t size;
};

#define linux_DRM_CAP_DUMB_BUFFER          0x01
#define linux_DRM_CAP_VBLANK_HIGH_CRTC     0x02
#define linux_DRM_CAP_DUMB_PREFERRED_DEPTH 0x03
#define linux_DRM_CAP_DUMB_PREFER_SHADOW   0x04
#define linux_DRM_CAP_PRIME                0x05
#define linux_DRM_CAP_TIMESTAMP_MONOTONIC  0x06
#define linux_DRM_CAP_ASYNC_PAGE_FLIP      0x07
#define linux_DRM_CAP_CURSOR_WIDTH         0x08
#define linux_DRM_CAP_CURSOR_HEIGHT        0x09
#define linux_DRM_CAP_ADDFB2_MODIFIERS     0x10
#define linux_DRM_CAP_PAGE_FLIP_TARGET     0x11
#define linux_DRM_CAP_CRTC_IN_VBLANK_EVENT 0x12
#define linux_DRM_CAP_SYNCOBJ              0x13
#define linux_DRM_CAP_SYNCOBJ_TIMELINE     0x14

#define linux_DRM_PRIME_CAP_IMPORT 0x1
#define linux_DRM_PRIME_CAP_EXPORT 0x2

struct linux_drm_get_cap
{
	uint64_t capability;
	uint64_t value;
};

#define linux_DRM_CLIENT_CAP_STEREO_3D            1
#define linux_DRM_CLIENT_CAP_UNIVERSAL_PLANES     2
#define linux_DRM_CLIENT_CAP_ATOMIC               3
#define linux_DRM_CLIENT_CAP_ASPECT_RATIO         4
#define linux_DRM_CLIENT_CAP_WRITEBACK_CONNECTORS 5

struct linux_drm_set_client_cap
{
	uint64_t capability;
	uint64_t value;
};

#define linux_DRM_RDWR    linux_O_RDWR
#define linux_DRM_CLOEXEC linux_O_CLOEXEC
struct linux_drm_prime_handle
{
	uint32_t handle;
	uint32_t flags;
	int32_t fd;
};

struct linux_drm_syncobj_create
{
	uint32_t handle;
#define linux_DRM_SYNCOBJ_CREATE_SIGNALED (1 << 0)
	uint32_t flags;
};

struct linux_drm_syncobj_destroy
{
	uint32_t handle;
	uint32_t _pad;
};

#define linux_DRM_SYNCOBJ_FD_TO_HANDLE_FLAGS_IMPORT_SYNC_FILE (1 << 0)
#define linux_DRM_SYNCOBJ_HANDLE_TO_FD_FLAGS_EXPORT_SYNC_FILE (1 << 0)
struct linux_drm_syncobj_handle
{
	uint32_t handle;
	uint32_t flags;
	int32_t fd;
	uint32_t _pad;
};

struct linux_drm_syncobj_transfer
{
	uint32_t src_handle;
	uint32_t dst_handle;
	uint64_t src_point;
	uint64_t dst_point;
	uint32_t flags;
	uint32_t _pad;
};

#define linux_DRM_SYNCOBJ_WAIT_FLAGS_WAIT_ALL        (1 << 0)
#define linux_DRM_SYNCOBJ_WAIT_FLAGS_WAIT_FOR_SUBMIT (1 << 1)
#define linux_DRM_SYNCOBJ_WAIT_FLAGS_WAIT_AVAILABLE  (1 << 2)
struct linux_drm_syncobj_wait
{
	uint64_t handles;
	int64_t timeout_nsec;
	uint32_t count_handles;
	uint32_t flags;
	uint32_t first_signaled;
	uint32_t _pad;
};

struct linux_drm_syncobj_timeline_wait
{
	uint64_t handles;
	uint64_t points;
	int64_t timeout_nsec;
	uint32_t count_handles;
	uint32_t flags;
	uint32_t first_signaled;
	uint32_t _pad;
};

struct linux_drm_syncobj_array
{
	uint64_t handles;
	uint32_t count_handles;
	uint32_t _pad;
};

#define linux_DRM_SYNCOBJ_QUERY_FLAGS_LAST_SUBMITTED (1 << 0)
struct linux_drm_syncobj_timeline_array
{
	uint64_t handles;
	uint64_t points;
	uint32_t count_handles;
	uint32_t flags;
};

struct linux_drm_crtc_get_sequence
{
	uint32_t crtc_id;
	uint32_t active;
	uint64_t sequence;
	int64_t sequence_ns;
};

#define linux_DRM_CRTC_SEQUENCE_RELATIVE     0x00000001
#define linux_DRM_CRTC_SEQUENCE_NEXT_ON_MISS 0x00000002

struct linux_drm_crtc_queue_sequence
{
	uint32_t crtc_id;
	uint32_t flags;
	uint64_t sequence;
	uint64_t user_data;
};

#define linux_DRM_IOCTL_BASE                    'd'
#define linux_DRM_IO(nr)                        linux_IO(linux_DRM_IOCTL_BASE, nr)
#define linux_DRM_IOR(nr, type)                 linux_IOR(linux_DRM_IOCTL_BASE, nr, type)
#define linux_DRM_IOW(nr, type)                 linux_IOW(linux_DRM_IOCTL_BASE, nr, type)
#define linux_DRM_IOWR(nr, type)                linux_IOWR(linux_DRM_IOCTL_BASE, nr, type)

#define linux_DRM_IOCTL_VERSION                 linux_DRM_IOWR(0x00, struct linux_drm_version)
#define linux_DRM_IOCTL_GET_UNIQUE              linux_DRM_IOWR(0x01, struct linux_drm_unique)
#define linux_DRM_IOCTL_GET_MAGIC               linux_DRM_IOR( 0x02, struct linux_drm_auth)
#define linux_DRM_IOCTL_IRQ_BUSID               linux_DRM_IOWR(0x03, struct linux_drm_irq_busid)
#define linux_DRM_IOCTL_GET_MAP                 linux_DRM_IOWR(0x04, struct linux_drm_map)
#define linux_DRM_IOCTL_GET_CLIENT              linux_DRM_IOWR(0x05, struct linux_drm_client)
#define linux_DRM_IOCTL_GET_STATS               linux_DRM_IOR( 0x06, struct linux_drm_stats)
#define linux_DRM_IOCTL_SET_VERSION             linux_DRM_IOWR(0x07, struct linux_drm_set_version)
#define linux_DRM_IOCTL_MODESET_CTL             linux_DRM_IOW(0x08, struct linux_drm_modeset_ctl)
#define linux_DRM_IOCTL_GEM_CLOSE               linux_DRM_IOW (0x09, struct linux_drm_gem_close)
#define linux_DRM_IOCTL_GEM_FLINK               linux_DRM_IOWR(0x0a, struct linux_drm_gem_flink)
#define linux_DRM_IOCTL_GEM_OPEN                linux_DRM_IOWR(0x0b, struct linux_drm_gem_open)
#define linux_DRM_IOCTL_GET_CAP                 linux_DRM_IOWR(0x0c, struct linux_drm_get_cap)
#define linux_DRM_IOCTL_SET_CLIENT_CAP          linux_DRM_IOW( 0x0d, struct linux_drm_set_client_cap)

#define linux_DRM_IOCTL_SET_UNIQUE              linux_DRM_IOW( 0x10, struct linux_drm_unique)
#define linux_DRM_IOCTL_AUTH_MAGIC              linux_DRM_IOW( 0x11, struct linux_drm_auth)
#define linux_DRM_IOCTL_BLOCK                   linux_DRM_IOWR(0x12, struct linux_drm_block)
#define linux_DRM_IOCTL_UNBLOCK                 linux_DRM_IOWR(0x13, struct linux_drm_block)
#define linux_DRM_IOCTL_CONTROL                 linux_DRM_IOW( 0x14, struct linux_drm_control)
#define linux_DRM_IOCTL_ADD_MAP                 linux_DRM_IOWR(0x15, struct linux_drm_map)
#define linux_DRM_IOCTL_ADD_BUFS                linux_DRM_IOWR(0x16, struct linux_drm_buf_desc)
#define linux_DRM_IOCTL_MARK_BUFS               linux_DRM_IOW( 0x17, struct linux_drm_buf_desc)
#define linux_DRM_IOCTL_INFO_BUFS               linux_DRM_IOWR(0x18, struct linux_drm_buf_info)
#define linux_DRM_IOCTL_MAP_BUFS                linux_DRM_IOWR(0x19, struct linux_drm_buf_map)
#define linux_DRM_IOCTL_FREE_BUFS               linux_DRM_IOW( 0x1a, struct linux_drm_buf_free)

#define linux_DRM_IOCTL_RM_MAP                  linux_DRM_IOW( 0x1b, struct linux_drm_map)

#define linux_DRM_IOCTL_SET_SAREA_CTX           linux_DRM_IOW( 0x1c, struct linux_drm_ctx_priv_map)
#define linux_DRM_IOCTL_GET_SAREA_CTX           linux_DRM_IOWR(0x1d, struct linux_drm_ctx_priv_map)

#define linux_DRM_IOCTL_SET_MASTER              linux_DRM_IO(0x1e)
#define linux_DRM_IOCTL_DROP_MASTER             linux_DRM_IO(0x1f)

#define linux_DRM_IOCTL_ADD_CTX                 linux_DRM_IOWR(0x20, struct linux_drm_ctx)
#define linux_DRM_IOCTL_RM_CTX                  linux_DRM_IOWR(0x21, struct linux_drm_ctx)
#define linux_DRM_IOCTL_MOD_CTX                 linux_DRM_IOW( 0x22, struct linux_drm_ctx)
#define linux_DRM_IOCTL_GET_CTX                 linux_DRM_IOWR(0x23, struct linux_drm_ctx)
#define linux_DRM_IOCTL_SWITCH_CTX              linux_DRM_IOW( 0x24, struct linux_drm_ctx)
#define linux_DRM_IOCTL_NEW_CTX                 linux_DRM_IOW( 0x25, struct linux_drm_ctx)
#define linux_DRM_IOCTL_RES_CTX                 linux_DRM_IOWR(0x26, struct linux_drm_ctx_res)
#define linux_DRM_IOCTL_ADD_DRAW                linux_DRM_IOWR(0x27, struct linux_drm_draw)
#define linux_DRM_IOCTL_RM_DRAW                 linux_DRM_IOWR(0x28, struct linux_drm_draw)
#define linux_DRM_IOCTL_DMA                     linux_DRM_IOWR(0x29, struct linux_drm_dma)
#define linux_DRM_IOCTL_LOCK                    linux_DRM_IOW( 0x2a, struct linux_drm_lock)
#define linux_DRM_IOCTL_UNLOCK                  linux_DRM_IOW( 0x2b, struct linux_drm_lock)
#define linux_DRM_IOCTL_FINISH                  linux_DRM_IOW( 0x2c, struct linux_drm_lock)

#define linux_DRM_IOCTL_PRIME_HANDLE_TO_FD      linux_DRM_IOWR(0x2d, struct linux_drm_prime_handle)
#define linux_DRM_IOCTL_PRIME_FD_TO_HANDLE      linux_DRM_IOWR(0x2e, struct linux_drm_prime_handle)

#define linux_DRM_IOCTL_AGP_ACQUIRE             linux_DRM_IO(  0x30)
#define linux_DRM_IOCTL_AGP_RELEASE             linux_DRM_IO(  0x31)
#define linux_DRM_IOCTL_AGP_ENABLE              linux_DRM_IOW( 0x32, struct linux_drm_agp_mode)
#define linux_DRM_IOCTL_AGP_INFO                linux_DRM_IOR( 0x33, struct linux_drm_agp_info)
#define linux_DRM_IOCTL_AGP_ALLOC               linux_DRM_IOWR(0x34, struct linux_drm_agp_buffer)
#define linux_DRM_IOCTL_AGP_FREE                linux_DRM_IOW( 0x35, struct linux_drm_agp_buffer)
#define linux_DRM_IOCTL_AGP_BIND                linux_DRM_IOW( 0x36, struct linux_drm_agp_binding)
#define linux_DRM_IOCTL_AGP_UNBIND              linux_DRM_IOW( 0x37, struct linux_drm_agp_binding)

#define linux_DRM_IOCTL_SG_ALLOC                linux_DRM_IOWR(0x38, struct linux_drm_scatter_gather)
#define linux_DRM_IOCTL_SG_FREE                 linux_DRM_IOW( 0x39, struct linux_drm_scatter_gather)

#define linux_DRM_IOCTL_WAIT_VBLANK             linux_DRM_IOWR(0x3a, union linux_drm_wait_vblank)

#define linux_DRM_IOCTL_CRTC_GET_SEQUENCE       linux_DRM_IOWR(0x3b, struct linux_drm_crtc_get_sequence)
#define linux_DRM_IOCTL_CRTC_QUEUE_SEQUENCE     linux_DRM_IOWR(0x3c, struct linux_drm_crtc_queue_sequence)

#define linux_DRM_IOCTL_UPDATE_DRAW             linux_DRM_IOW(0x3f, struct linux_drm_update_draw)

#define linux_DRM_IOCTL_MODE_GETRESOURCES       linux_DRM_IOWR(0xA0, struct linux_drm_mode_card_res)
#define linux_DRM_IOCTL_MODE_GETCRTC            linux_DRM_IOWR(0xA1, struct linux_drm_mode_crtc)
#define linux_DRM_IOCTL_MODE_SETCRTC            linux_DRM_IOWR(0xA2, struct linux_drm_mode_crtc)
#define linux_DRM_IOCTL_MODE_CURSOR             linux_DRM_IOWR(0xA3, struct linux_drm_mode_cursor)
#define linux_DRM_IOCTL_MODE_GETGAMMA           linux_DRM_IOWR(0xA4, struct linux_drm_mode_crtc_lut)
#define linux_DRM_IOCTL_MODE_SETGAMMA           linux_DRM_IOWR(0xA5, struct linux_drm_mode_crtc_lut)
#define linux_DRM_IOCTL_MODE_GETENCODER         linux_DRM_IOWR(0xA6, struct linux_drm_mode_get_encoder)
#define linux_DRM_IOCTL_MODE_GETCONNECTOR       linux_DRM_IOWR(0xA7, struct linux_drm_mode_get_connector)
#define linux_DRM_IOCTL_MODE_ATTACHMODE         linux_DRM_IOWR(0xA8, struct linux_drm_mode_mode_cmd)
#define linux_DRM_IOCTL_MODE_DETACHMODE         linux_DRM_IOWR(0xA9, struct linux_drm_mode_mode_cmd)

#define linux_DRM_IOCTL_MODE_GETPROPERTY        linux_DRM_IOWR(0xAA, struct linux_drm_mode_get_property)
#define linux_DRM_IOCTL_MODE_SETPROPERTY        linux_DRM_IOWR(0xAB, struct linux_drm_mode_connector_set_property)
#define linux_DRM_IOCTL_MODE_GETPROPBLOB        linux_DRM_IOWR(0xAC, struct linux_drm_mode_get_blob)
#define linux_DRM_IOCTL_MODE_GETFB              linux_DRM_IOWR(0xAD, struct linux_drm_mode_fb_cmd)
#define linux_DRM_IOCTL_MODE_ADDFB              linux_DRM_IOWR(0xAE, struct linux_drm_mode_fb_cmd)
#define linux_DRM_IOCTL_MODE_RMFB               linux_DRM_IOWR(0xAF, unsigned int)
#define linux_DRM_IOCTL_MODE_PAGE_FLIP          linux_DRM_IOWR(0xB0, struct linux_drm_mode_crtc_page_flip)
#define linux_DRM_IOCTL_MODE_DIRTYFB            linux_DRM_IOWR(0xB1, struct linux_drm_mode_fb_dirty_cmd)

#define linux_DRM_IOCTL_MODE_CREATE_DUMB        linux_DRM_IOWR(0xB2, struct linux_drm_mode_create_dumb)
#define linux_DRM_IOCTL_MODE_MAP_DUMB           linux_DRM_IOWR(0xB3, struct linux_drm_mode_map_dumb)
#define linux_DRM_IOCTL_MODE_DESTROY_DUMB       linux_DRM_IOWR(0xB4, struct linux_drm_mode_destroy_dumb)
#define linux_DRM_IOCTL_MODE_GETPLANERESOURCES  linux_DRM_IOWR(0xB5, struct linux_drm_mode_get_plane_res)
#define linux_DRM_IOCTL_MODE_GETPLANE           linux_DRM_IOWR(0xB6, struct linux_drm_mode_get_plane)
#define linux_DRM_IOCTL_MODE_SETPLANE           linux_DRM_IOWR(0xB7, struct linux_drm_mode_set_plane)
#define linux_DRM_IOCTL_MODE_ADDFB2             linux_DRM_IOWR(0xB8, struct linux_drm_mode_fb_cmd2)
#define linux_DRM_IOCTL_MODE_OBJ_GETPROPERTIES  linux_DRM_IOWR(0xB9, struct linux_drm_mode_obj_get_properties)
#define linux_DRM_IOCTL_MODE_OBJ_SETPROPERTY    linux_DRM_IOWR(0xBA, struct linux_drm_mode_obj_set_property)
#define linux_DRM_IOCTL_MODE_CURSOR2            linux_DRM_IOWR(0xBB, struct linux_drm_mode_cursor2)
#define linux_DRM_IOCTL_MODE_ATOMIC             linux_DRM_IOWR(0xBC, struct linux_drm_mode_atomic)
#define linux_DRM_IOCTL_MODE_CREATEPROPBLOB     linux_DRM_IOWR(0xBD, struct linux_drm_mode_create_blob)
#define linux_DRM_IOCTL_MODE_DESTROYPROPBLOB    linux_DRM_IOWR(0xBE, struct linux_drm_mode_destroy_blob)

#define linux_DRM_IOCTL_SYNCOBJ_CREATE          linux_DRM_IOWR(0xBF, struct linux_drm_syncobj_create)
#define linux_DRM_IOCTL_SYNCOBJ_DESTROY         linux_DRM_IOWR(0xC0, struct linux_drm_syncobj_destroy)
#define linux_DRM_IOCTL_SYNCOBJ_HANDLE_TO_FD    linux_DRM_IOWR(0xC1, struct linux_drm_syncobj_handle)
#define linux_DRM_IOCTL_SYNCOBJ_FD_TO_HANDLE    linux_DRM_IOWR(0xC2, struct linux_drm_syncobj_handle)
#define linux_DRM_IOCTL_SYNCOBJ_WAIT            linux_DRM_IOWR(0xC3, struct linux_drm_syncobj_wait)
#define linux_DRM_IOCTL_SYNCOBJ_RESET           linux_DRM_IOWR(0xC4, struct linux_drm_syncobj_array)
#define linux_DRM_IOCTL_SYNCOBJ_SIGNAL          linux_DRM_IOWR(0xC5, struct linux_drm_syncobj_array)

#define linux_DRM_IOCTL_MODE_CREATE_LEASE       linux_DRM_IOWR(0xC6, struct linux_drm_mode_create_lease)
#define linux_DRM_IOCTL_MODE_LIST_LESSEES       linux_DRM_IOWR(0xC7, struct linux_drm_mode_list_lessees)
#define linux_DRM_IOCTL_MODE_GET_LEASE          linux_DRM_IOWR(0xC8, struct linux_drm_mode_get_lease)
#define linux_DRM_IOCTL_MODE_REVOKE_LEASE       linux_DRM_IOWR(0xC9, struct linux_drm_mode_revoke_lease)

#define linux_DRM_IOCTL_SYNCOBJ_TIMELINE_WAIT   linux_DRM_IOWR(0xCA, struct linux_drm_syncobj_timeline_wait)
#define linux_DRM_IOCTL_SYNCOBJ_QUERY           linux_DRM_IOWR(0xCB, struct linux_drm_syncobj_timeline_array)
#define linux_DRM_IOCTL_SYNCOBJ_TRANSFER        linux_DRM_IOWR(0xCC, struct linux_drm_syncobj_transfer)
#define linux_DRM_IOCTL_SYNCOBJ_TIMELINE_SIGNAL linux_DRM_IOWR(0xCD, struct linux_drm_syncobj_timeline_array)

#define linux_DRM_COMMAND_BASE 0x40
#define linux_DRM_COMMAND_END  0xA0

struct linux_drm_event
{
	uint32_t type;
	uint32_t length;
};

#define linux_DRM_EVENT_VBLANK        0x01
#define linux_DRM_EVENT_FLIP_COMPLETE 0x02
#define linux_DRM_EVENT_CRTC_SEQUENCE 0x03

struct linux_drm_event_vblank
{
	struct linux_drm_event base;
	uint64_t user_data;
	uint32_t tv_sec;
	uint32_t tv_usec;
	uint32_t sequence;
	uint32_t crtc_id;
};

struct linux_drm_event_crtc_sequence
{
	struct linux_drm_event base;
	uint64_t user_data;
	int64_t time_ns;
	uint64_t sequence;
};

typedef struct linux_drm_clip_rect     linux_drm_clip_rect_t;
typedef struct linux_drm_drawable_info linux_drm_drawable_info_t;
typedef struct linux_drm_tex_region    linux_drm_tex_region_t;
typedef struct linux_drm_hw_lock       linux_drm_hw_lock_t;
typedef struct linux_drm_version       linux_drm_version_t;
typedef struct linux_drm_unique        linux_drm_unique_t;
typedef struct linux_drm_list          linux_drm_list_t;
typedef struct linux_drm_block         linux_drm_block_t;
typedef struct linux_drm_control       linux_drm_control_t;
typedef enum linux_drm_map_type        linux_drm_map_type_t;
typedef enum linux_drm_map_flags       linux_drm_map_flags_t;
typedef struct linux_drm_ctx_priv_map  linux_drm_ctx_priv_map_t;
typedef struct linux_drm_map           linux_drm_map_t;
typedef struct linux_drm_client        linux_drm_client_t;
typedef enum linux_drm_stat_type       linux_drm_stat_type_t;
typedef struct linux_drm_stats         linux_drm_stats_t;
typedef enum linux_drm_lock_flags      linux_drm_lock_flags_t;
typedef struct linux_drm_lock          linux_drm_lock_t;
typedef enum linux_drm_dma_flags       linux_drm_dma_flags_t;
typedef struct linux_drm_buf_desc      linux_drm_buf_desc_t;
typedef struct linux_drm_buf_info      linux_drm_buf_info_t;
typedef struct linux_drm_buf_free      linux_drm_buf_free_t;
typedef struct linux_drm_buf_pub       linux_drm_buf_pub_t;
typedef struct linux_drm_buf_map       linux_drm_buf_map_t;
typedef struct linux_drm_dma           linux_drm_dma_t;
typedef union linux_drm_wait_vblank    linux_drm_wait_vblank_t;
typedef struct linux_drm_agp_mode      linux_drm_agp_mode_t;
typedef enum linux_drm_ctx_flags       linux_drm_ctx_flags_t;
typedef struct linux_drm_ctx           linux_drm_ctx_t;
typedef struct linux_drm_ctx_res       linux_drm_ctx_res_t;
typedef struct linux_drm_draw          linux_drm_draw_t;
typedef struct linux_drm_update_draw   linux_drm_update_draw_t;
typedef struct linux_drm_auth          linux_drm_auth_t;
typedef struct linux_drm_irq_busid     linux_drm_irq_busid_t;
typedef enum linux_drm_vblank_seq_type linux_drm_vblank_seq_type_t;

typedef struct linux_drm_agp_buffer     linux_drm_agp_buffer_t;
typedef struct linux_drm_agp_binding    linux_drm_agp_binding_t;
typedef struct linux_drm_agp_info       linux_drm_agp_info_t;
typedef struct linux_drm_scatter_gather linux_drm_scatter_gather_t;
typedef struct linux_drm_set_version    linux_drm_set_version_t;

#endif // !HEADER_LIBLINUX_DRM_DRM_H_INCLUDED
