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

#ifndef HEADER_LIBLINUX_DRM_DRM_MODE_H_INCLUDED
#define HEADER_LIBLINUX_DRM_DRM_MODE_H_INCLUDED

#include <stdint.h>

#define linux_DRM_CONNECTOR_NAME_LEN 32
#define linux_DRM_DISPLAY_MODE_LEN   32
#define linux_DRM_PROP_NAME_LEN      32

#define linux_DRM_MODE_TYPE_BUILTIN   (1 << 0)
#define linux_DRM_MODE_TYPE_CLOCK_C   ((1 << 1) | linux_DRM_MODE_TYPE_BUILTIN)
#define linux_DRM_MODE_TYPE_CRTC_C    ((1 << 2) | linux_DRM_MODE_TYPE_BUILTIN)
#define linux_DRM_MODE_TYPE_PREFERRED (1 << 3)
#define linux_DRM_MODE_TYPE_DEFAULT   (1 << 4)
#define linux_DRM_MODE_TYPE_USERDEF   (1 << 5)
#define linux_DRM_MODE_TYPE_DRIVER    (1 << 6)

#define linux_DRM_MODE_TYPE_ALL (linux_DRM_MODE_TYPE_PREFERRED | linux_DRM_MODE_TYPE_USERDEF | linux_DRM_MODE_TYPE_DRIVER)

#define linux_DRM_MODE_FLAG_PHSYNC                    (1 <<  0)
#define linux_DRM_MODE_FLAG_NHSYNC                    (1 <<  1)
#define linux_DRM_MODE_FLAG_PVSYNC                    (1 <<  2)
#define linux_DRM_MODE_FLAG_NVSYNC                    (1 <<  3)
#define linux_DRM_MODE_FLAG_INTERLACE                 (1 <<  4)
#define linux_DRM_MODE_FLAG_DBLSCAN                   (1 <<  5)
#define linux_DRM_MODE_FLAG_CSYNC                     (1 <<  6)
#define linux_DRM_MODE_FLAG_PCSYNC                    (1 <<  7)
#define linux_DRM_MODE_FLAG_NCSYNC                    (1 <<  8)
#define linux_DRM_MODE_FLAG_HSKEW                     (1 <<  9)
#define linux_DRM_MODE_FLAG_BCAST                     (1 << 10)
#define linux_DRM_MODE_FLAG_PIXMUX                    (1 << 11)
#define linux_DRM_MODE_FLAG_DBLCLK                    (1 << 12)
#define linux_DRM_MODE_FLAG_CLKDIV2                   (1 << 13)
#define linux_DRM_MODE_FLAG_3D_MASK                   (0x1f << 14)

#define linux_DRM_MODE_FLAG_3D_NONE                  (0 << 14)
#define linux_DRM_MODE_FLAG_3D_FRAME_PACKING         (1 << 14)
#define linux_DRM_MODE_FLAG_3D_FIELD_ALTERNATIVE     (2 << 14)
#define linux_DRM_MODE_FLAG_3D_LINE_ALTERNATIVE      (3 << 14)
#define linux_DRM_MODE_FLAG_3D_SIDE_BY_SIDE_FULL     (4 << 14)
#define linux_DRM_MODE_FLAG_3D_L_DEPTH               (5 << 14)
#define linux_DRM_MODE_FLAG_3D_L_DEPTH_GFX_GFX_DEPTH (6 << 14)
#define linux_DRM_MODE_FLAG_3D_TOP_AND_BOTTOM        (7 << 14)
#define linux_DRM_MODE_FLAG_3D_SIDE_BY_SIDE_HALF     (8 << 14)

#define linux_DRM_MODE_PICTURE_ASPECT_NONE    0
#define linux_DRM_MODE_PICTURE_ASPECT_4_3     1
#define linux_DRM_MODE_PICTURE_ASPECT_16_9    2
#define linux_DRM_MODE_PICTURE_ASPECT_64_27   3
#define linux_DRM_MODE_PICTURE_ASPECT_256_135 4

