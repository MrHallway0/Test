/* $MidnightBSD$ */
/*
 * CDDL HEADER START
 *
 * The contents of this file are subject to the terms of the
 * Common Development and Distribution License (the "License").
 * You may not use this file except in compliance with the License.
 *
 * You can obtain a copy of the license at usr/src/OPENSOLARIS.LICENSE
 * or http://www.opensolaris.org/os/licensing.
 * See the License for the specific language governing permissions
 * and limitations under the License.
 *
 * When distributing Covered Code, include this CDDL HEADER in each
 * file and include the License file at usr/src/OPENSOLARIS.LICENSE.
 * If applicable, add the following below this CDDL HEADER, with the
 * fields enclosed by brackets "[]" replaced with your own identifying
 * information: Portions Copyright [yyyy] [name of copyright owner]
 *
 * CDDL HEADER END
 *
 * $FreeBSD: src/sys/cddl/compat/opensolaris/sys/acl.h,v 1.2.2.2.2.1 2008/11/25 02:59:29 kensmith Exp $
 */
/*
 * Copyright 2006 Sun Microsystems, Inc.  All rights reserved.
 * Use is subject to license terms.
 */

#ifndef _OPENSOLARIS_SYS_ACL_H_
#define	_OPENSOLARIS_SYS_ACL_H_

#include_next <sys/acl.h>

#define	MAX_ACL_ENTRIES		(1024)	/* max entries of each type */

typedef struct acl_entry	aclent_t;
#define	a_type	ae_tag
#define	a_id	ae_id
#define	a_perm	ae_perm

typedef struct ace {
	uid_t		a_who;		/* uid or gid */
	uint32_t	a_access_mask;	/* read,write,... */
	uint16_t	a_flags;	/* see below */
	uint16_t	a_type;		/* allow or deny */
} ace_t;

#if 0
/*
 * The following are Defined types for an aclent_t.
 */
#define	USER_OBJ	(0x01)		/* object owner */
#define	USER		(0x02)		/* additional users */
#define	GROUP_OBJ	(0x04)		/* owning group of the object */
#define	GROUP		(0x08)		/* additional groups */
#define	CLASS_OBJ	(0x10)		/* file group class and mask entry */
#define	OTHER_OBJ	(0x20)		/* other entry for the object */
#define	ACL_DEFAULT	(0x1000)	/* default flag */
/* default object owner */
#define	DEF_USER_OBJ	(ACL_DEFAULT | USER_OBJ)
/* defalut additional users */
#define	DEF_USER	(ACL_DEFAULT | USER)
/* default owning group */
#define	DEF_GROUP_OBJ	(ACL_DEFAULT | GROUP_OBJ)
/* default additional groups */
#define	DEF_GROUP	(ACL_DEFAULT | GROUP)
/* default mask entry */
#define	DEF_CLASS_OBJ	(ACL_DEFAULT | CLASS_OBJ)
/* default other entry */
#define	DEF_OTHER_OBJ	(ACL_DEFAULT | OTHER_OBJ)
#endif

/*
 * The following are defined for ace_t.
 */
#define	ACE_READ_DATA		0x00000001
#define	ACE_LIST_DIRECTORY	0x00000001
#define	ACE_WRITE_DATA		0x00000002
#define	ACE_ADD_FILE		0x00000002
#define	ACE_APPEND_DATA		0x00000004
#define	ACE_ADD_SUBDIRECTORY	0x00000004
#define	ACE_READ_NAMED_ATTRS	0x00000008
#define	ACE_WRITE_NAMED_ATTRS	0x00000010
#define	ACE_EXECUTE		0x00000020
#define	ACE_DELETE_CHILD	0x00000040
#define	ACE_READ_ATTRIBUTES	0x00000080
#define	ACE_WRITE_ATTRIBUTES	0x00000100
#define	ACE_DELETE		0x00010000
#define	ACE_READ_ACL		0x00020000
#define	ACE_WRITE_ACL		0x00040000
#define	ACE_WRITE_OWNER		0x00080000
#define	ACE_SYNCHRONIZE		0x00100000

#define	ACE_FILE_INHERIT_ACE		0x0001
#define	ACE_DIRECTORY_INHERIT_ACE	0x0002
#define	ACE_NO_PROPAGATE_INHERIT_ACE	0x0004
#define	ACE_INHERIT_ONLY_ACE		0x0008
#define	ACE_SUCCESSFUL_ACCESS_ACE_FLAG	0x0010
#define	ACE_FAILED_ACCESS_ACE_FLAG	0x0020
#define	ACE_IDENTIFIER_GROUP		0x0040
#define	ACE_OWNER			0x1000
#define	ACE_GROUP			0x2000
#define	ACE_EVERYONE			0x4000

#define	ACE_ACCESS_ALLOWED_ACE_TYPE	0x0000
#define	ACE_ACCESS_DENIED_ACE_TYPE	0x0001
#define	ACE_SYSTEM_AUDIT_ACE_TYPE	0x0002
#define	ACE_SYSTEM_ALARM_ACE_TYPE	0x0003

#define	ACE_ALL_PERMS	(ACE_READ_DATA|ACE_LIST_DIRECTORY|ACE_WRITE_DATA| \
    ACE_ADD_FILE|ACE_APPEND_DATA|ACE_ADD_SUBDIRECTORY|ACE_READ_NAMED_ATTRS| \
    ACE_WRITE_NAMED_ATTRS|ACE_EXECUTE|ACE_DELETE_CHILD|ACE_READ_ATTRIBUTES| \
    ACE_WRITE_ATTRIBUTES|ACE_DELETE|ACE_READ_ACL|ACE_WRITE_ACL| \
    ACE_WRITE_OWNER|ACE_SYNCHRONIZE)

