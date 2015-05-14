#$abc="AC_DEFINE(HAVE_LIBC)";
#print "$abc\n";


#if ($abc =~ s/(AC_DEFINE)\((.*)\)/$1\($2,,""\)/g )
#{
#	print "$1\n";
#	print "$abc\n";
#}

open(IN,"test.txt") || die "open file failed";
open(OUT,">testcp.txt") || die "open file failed";

while($string=<IN>)
{
#	if ($string =~ /bbb/)
#	{
#		$string =~ s/bbb/ddd/g;
#	}
#	print $string;

	#if ($string =~ /(AC_DEFINE)/)
	#{
	#	print "$&\n";
	#	print "hahaha\n";
	#}

	#if ($string =~ /[^\(]*\(/)
	#{
#		print "$&\n";
#		print "hahaha\n";
#	}
#	exit 0;

	if ($string =~ /(AC_DEFINE)\(([^\)\(]*?),([^\(\)]*?)\)/)
	{
		print "$&\n";
		$string =~ s/(AC_DEFINE)\(([^\)]*?),([^\(]*?)\)/$1\($2,$3,""\)/g;
		print $string;
	}
	exit 0;
	if ($string =~ /(AC_DEFINE)\((([a-zA-Z]|_)*),(.*?)\)/)
	{
#		print "$&\n";
#		print "111\n";
#		$string =~ s/(AC_DEFINE)\((.*),(.*)\)/$1\($2,$3,""\)/g;
		$string =~ s/(AC_DEFINE)\((([a-zA-Z]|_)*?),(.*?)\)/$1\($2,$4,""\)/g;


	}
	
	if ($string =~ /(AC_DEFINE)\((([a-zA-Z]|_)*?)\)/)
	{
		#print "222\n";
		#print "$&\n";
		$string =~ s/(AC_DEFINE)\((([a-zA-Z]|_)*?)\)/$1\($2,,""\)/g;
		#print "$1\n";
		#print "$2\n";
		
	}
	print $string;
#	$string =~ s/(AC_DEFINE)\((.*)\)/$1\($2,,""\)/g;
#	print OUT $string;		

}

close(IN);
close(OUT);