#define linux_DRM_MODE_CONTENT_TYPE_NO_DATA  0
#define linux_DRM_MODE_CONTENT_TYPE_GRAPHICS 1
#define linux_DRM_MODE_CONTENT_TYPE_PHOTO    2
#define linux_DRM_MODE_CONTENT_TYPE_CINEMA   3
#define linux_DRM_MODE_CONTENT_TYPE_GAME     4

#define linux_DRM_MODE_FLAG_PIC_AR_MASK (0x0F << 19)

#define linux_DRM_MODE_FLAG_PIC_AR_NONE    (linux_DRM_MODE_PICTURE_ASPECT_NONE    << 19)
#define linux_DRM_MODE_FLAG_PIC_AR_4_3     (linux_DRM_MODE_PICTURE_ASPECT_4_3     << 19)
#define linux_DRM_MODE_FLAG_PIC_AR_16_9    (linux_DRM_MODE_PICTURE_ASPECT_16_9    << 19)
#define linux_DRM_MODE_FLAG_PIC_AR_64_27   (linux_DRM_MODE_PICTURE_ASPECT_64_27   << 19)
#define linux_DRM_MODE_FLAG_PIC_AR_256_135 (linux_DRM_MODE_PICTURE_ASPECT_256_135 << 19)
#define linux_DRM_MODE_FLAG_ALL            (linux_DRM_MODE_FLAG_PHSYNC    | \
                                            linux_DRM_MODE_FLAG_NHSYNC    | \
                                            linux_DRM_MODE_FLAG_PVSYNC    | \
                                            linux_DRM_MODE_FLAG_NVSYNC    | \
                                            linux_DRM_MODE_FLAG_INTERLACE | \
                                            linux_DRM_MODE_FLAG_DBLSCAN   | \
                                            linux_DRM_MODE_FLAG_CSYNC     | \
                                            linux_DRM_MODE_FLAG_PCSYNC    | \
                                            linux_DRM_MODE_FLAG_NCSYNC    | \
                                            linux_DRM_MODE_FLAG_HSKEW     | \
                                            linux_DRM_MODE_FLAG_DBLCLK    | \
                                            linux_DRM_MODE_FLAG_CLKDIV2   | \
                                            linux_DRM_MODE_FLAG_3D_MASK)

#define linux_DRM_MODE_DPMS_ON      0
#define linux_DRM_MODE_DPMS_STANDBY 1
#define linux_DRM_MODE_DPMS_SUSPEND 2
#define linux_DRM_MODE_DPMS_OFF     3

#define linux_DRM_MODE_SCALE_NONE       0
#define linux_DRM_MODE_SCALE_FULLSCREEN 1
#define linux_DRM_MODE_SCALE_CENTER     2
#define linux_DRM_MODE_SCALE_ASPECT     3

#define linux_DRM_MODE_DITHERING_OFF  0
#define linux_DRM_MODE_DITHERING_ON   1
#define linux_DRM_MODE_DITHERING_AUTO 2

#define linux_DRM_MODE_DIRTY_OFF      0
#define linux_DRM_MODE_DIRTY_ON       1
#define linux_DRM_MODE_DIRTY_ANNOTATE 2

#define linux_DRM_MODE_LINK_STATUS_GOOD 0
#define linux_DRM_MODE_LINK_STATUS_BAD  1

#define linux_DRM_MODE_ROTATE_0   (1 << 0)
#define linux_DRM_MODE_ROTATE_90  (1 << 1)
#define linux_DRM_MODE_ROTATE_180 (1 << 2)
#define linux_DRM_MODE_ROTATE_270 (1 << 3)

#define linux_DRM_MODE_ROTATE_MASK (linux_DRM_MODE_ROTATE_0 | linux_DRM_MODE_ROTATE_90 | linux_DRM_MODE_ROTATE_180 | linux_DRM_MODE_ROTATE_270)

#define linux_DRM_MODE_REFLECT_X (1 << 4)
#define linux_DRM_MODE_REFLECT_Y (1 << 5)

#define linux_DRM_MODE_REFLECT_MASK (linux_DRM_MODE_REFLECT_X | linux_DRM_MODE_REFLECT_Y)

