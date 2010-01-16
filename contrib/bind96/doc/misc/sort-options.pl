#!/bin/perl
#
# Copyright (C) 2007  Internet Systems Consortium, Inc. ("ISC")
#
# Permission to use, copy, modify, and/or distribute this software for any
# purpose with or without fee is hereby granted, provided that the above
# copyright notice and this permission notice appear in all copies.
#
# THE SOFTWARE IS PROVIDED "AS IS" AND ISC DISCLAIMS ALL WARRANTIES WITH
# REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY
# AND FITNESS.  IN NO EVENT SHALL ISC BE LIABLE FOR ANY SPECIAL, DIRECT,
# INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM
# LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE
# OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR
# PERFORMANCE OF THIS SOFTWARE.

# $Id: sort-options.pl,v 1.1.1.1 2010-01-16 16:06:20 laffer1 Exp $

sub sortlevel() {
	my @options = ();
	my $fin = "";
	my $i = 0;
	while (<>) {
		if (/^\s*};$/) {
			$fin = $_;
			# print 2, $_;
			last;
		}
		next if (/^$/);
		if (/{$/) {
			# print 3, $_;
			my $sec = $_;
			push(@options, $sec . sortlevel());
		} else {
			push(@options, $_);
			# print 1, $_;
		}
		$i++;
	}
	my $result = "";
	foreach my $i (sort @options) {
		$result = ${result}.${i};
		$result = $result."\n" if ($i =~ /^[a-z]/i);
		# print 5, ${i};
	}
	$result = ${result}.${fin};
	return ($result);
}

print sortlevel();
