warn "Legacy library @{[(caller(0))[6]]} will be removed from the Perl core distribution in the next major release. Please install it from the CPAN distribution Perl4::CoreLibs. It is being used at @{[(caller)[1]]}, line @{[(caller)[2]]}.\n";

;# pwd.pl - keeps track of current working directory in PWD environment var
;#
#
# This library is no longer being maintained, and is included for backward
# compatibility with Perl 4 programs which may require it.
# This legacy library is deprecated and will be removed in a future
# release of perl.
#
# In particular, this should not be used as an example of modern Perl
# programming techniques.
#
# Suggested alternative: Cwd

;# $RCSfile: pwd.pl,v $$Revision: 1.1.1.2 $$Date: 2011-05-18 13:33:26 $
;#
;# $Log: not supported by cvs2svn $
;#
;# Usage:
;#	require "pwd.pl";
;#	&initpwd;
;#	...
;#	&chdir($newdir);

package pwd;

sub main'initpwd {
    if ($ENV{'PWD'}) {
	local($dd,$di) = stat('.');
	local($pd,$pi) = stat($ENV{'PWD'});
	if (!defined $dd or !defined $pd or $di != $pi or $dd != $pd) {
	    chop($ENV{'PWD'} = `pwd`);
	}
    }
    else {
	chop($ENV{'PWD'} = `pwd`);
    }
    if ($ENV{'PWD'} =~ m|(/[^/]+(/[^/]+/[^/]+))(.*)|) {
	local($pd,$pi) = stat($2);
	local($dd,$di) = stat($1);
	if (defined $pd and defined $dd and $di == $pi and $dd == $pd) {
	    $ENV{'PWD'}="$2$3";
	}
    }
}

sub main'chdir {
    local($newdir) = shift;
    $newdir =~ s|/{2,}|/|g;
    if (chdir $newdir) {
	if ($newdir =~ m#^/#) {
	    $ENV{'PWD'} = $newdir;
	}
	else {
	    local(@curdir) = split(m#/#,$ENV{'PWD'});
	    @curdir = '' unless @curdir;
	    foreach $component (split(m#/#, $newdir)) {
		next if $component eq '.';
		pop(@curdir),next if $component eq '..';
		push(@curdir,$component);
	    }
	    $ENV{'PWD'} = join('/',@curdir) || '/';
	}
    }
    else {
	0;
    }
}

1;