#define linux_DRM_MODE_CONTENT_PROTECTION_UNDESIRED 0
#define linux_DRM_MODE_CONTENT_PROTECTION_DESIRED   1
#define linux_DRM_MODE_CONTENT_PROTECTION_ENABLED   2

struct linux_drm_mode_modeinfo
{
	uint32_t clock;
	uint16_t hdisplay;
	uint16_t hsync_start;
	uint16_t hsync_end;
	uint16_t htotal;
	uint16_t hskew;
	uint16_t vdisplay;
	uint16_t vsync_start;
	uint16_t vsync_end;
	uint16_t vtotal;
	uint16_t vscan;
	uint32_t vrefresh;
	uint32_t flags;
	uint32_t type;
	char name[linux_DRM_DISPLAY_MODE_LEN];
};

struct linux_drm_mode_card_res
{
	uint64_t fb_id_ptr;
	uint64_t crtc_id_ptr;
	uint64_t connector_id_ptr;
	uint64_t encoder_id_ptr;
	uint32_t count_fbs;
	uint32_t count_crtcs;
	uint32_t count_connectors;
	uint32_t count_encoders;
	uint32_t min_width;
	uint32_t max_width;
	uint32_t min_height;
	uint32_t max_height;
};

struct linux_drm_mode_crtc
{
	uint64_t set_connectors_ptr;
	uint32_t count_connectors;
	uint32_t crtc_id;
	uint32_t fb_id;
	uint32_t x;
	uint32_t y;
	uint32_t gamma_size;
	uint32_t mode_valid;
	struct linux_drm_mode_modeinfo mode;
};

#define linux_DRM_MODE_PRESENT_TOP_FIELD    (1 << 0)
#define linux_DRM_MODE_PRESENT_BOTTOM_FIELD (1 << 1)

struct linux_drm_mode_set_plane
{
	uint32_t plane_id;
	uint32_t crtc_id;
	uint32_t fb_id;
	uint32_t flags;
	int32_t crtc_x;
	int32_t crtc_y;
	uint32_t crtc_w;
	uint32_t crtc_h;
	uint32_t src_x;
	uint32_t src_y;
	uint32_t src_h;
	uint32_t src_w;
};

struct linux_drm_mode_get_plane
{
	uint32_t plane_id;
	uint32_t crtc_id;
	uint32_t fb_id;
	uint32_t possible_crtcs;
	uint32_t gamma_size;
	uint32_t count_format_types;
	uint64_t format_type_ptr;
};

struct linux_drm_mode_get_plane_res
{
	uint64_t plane_id_ptr;
	uint32_t count_planes;
};

#define linux_DRM_MODE_ENCODER_NONE    0
#define linux_DRM_MODE_ENCODER_DAC     1
#define linux_DRM_MODE_ENCODER_TMDS    2
#define linux_DRM_MODE_ENCODER_LVDS    3
#define linux_DRM_MODE_ENCODER_TVDAC   4
#define linux_DRM_MODE_ENCODER_VIRTUAL 5
#define linux_DRM_MODE_ENCODER_DSI     6
#define linux_DRM_MODE_ENCODER_DPMST   7
#define linux_DRM_MODE_ENCODER_DPI     8

struct linux_drm_mode_get_encoder
{
	uint32_t encoder_id;
	uint32_t encoder_type;
	uint32_t crtc_id;
	uint32_t possible_crtcs;
	uint32_t possible_clones;
};

enum linux_drm_mode_subconnector
{
	linux_DRM_MODE_SUBCONNECTOR_Automatic = 0,
	linux_DRM_MODE_SUBCONNECTOR_Unknown   = 0,
	linux_DRM_MODE_SUBCONNECTOR_DVID      = 3,
	linux_DRM_MODE_SUBCONNECTOR_DVIA      = 4,
	linux_DRM_MODE_SUBCONNECTOR_Composite = 5,
	linux_DRM_MODE_SUBCONNECTOR_SVIDEO    = 6,
	linux_DRM_MODE_SUBCONNECTOR_Component = 8,
	linux_DRM_MODE_SUBCONNECTOR_SCART     = 9,
};

