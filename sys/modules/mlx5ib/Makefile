# $FreeBSD: stable/11/sys/modules/mlx5ib/Makefile 341958 2018-12-12 12:46:12Z hselasky $
.PATH:	${SRCTOP}/sys/dev/mlx5/mlx5_ib

KMOD=mlx5ib
SRCS= \
mlx5_ib_ah.c \
mlx5_ib_cong.c \
mlx5_ib_cq.c \
mlx5_ib_doorbell.c \
mlx5_ib_gsi.c \
mlx5_ib_mad.c \
mlx5_ib_main.c \
mlx5_ib_mem.c \
mlx5_ib_mr.c \
mlx5_ib_qp.c \
mlx5_ib_srq.c \
mlx5_ib_virt.c
SRCS+=	${LINUXKPI_GENSRCS}
SRCS+= 	opt_inet.h opt_inet6.h

CFLAGS+= -I${SRCTOP}/sys/ofed/include
CFLAGS+= -I${SRCTOP}/sys/ofed/include/uapi
CFLAGS+= -I${SRCTOP}/sys/compat/linuxkpi/common/include
CFLAGS+= -DCONFIG_INFINIBAND_USER_MEM
CFLAGS+= -DINET -DINET6

.if defined(CONFIG_BUILD_FPGA)
CFLAGS+= -DCONFIG_MLX5_FPGA
.endif

.include <bsd.kmod.mk>

CFLAGS+= -Wno-cast-qual -Wno-pointer-arith ${GCC_MS_EXTENSIONS}
