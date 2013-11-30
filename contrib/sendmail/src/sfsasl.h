/*
 * Copyright (c) 1999, 2000, 2006 Sendmail, Inc. and its suppliers.
 *	All rights reserved.
 *
 * By using this file, you agree to the terms and conditions set
 * forth in the LICENSE file which can be found at the top level of
 * the sendmail distribution.
 *
 *	$Id: sfsasl.h,v 1.1.1.3 2006-08-04 02:03:05 laffer1 Exp $"
 */

#ifndef SFSASL_H
# define SFSASL_H

# if SASL
extern int	sfdcsasl __P((SM_FILE_T **, SM_FILE_T **, sasl_conn_t *, int));
# endif /* SASL */

# if STARTTLS
extern int	tls_retry __P((SSL *, int, int, time_t, int, int,
				const char *));
extern int	sfdctls __P((SM_FILE_T **, SM_FILE_T **, SSL *));
# endif /* STARTTLS */

#endif /* ! SFSASL_H */