#define linux_DRM_MODE_CONNECTOR_Unknown      0
#define linux_DRM_MODE_CONNECTOR_VGA          1
#define linux_DRM_MODE_CONNECTOR_DVII         2
#define linux_DRM_MODE_CONNECTOR_DVID         3
#define linux_DRM_MODE_CONNECTOR_DVIA         4
#define linux_DRM_MODE_CONNECTOR_Composite    5
#define linux_DRM_MODE_CONNECTOR_SVIDEO       6
#define linux_DRM_MODE_CONNECTOR_LVDS         7
#define linux_DRM_MODE_CONNECTOR_Component    8
#define linux_DRM_MODE_CONNECTOR_9PinDIN      9
#define linux_DRM_MODE_CONNECTOR_DisplayPort 10
#define linux_DRM_MODE_CONNECTOR_HDMIA       11
#define linux_DRM_MODE_CONNECTOR_HDMIB       12
#define linux_DRM_MODE_CONNECTOR_TV          13
#define linux_DRM_MODE_CONNECTOR_eDP         14
#define linux_DRM_MODE_CONNECTOR_VIRTUAL     15
#define linux_DRM_MODE_CONNECTOR_DSI         16
#define linux_DRM_MODE_CONNECTOR_DPI         17
#define linux_DRM_MODE_CONNECTOR_WRITEBACK   18
#define linux_DRM_MODE_CONNECTOR_SPI         19

struct linux_drm_mode_get_connector
{
	uint64_t encoders_ptr;
	uint64_t modes_ptr;
	uint64_t props_ptr;
	uint64_t prop_values_ptr;
	uint32_t count_modes;
	uint32_t count_props;
	uint32_t count_encoders;
	uint32_t encoder_id;
	uint32_t connector_id;
	uint32_t connector_type;
	uint32_t connector_type_id;
	uint32_t connection;
	uint32_t mm_width;
	uint32_t mm_height;
	uint32_t subpixel;
	uint32_t _pad;
};

#define linux_DRM_MODE_PROP_PENDING   (1 << 0)
#define linux_DRM_MODE_PROP_RANGE     (1 << 1)
#define linux_DRM_MODE_PROP_IMMUTABLE (1 << 2)
#define linux_DRM_MODE_PROP_ENUM      (1 << 3)
#define linux_DRM_MODE_PROP_BLOB      (1 << 4)
#define linux_DRM_MODE_PROP_BITMASK   (1 << 5)

#define linux_DRM_MODE_PROP_LEGACY_TYPE (linux_DRM_MODE_PROP_RANGE | \
                                         linux_DRM_MODE_PROP_ENUM  | \
                                         linux_DRM_MODE_PROP_BLOB  | \
                                         linux_DRM_MODE_PROP_BITMASK)

#define linux_DRM_MODE_PROP_EXTENDED_TYPE 0x0000ffc0
#define linux_DRM_MODE_PROP_TYPE(n)       ((n) << 6)
#define linux_DRM_MODE_PROP_OBJECT        linux_DRM_MODE_PROP_TYPE(1)
#define linux_DRM_MODE_PROP_SIGNED_RANGE  linux_DRM_MODE_PROP_TYPE(2)
#define linux_DRM_MODE_PROP_ATOMIC        0x80000000

struct linux_drm_mode_property_enum
{
	uint64_t value;
	char name[linux_DRM_PROP_NAME_LEN];
};

struct linux_drm_mode_get_property
{
	uint64_t values_ptr;
	uint64_t enum_blob_ptr;
	uint32_t prop_id;
	uint32_t flags;
	char name[linux_DRM_PROP_NAME_LEN];
	uint32_t count_values;
	uint32_t count_enum_blobs;
};

struct linux_drm_mode_connector_set_property
{
	uint64_t value;
	uint32_t prop_id;
	uint32_t connector_id;
};

#define linux_DRM_MODE_OBJECT_CRTC      0xcccccccc
#define linux_DRM_MODE_OBJECT_CONNECTOR 0xc0c0c0c0
#define linux_DRM_MODE_OBJECT_ENCODER   0xe0e0e0e0
#define linux_DRM_MODE_OBJECT_MODE      0xdededede
#define linux_DRM_MODE_OBJECT_PROPERTY  0xb0b0b0b0
#define linux_DRM_MODE_OBJECT_FB        0xfbfbfbfb
#define linux_DRM_MODE_OBJECT_BLOB      0xbbbbbbbb
#define linux_DRM_MODE_OBJECT_PLANE     0xeeeeeeee
#define linux_DRM_MODE_OBJECT_ANY       0