/*
 * The following flags are supported by both NFSv4 ACLs and ace_t.
 */
#define	ACE_NFSV4_SUP_FLAGS (ACE_FILE_INHERIT_ACE | \
    ACE_DIRECTORY_INHERIT_ACE | \
    ACE_NO_PROPAGATE_INHERIT_ACE | \
    ACE_INHERIT_ONLY_ACE | \
    ACE_IDENTIFIER_GROUP)

#define	ACE_TYPE_FLAGS	(ACE_OWNER|ACE_GROUP|ACE_EVERYONE|ACE_IDENTIFIER_GROUP)

#if 0
/* cmd args to acl(2) for aclent_t  */
#define	GETACL			1
#define	SETACL			2
#define	GETACLCNT		3
#endif

/* cmd's to manipulate ace acls. */
#define	ACE_GETACL		4
#define	ACE_SETACL		5
#define	ACE_GETACLCNT		6

#if 0
/* minimal acl entries from GETACLCNT */
#define	MIN_ACL_ENTRIES		4

#if !defined(_KERNEL)

/* acl check errors */
#define	GRP_ERROR		1
#define	USER_ERROR		2
#define	OTHER_ERROR		3
#define	CLASS_ERROR		4
#define	DUPLICATE_ERROR		5
#define	MISS_ERROR		6
#define	MEM_ERROR		7
#define	ENTRY_ERROR		8


/*
 * similar to ufs_acl.h: changed to char type for user commands (tar, cpio)
 * Attribute types
 */
#define	UFSD_FREE	('0')	/* Free entry */
#define	UFSD_ACL	('1')	/* Access Control Lists */
#define	UFSD_DFACL	('2')	/* reserved for future use */
#define	ACE_ACL		('3')	/* ace_t style acls */

/*
 * flag to [f]acl_get()
 * controls whether a trivial acl should be returned.
 */
#define	ACL_NO_TRIVIAL	0x2


/*
 * Flags to control acl_totext()
 */

#define	ACL_APPEND_ID	0x1 	/* append uid/gid to user/group entries */
#define	ACL_COMPACT_FMT	0x2 	/* build ACL in ls -V format */
#define	ACL_NORESOLVE	0x4	/* don't do name service lookups */

/*
 * Legacy aclcheck errors for aclent_t ACLs
 */
#define	EACL_GRP_ERROR		GRP_ERROR
#define	EACL_USER_ERROR		USER_ERROR
#define	EACL_OTHER_ERROR	OTHER_ERROR
#define	EACL_CLASS_ERROR	CLASS_ERROR
#define	EACL_DUPLICATE_ERROR	DUPLICATE_ERROR
#define	EACL_MISS_ERROR		MISS_ERROR
#define	EACL_MEM_ERROR		MEM_ERROR
#define	EACL_ENTRY_ERROR	ENTRY_ERROR

#define	EACL_INHERIT_ERROR	9		/* invalid inherit flags */
#define	EACL_FLAGS_ERROR	10		/* unknown flag value */
#define	EACL_PERM_MASK_ERROR	11		/* unknown permission */
#define	EACL_COUNT_ERROR	12		/* invalid acl count */

#define	EACL_INVALID_SLOT	13		/* invalid acl slot */
#define	EACL_NO_ACL_ENTRY	14		/* Entry doesn't exist */
#define	EACL_DIFF_TYPE		15		/* acls aren't same type */

#define	EACL_INVALID_USER_GROUP	16		/* need user/group name */
#define	EACL_INVALID_STR	17		/* invalid acl string */
#define	EACL_FIELD_NOT_BLANK	18		/* can't have blank field */
#define	EACL_INVALID_ACCESS_TYPE 19		/* invalid access type */
#define	EACL_UNKNOWN_DATA	20		/* Unrecognized data in ACL */
#define	EACL_MISSING_FIELDS	21		/* missing fields in acl */

#define	EACL_INHERIT_NOTDIR	22		/* Need dir for inheritance */

extern int aclcheck(aclent_t *, int, int *);
extern int acltomode(aclent_t *, int, mode_t *);
extern int aclfrommode(aclent_t *, int, mode_t *);
extern int aclsort(int, int, aclent_t *);
extern char *acltotext(aclent_t *, int);
extern aclent_t *aclfromtext(char *, int *);
extern void acl_free(acl_t *);
extern int acl_get(const char *, int, acl_t **);
extern int facl_get(int, int, acl_t **);
extern int acl_set(const char *, acl_t *acl);
extern int facl_set(int, acl_t *acl);
extern int acl_strip(const char *, uid_t, gid_t, mode_t);
extern int acl_trivial(const char *);
extern char *acl_totext(acl_t *, int);
extern int acl_fromtext(const char *, acl_t **);
extern int acl_check(acl_t *, int);

#else	/* !defined(_KERNEL) */

extern void ksort(caddr_t, int, int, int (*)(void *, void *));
extern int cmp2acls(void *, void *);

#endif	/* !defined(_KERNEL) */

#if defined(__STDC__)
extern int acl(const char *path, int cmd, int cnt, void *buf);
extern int facl(int fd, int cmd, int cnt, void *buf);
#else	/* !__STDC__ */
extern int acl();
extern int facl();
#endif	/* defined(__STDC__) */

#endif

#endif /* _OPENSOLARIS_SYS_ACL_H */
