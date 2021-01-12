/*
 * Copyright 2018-2021 Mahdi Khanalizadeh
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

#ifndef HEADER_LIBLINUX_DRM_DRM_FOURCC_H_INCLUDED
#define HEADER_LIBLINUX_DRM_DRM_FOURCC_H_INCLUDED

#include <stdint.h>

#define linux_fourcc_code(a, b, c, d) ((uint32_t)(a) | ((uint32_t)(b) << 8) | ((uint32_t)(c) << 16) | ((uint32_t)(d) << 24))

#define linux_DRM_FORMAT_BIG_ENDIAN      (1U << 31)
#define linux_DRM_FORMAT_INVALID         0
#define linux_DRM_FORMAT_C8              linux_fourcc_code('C', '8', ' ', ' ')
#define linux_DRM_FORMAT_R8              linux_fourcc_code('R', '8', ' ', ' ')
#define linux_DRM_FORMAT_R16             linux_fourcc_code('R', '1', '6', ' ')
#define linux_DRM_FORMAT_RG88            linux_fourcc_code('R', 'G', '8', '8')
#define linux_DRM_FORMAT_GR88            linux_fourcc_code('G', 'R', '8', '8')
#define linux_DRM_FORMAT_RG1616          linux_fourcc_code('R', 'G', '3', '2')
#define linux_DRM_FORMAT_GR1616          linux_fourcc_code('G', 'R', '3', '2')
#define linux_DRM_FORMAT_RGB332          linux_fourcc_code('R', 'G', 'B', '8')
#define linux_DRM_FORMAT_BGR233          linux_fourcc_code('B', 'G', 'R', '8')
#define linux_DRM_FORMAT_XRGB4444        linux_fourcc_code('X', 'R', '1', '2')
#define linux_DRM_FORMAT_XBGR4444        linux_fourcc_code('X', 'B', '1', '2')
#define linux_DRM_FORMAT_RGBX4444        linux_fourcc_code('R', 'X', '1', '2')
#define linux_DRM_FORMAT_BGRX4444        linux_fourcc_code('B', 'X', '1', '2')
#define linux_DRM_FORMAT_ARGB4444        linux_fourcc_code('A', 'R', '1', '2')
#define linux_DRM_FORMAT_ABGR4444        linux_fourcc_code('A', 'B', '1', '2')
#define linux_DRM_FORMAT_RGBA4444        linux_fourcc_code('R', 'A', '1', '2')
#define linux_DRM_FORMAT_BGRA4444        linux_fourcc_code('B', 'A', '1', '2')
#define linux_DRM_FORMAT_XRGB1555        linux_fourcc_code('X', 'R', '1', '5')
#define linux_DRM_FORMAT_XBGR1555        linux_fourcc_code('X', 'B', '1', '5')
#define linux_DRM_FORMAT_RGBX5551        linux_fourcc_code('R', 'X', '1', '5')
#define linux_DRM_FORMAT_BGRX5551        linux_fourcc_code('B', 'X', '1', '5')
#define linux_DRM_FORMAT_ARGB1555        linux_fourcc_code('A', 'R', '1', '5')
#define linux_DRM_FORMAT_ABGR1555        linux_fourcc_code('A', 'B', '1', '5')
#define linux_DRM_FORMAT_RGBA5551        linux_fourcc_code('R', 'A', '1', '5')
#define linux_DRM_FORMAT_BGRA5551        linux_fourcc_code('B', 'A', '1', '5')
#define linux_DRM_FORMAT_RGB565          linux_fourcc_code('R', 'G', '1', '6')
#define linux_DRM_FORMAT_BGR565          linux_fourcc_code('B', 'G', '1', '6')
#define linux_DRM_FORMAT_RGB888          linux_fourcc_code('R', 'G', '2', '4')
#define linux_DRM_FORMAT_BGR888          linux_fourcc_code('B', 'G', '2', '4')
#define linux_DRM_FORMAT_XRGB8888        linux_fourcc_code('X', 'R', '2', '4')
#define linux_DRM_FORMAT_XBGR8888        linux_fourcc_code('X', 'B', '2', '4')
#define linux_DRM_FORMAT_RGBX8888        linux_fourcc_code('R', 'X', '2', '4')
#define linux_DRM_FORMAT_BGRX8888        linux_fourcc_code('B', 'X', '2', '4')
#define linux_DRM_FORMAT_ARGB8888        linux_fourcc_code('A', 'R', '2', '4')
#define linux_DRM_FORMAT_ABGR8888        linux_fourcc_code('A', 'B', '2', '4')
#define linux_DRM_FORMAT_RGBA8888        linux_fourcc_code('R', 'A', '2', '4')
#define linux_DRM_FORMAT_BGRA8888        linux_fourcc_code('B', 'A', '2', '4')
#define linux_DRM_FORMAT_XRGB2101010     linux_fourcc_code('X', 'R', '3', '0')
#define linux_DRM_FORMAT_XBGR2101010     linux_fourcc_code('X', 'B', '3', '0')
#define linux_DRM_FORMAT_RGBX1010102     linux_fourcc_code('R', 'X', '3', '0')
#define linux_DRM_FORMAT_BGRX1010102     linux_fourcc_code('B', 'X', '3', '0')
#define linux_DRM_FORMAT_ARGB2101010     linux_fourcc_code('A', 'R', '3', '0')
#define linux_DRM_FORMAT_ABGR2101010     linux_fourcc_code('A', 'B', '3', '0')
#define linux_DRM_FORMAT_RGBA1010102     linux_fourcc_code('R', 'A', '3', '0')
#define linux_DRM_FORMAT_BGRA1010102     linux_fourcc_code('B', 'A', '3', '0')
#define linux_DRM_FORMAT_XRGB16161616F   linux_fourcc_code('X', 'R', '4', 'H')
#define linux_DRM_FORMAT_XBGR16161616F   linux_fourcc_code('X', 'B', '4', 'H')
#define linux_DRM_FORMAT_ARGB16161616F   linux_fourcc_code('A', 'R', '4', 'H')
#define linux_DRM_FORMAT_ABGR16161616F   linux_fourcc_code('A', 'B', '4', 'H')
#define linux_DRM_FORMAT_YUYV            linux_fourcc_code('Y', 'U', 'Y', 'V')
#define linux_DRM_FORMAT_YVYU            linux_fourcc_code('Y', 'V', 'Y', 'U')
#define linux_DRM_FORMAT_UYVY            linux_fourcc_code('U', 'Y', 'V', 'Y')
#define linux_DRM_FORMAT_VYUY            linux_fourcc_code('V', 'Y', 'U', 'Y')
#define linux_DRM_FORMAT_AYUV            linux_fourcc_code('A', 'Y', 'U', 'V')
#define linux_DRM_FORMAT_XYUV8888        linux_fourcc_code('X', 'Y', 'U', 'V')
#define linux_DRM_FORMAT_VUY888          linux_fourcc_code('V', 'U', '2', '4')
#define linux_DRM_FORMAT_VUY101010       linux_fourcc_code('V', 'U', '3', '0')
#define linux_DRM_FORMAT_Y210            linux_fourcc_code('Y', '2', '1', '0')
#define linux_DRM_FORMAT_Y212            linux_fourcc_code('Y', '2', '1', '2')
#define linux_DRM_FORMAT_Y216            linux_fourcc_code('Y', '2', '1', '6')
#define linux_DRM_FORMAT_Y410            linux_fourcc_code('Y', '4', '1', '0')
#define linux_DRM_FORMAT_Y412            linux_fourcc_code('Y', '4', '1', '2')
#define linux_DRM_FORMAT_Y416            linux_fourcc_code('Y', '4', '1', '6')
#define linux_DRM_FORMAT_XVYU2101010     linux_fourcc_code('X', 'V', '3', '0')
#define linux_DRM_FORMAT_XVYU12_16161616 linux_fourcc_code('X', 'V', '3', '6')
#define linux_DRM_FORMAT_XVYU16161616    linux_fourcc_code('X', 'V', '4', '8')
#define linux_DRM_FORMAT_Y0L0            linux_fourcc_code('Y', '0', 'L', '0')
#define linux_DRM_FORMAT_X0L0            linux_fourcc_code('X', '0', 'L', '0')
#define linux_DRM_FORMAT_Y0L2            linux_fourcc_code('Y', '0', 'L', '2')
#define linux_DRM_FORMAT_X0L2            linux_fourcc_code('X', '0', 'L', '2')
#define linux_DRM_FORMAT_YUV420_8BIT     linux_fourcc_code('Y', 'U', '0', '8')
#define linux_DRM_FORMAT_YUV420_10BIT    linux_fourcc_code('Y', 'U', '1', '0')
#define linux_DRM_FORMAT_XRGB8888_A8     linux_fourcc_code('X', 'R', 'A', '8')
#define linux_DRM_FORMAT_XBGR8888_A8     linux_fourcc_code('X', 'B', 'A', '8')
#define linux_DRM_FORMAT_RGBX8888_A8     linux_fourcc_code('R', 'X', 'A', '8')
#define linux_DRM_FORMAT_BGRX8888_A8     linux_fourcc_code('B', 'X', 'A', '8')
#define linux_DRM_FORMAT_RGB888_A8       linux_fourcc_code('R', '8', 'A', '8')
#define linux_DRM_FORMAT_BGR888_A8       linux_fourcc_code('B', '8', 'A', '8')
#define linux_DRM_FORMAT_RGB565_A8       linux_fourcc_code('R', '5', 'A', '8')
#define linux_DRM_FORMAT_BGR565_A8       linux_fourcc_code('B', '5', 'A', '8')
#define linux_DRM_FORMAT_NV12            linux_fourcc_code('N', 'V', '1', '2')
#define linux_DRM_FORMAT_NV21            linux_fourcc_code('N', 'V', '2', '1')
#define linux_DRM_FORMAT_NV16            linux_fourcc_code('N', 'V', '1', '6')
#define linux_DRM_FORMAT_NV61            linux_fourcc_code('N', 'V', '6', '1')
#define linux_DRM_FORMAT_NV24            linux_fourcc_code('N', 'V', '2', '4')
#define linux_DRM_FORMAT_NV42            linux_fourcc_code('N', 'V', '4', '2')
#define linux_DRM_FORMAT_P210            linux_fourcc_code('P', '2', '1', '0')
#define linux_DRM_FORMAT_P010            linux_fourcc_code('P', '0', '1', '0')
#define linux_DRM_FORMAT_P012            linux_fourcc_code('P', '0', '1', '2')
#define linux_DRM_FORMAT_P016            linux_fourcc_code('P', '0', '1', '6')
#define linux_DRM_FORMAT_YUV410          linux_fourcc_code('Y', 'U', 'V', '9')
#define linux_DRM_FORMAT_YVU410          linux_fourcc_code('Y', 'V', 'U', '9')
#define linux_DRM_FORMAT_YUV411          linux_fourcc_code('Y', 'U', '1', '1')
#define linux_DRM_FORMAT_YVU411          linux_fourcc_code('Y', 'V', '1', '1')
#define linux_DRM_FORMAT_YUV420          linux_fourcc_code('Y', 'U', '1', '2')
#define linux_DRM_FORMAT_YVU420          linux_fourcc_code('Y', 'V', '1', '2')
#define linux_DRM_FORMAT_YUV422          linux_fourcc_code('Y', 'U', '1', '6')
#define linux_DRM_FORMAT_YVU422          linux_fourcc_code('Y', 'V', '1', '6')
#define linux_DRM_FORMAT_YUV444          linux_fourcc_code('Y', 'U', '2', '4')
#define linux_DRM_FORMAT_YVU444          linux_fourcc_code('Y', 'V', '2', '4')

#define linux_DRM_FORMAT_MOD_NONE             0
#define linux_DRM_FORMAT_MOD_VENDOR_NONE      0
#define linux_DRM_FORMAT_MOD_VENDOR_INTEL     0x01
#define linux_DRM_FORMAT_MOD_VENDOR_AMD       0x02
#define linux_DRM_FORMAT_MOD_VENDOR_NVIDIA    0x03
#define linux_DRM_FORMAT_MOD_VENDOR_SAMSUNG   0x04
#define linux_DRM_FORMAT_MOD_VENDOR_QCOM      0x05
#define linux_DRM_FORMAT_MOD_VENDOR_VIVANTE   0x06
#define linux_DRM_FORMAT_MOD_VENDOR_BROADCOM  0x07
#define linux_DRM_FORMAT_MOD_VENDOR_ARM       0x08
#define linux_DRM_FORMAT_MOD_VENDOR_ALLWINNER 0x09
#define linux_DRM_FORMAT_RESERVED             ((1ULL << 56) - 1)

#define linux_fourcc_mod_code(vendor, val) ((((uint64_t)linux_DRM_FORMAT_MOD_VENDOR_## vendor) << 56) | ((val) & 0x00ffffffffffffffULL))

#define linux__fourcc_mod_broadcom_param_shift       8
#define linux__fourcc_mod_broadcom_param_bits       48
#define linux_fourcc_mod_broadcom_code(val, params) linux_fourcc_mod_code(BROADCOM, ((((uint64_t)params) << linux__fourcc_mod_broadcom_param_shift) | val))
#define linux_fourcc_mod_broadcom_param(m)          ((int)(((m) >> linux__fourcc_mod_broadcom_param_shift) & ((1ULL << linux__fourcc_mod_broadcom_param_bits) - 1)))
#define linux_fourcc_mod_broadcom_mod(m)            ((m) & ~(((1ULL << linux__fourcc_mod_broadcom_param_bits) - 1) << linux__fourcc_mod_broadcom_param_shift))

#define linux_DRM_FORMAT_MOD_BROADCOM_SAND32_COL_HEIGHT(v)  linux_fourcc_mod_broadcom_code(2, v)
#define linux_DRM_FORMAT_MOD_BROADCOM_SAND64_COL_HEIGHT(v)  linux_fourcc_mod_broadcom_code(3, v)
#define linux_DRM_FORMAT_MOD_BROADCOM_SAND128_COL_HEIGHT(v) linux_fourcc_mod_broadcom_code(4, v)
#define linux_DRM_FORMAT_MOD_BROADCOM_SAND256_COL_HEIGHT(v) linux_fourcc_mod_broadcom_code(5, v)

#define linux_DRM_FORMAT_MOD_ARM_CODE(__type, __val) linux_fourcc_mod_code(ARM, ((uint64_t)(__type) << 52) | ((__val) & 0x000fffffffffffffULL))

#define linux_DRM_FORMAT_MOD_INVALID                          linux_fourcc_mod_code(NONE, linux_DRM_FORMAT_RESERVED)
#define linux_DRM_FORMAT_MOD_LINEAR                           linux_fourcc_mod_code(NONE, 0)

#define linux_I915_FORMAT_MOD_X_TILED                         linux_fourcc_mod_code(INTEL, 1)
#define linux_I915_FORMAT_MOD_Y_TILED                         linux_fourcc_mod_code(INTEL, 2)
#define linux_I915_FORMAT_MOD_Yf_TILED                        linux_fourcc_mod_code(INTEL, 3)
#define linux_I915_FORMAT_MOD_Y_TILED_CCS                     linux_fourcc_mod_code(INTEL, 4)
#define linux_I915_FORMAT_MOD_Yf_TILED_CCS                    linux_fourcc_mod_code(INTEL, 5)

#define linux_DRM_FORMAT_MOD_SAMSUNG_64_32_TILE               linux_fourcc_mod_code(SAMSUNG, 1)
#define linux_DRM_FORMAT_MOD_SAMSUNG_16_16_TILE               linux_fourcc_mod_code(SAMSUNG, 2)
#define linux_DRM_FORMAT_MOD_QCOM_COMPRESSED                  linux_fourcc_mod_code(QCOM, 1)
#define linux_DRM_FORMAT_MOD_VIVANTE_TILED                    linux_fourcc_mod_code(VIVANTE, 1)
#define linux_DRM_FORMAT_MOD_VIVANTE_SUPER_TILED              linux_fourcc_mod_code(VIVANTE, 2)
#define linux_DRM_FORMAT_MOD_VIVANTE_SPLIT_TILED              linux_fourcc_mod_code(VIVANTE, 3)
#define linux_DRM_FORMAT_MOD_VIVANTE_SPLIT_SUPER_TILED        linux_fourcc_mod_code(VIVANTE, 4)
#define linux_DRM_FORMAT_MOD_NVIDIA_TEGRA_TILED               linux_fourcc_mod_code(NVIDIA, 1)
#define linux_DRM_FORMAT_MOD_NVIDIA_16BX2_BLOCK(v)            linux_fourcc_mod_code(NVIDIA, 0x10 | ((v) & 0xf))
#define linux_DRM_FORMAT_MOD_NVIDIA_16BX2_BLOCK_ONE_GOB       linux_fourcc_mod_code(NVIDIA, 0x10)
#define linux_DRM_FORMAT_MOD_NVIDIA_16BX2_BLOCK_TWO_GOB       linux_fourcc_mod_code(NVIDIA, 0x11)
#define linux_DRM_FORMAT_MOD_NVIDIA_16BX2_BLOCK_FOUR_GOB      linux_fourcc_mod_code(NVIDIA, 0x12)
#define linux_DRM_FORMAT_MOD_NVIDIA_16BX2_BLOCK_EIGHT_GOB     linux_fourcc_mod_code(NVIDIA, 0x13)
#define linux_DRM_FORMAT_MOD_NVIDIA_16BX2_BLOCK_SIXTEEN_GOB   linux_fourcc_mod_code(NVIDIA, 0x14)
#define linux_DRM_FORMAT_MOD_NVIDIA_16BX2_BLOCK_THIRTYTWO_GOB linux_fourcc_mod_code(NVIDIA, 0x15)
#define linux_DRM_FORMAT_MOD_BROADCOM_VC4_T_TILED             linux_fourcc_mod_code(BROADCOM, 1)
#define linux_DRM_FORMAT_MOD_BROADCOM_SAND32                  linux_DRM_FORMAT_MOD_BROADCOM_SAND32_COL_HEIGHT(0)
#define linux_DRM_FORMAT_MOD_BROADCOM_SAND64                  linux_DRM_FORMAT_MOD_BROADCOM_SAND64_COL_HEIGHT(0)
#define linux_DRM_FORMAT_MOD_BROADCOM_SAND128                 linux_DRM_FORMAT_MOD_BROADCOM_SAND128_COL_HEIGHT(0)
#define linux_DRM_FORMAT_MOD_BROADCOM_SAND256                 linux_DRM_FORMAT_MOD_BROADCOM_SAND256_COL_HEIGHT(0)
#define linux_DRM_FORMAT_MOD_BROADCOM_UIF                     linux_fourcc_mod_code(BROADCOM, 6)
#define linux_DRM_FORMAT_MOD_ARM_AFBC(afbc_mode)              linux_DRM_FORMAT_MOD_ARM_CODE(linux_DRM_FORMAT_MOD_ARM_TYPE_AFBC, afbc_mode)
#define linux_DRM_FORMAT_MOD_ARM_16X16_BLOCK_U_INTERLEAVED    linux_DRM_FORMAT_MOD_ARM_CODE(linux_DRM_FORMAT_MOD_ARM_TYPE_MISC, 1ULL)
#define linux_DRM_FORMAT_MOD_ALLWINNER_TILED                  linux_fourcc_mod_code(ALLWINNER, 1)

#define linux_DRM_FORMAT_MOD_ARM_TYPE_AFBC 0x00
#define linux_DRM_FORMAT_MOD_ARM_TYPE_MISC 0x01

#define linux_AFBC_FORMAT_MOD_BLOCK_SIZE_MASK      0xf
#define linux_AFBC_FORMAT_MOD_BLOCK_SIZE_16x16     (1ULL)
#define linux_AFBC_FORMAT_MOD_BLOCK_SIZE_32x8      (2ULL)
#define linux_AFBC_FORMAT_MOD_BLOCK_SIZE_64x4      (3ULL)
#define linux_AFBC_FORMAT_MOD_BLOCK_SIZE_32x8_64x4 (4ULL)

#define linux_AFBC_FORMAT_MOD_YTR    (1ULL <<  4)
#define linux_AFBC_FORMAT_MOD_SPLIT  (1ULL <<  5)
#define linux_AFBC_FORMAT_MOD_SPARSE (1ULL <<  6)
#define linux_AFBC_FORMAT_MOD_CBR    (1ULL <<  7)
#define linux_AFBC_FORMAT_MOD_TILED  (1ULL <<  8)
#define linux_AFBC_FORMAT_MOD_SC     (1ULL <<  9)
#define linux_AFBC_FORMAT_MOD_DB     (1ULL << 10)
#define linux_AFBC_FORMAT_MOD_BCH    (1ULL << 11)

#endif // !HEADER_LIBLINUX_DRM_DRM_FOURCC_H_INCLUDED