struct linux_drm_mode_obj_get_properties
{
	uint64_t props_ptr;
	uint64_t prop_values_ptr;
	uint32_t count_props;
	uint32_t obj_id;
	uint32_t obj_type;
};

struct linux_drm_mode_obj_set_property
{
	uint64_t value;
	uint32_t prop_id;
	uint32_t obj_id;
	uint32_t obj_type;
};

struct linux_drm_mode_get_blob
{
	uint32_t blob_id;
	uint32_t length;
	uint64_t data;
};

struct linux_drm_mode_fb_cmd
{
	uint32_t fb_id;
	uint32_t width;
	uint32_t height;
	uint32_t pitch;
	uint32_t bpp;
	uint32_t depth;
	uint32_t handle;
};

#define linux_DRM_MODE_FB_INTERLACED (1 << 0)
#define linux_DRM_MODE_FB_MODIFIERS  (1 << 1)

struct linux_drm_mode_fb_cmd2
{
	uint32_t fb_id;
	uint32_t width;
	uint32_t height;
	uint32_t pixel_format;
	uint32_t flags;
	uint32_t handles[4];
	uint32_t pitches[4];
	uint32_t offsets[4];
	uint64_t modifier[4];
};

#define linux_DRM_MODE_FB_DIRTY_ANNOTATE_COPY 0x01
#define linux_DRM_MODE_FB_DIRTY_ANNOTATE_FILL 0x02
#define linux_DRM_MODE_FB_DIRTY_FLAGS         0x03
#define linux_DRM_MODE_FB_DIRTY_MAX_CLIPS     256

struct linux_drm_mode_fb_dirty_cmd
{
	uint32_t fb_id;
	uint32_t flags;
	uint32_t color;
	uint32_t num_clips;
	uint64_t clips_ptr;
};

struct linux_drm_mode_mode_cmd
{
	uint32_t connector_id;
	struct linux_drm_mode_modeinfo mode;
};

#define linux_DRM_MODE_CURSOR_BO    0x01
#define linux_DRM_MODE_CURSOR_MOVE  0x02
#define linux_DRM_MODE_CURSOR_FLAGS 0x03

struct linux_drm_mode_cursor
{
	uint32_t flags;
	uint32_t crtc_id;
	int32_t x;
	int32_t y;
	uint32_t width;
	uint32_t height;
	uint32_t handle;
};

struct linux_drm_mode_cursor2
{
	uint32_t flags;
	uint32_t crtc_id;
	int32_t x;
	int32_t y;
	uint32_t width;
	uint32_t height;
	uint32_t handle;
	int32_t hot_x;
	int32_t hot_y;
};

struct linux_drm_mode_crtc_lut
{
	uint32_t crtc_id;
	uint32_t gamma_size;
	uint64_t red;
	uint64_t green;
	uint64_t blue;
};

struct linux_drm_color_ctm
{
	uint64_t matrix[9];
};

struct linux_drm_color_lut
{
	uint16_t red;
	uint16_t green;
	uint16_t blue;
	uint16_t reserved;
};

struct linux_hdr_metadata_infoframe
{
	uint8_t eotf;
	uint8_t metadata_type;
	struct
	{
		uint16_t x, y;
	} display_primaries[3];
	struct
	{
		uint16_t x, y;
	} white_point;
	uint16_t max_display_mastering_luminance;
	uint16_t min_display_mastering_luminance;
	uint16_t max_cll;
	uint16_t max_fall;
};

struct linux_hdr_output_metadata
{
	uint32_t metadata_type;
	union
	{
		struct linux_hdr_metadata_infoframe hdmi_metadata_type1;
	};
};

