# $FreeBSD: stable/11/sys/modules/hyperv/vmbus/Makefile 319182 2017-05-30 04:11:12Z ngie $

.PATH:	${SRCTOP}/sys/dev/hyperv/vmbus \
	${SRCTOP}/sys/dev/hyperv/vmbus/${MACHINE_CPUARCH}

KMOD=	hv_vmbus
SRCS=	hyperv.c \
	hyperv_busdma.c \
	hyperv_machdep.c \
	vmbus.c \
	vmbus_br.c \
	vmbus_chan.c \
	vmbus_et.c \
	vmbus_if.c \
	vmbus_res.c \
	vmbus_xact.c
SRCS+=	acpi_if.h bus_if.h device_if.h opt_acpi.h pci_if.h pcib_if.h vmbus_if.h

# XXX: for assym.s
SRCS+=  opt_kstack_pages.h opt_nfs.h opt_hwpmc_hooks.h opt_compat.h
.if ${MACHINE_CPUARCH} == "i386"
SRCS+=	opt_apic.h
.endif

SRCS+=	assym.s \
	vmbus_vector.S

vmbus_vector.o:
	${CC} -c -x assembler-with-cpp -DLOCORE ${CFLAGS} \
            ${.IMPSRC} -o ${.TARGET}

CFLAGS+= -I${SRCTOP}/sys/dev/hyperv/include \
	 -I${SRCTOP}/sys/dev/hyperv/vmbus

.include <bsd.kmod.mk>