#define linux_DRM_MODE_PAGE_FLIP_EVENT           0x01
#define linux_DRM_MODE_PAGE_FLIP_ASYNC           0x02
#define linux_DRM_MODE_PAGE_FLIP_TARGET_ABSOLUTE 0x04
#define linux_DRM_MODE_PAGE_FLIP_TARGET_RELATIVE 0x08
#define linux_DRM_MODE_PAGE_FLIP_TARGET          (linux_DRM_MODE_PAGE_FLIP_TARGET_ABSOLUTE | linux_DRM_MODE_PAGE_FLIP_TARGET_RELATIVE)
#define linux_DRM_MODE_PAGE_FLIP_FLAGS           (linux_DRM_MODE_PAGE_FLIP_EVENT | \
                                                  linux_DRM_MODE_PAGE_FLIP_ASYNC | \
                                                  linux_DRM_MODE_PAGE_FLIP_TARGET)

struct linux_drm_mode_crtc_page_flip
{
	uint32_t crtc_id;
	uint32_t fb_id;
	uint32_t flags;
	uint32_t reserved;
	uint64_t user_data;
};

struct linux_drm_mode_crtc_page_flip_target
{
	uint32_t crtc_id;
	uint32_t fb_id;
	uint32_t flags;
	uint32_t sequence;
	uint64_t user_data;
};

struct linux_drm_mode_create_dumb
{
	uint32_t height;
	uint32_t width;
	uint32_t bpp;
	uint32_t flags;
	uint32_t handle;
	uint32_t pitch;
	uint64_t size;
};

struct linux_drm_mode_map_dumb
{
	uint32_t handle;
	uint32_t _pad;
	uint64_t offset;
};

struct linux_drm_mode_destroy_dumb
{
	uint32_t handle;
};

#define linux_DRM_MODE_ATOMIC_TEST_ONLY     0x0100
#define linux_DRM_MODE_ATOMIC_NONBLOCK      0x0200
#define linux_DRM_MODE_ATOMIC_ALLOW_MODESET 0x0400
#define linux_DRM_MODE_ATOMIC_FLAGS         (linux_DRM_MODE_PAGE_FLIP_EVENT  | \
                                             linux_DRM_MODE_PAGE_FLIP_ASYNC  | \
                                             linux_DRM_MODE_ATOMIC_TEST_ONLY | \
                                             linux_DRM_MODE_ATOMIC_NONBLOCK  | \
                                             linux_DRM_MODE_ATOMIC_ALLOW_MODESET)

struct linux_drm_mode_atomic
{
	uint32_t flags;
	uint32_t count_objs;
	uint64_t objs_ptr;
	uint64_t count_props_ptr;
	uint64_t props_ptr;
	uint64_t prop_values_ptr;
	uint64_t reserved;
	uint64_t user_data;
};

struct linux_drm_format_modifier_blob
{
#define linux_FORMAT_BLOB_CURRENT 1
	uint32_t version;
	uint32_t flags;
	uint32_t count_formats;
	uint32_t formats_offset;
	uint32_t count_modifiers;
	uint32_t modifiers_offset;
};

struct linux_drm_format_modifier
{
	uint64_t formats;
	uint32_t offset;
	uint32_t _pad;
	uint64_t modifier;
};

struct linux_drm_mode_create_blob
{
	uint64_t data;
	uint32_t length;
	uint32_t blob_id;
};

struct linux_drm_mode_destroy_blob
{
	uint32_t blob_id;
};

struct linux_drm_mode_create_lease
{
	uint64_t object_ids;
	uint32_t object_count;
	uint32_t flags;
	uint32_t lessee_id;
	uint32_t fd;
};

struct linux_drm_mode_list_lessees
{
	uint32_t count_lessees;
	uint32_t _pad;
	uint64_t lessees_ptr;
};

struct linux_drm_mode_get_lease
{
	uint32_t count_objects;
	uint32_t _pad;
	uint64_t objects_ptr;
};

struct linux_drm_mode_revoke_lease
{
	uint32_t lessee_id;
};

struct linux_drm_mode_rect
{
	int32_t x1;
	int32_t y1;
	int32_t x2;
	int32_t y2;
};

#endif // !HEADER_LIBLINUX_DRM_DRM_MODE_H_INCLUDED
