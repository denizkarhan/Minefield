#!/usr/bin/perl

use warnings;
use strict;
my $fh;
my $filename = 'maps.txt';
my $obst = 'o';
my $path = '.';
my $sqrmat = 'x';
open($fh, '>', $filename) or die $!;
die "program x y density" unless (scalar(@ARGV) == 3);
my ($x, $y, $density) = @ARGV;
print $fh "$y$path$obst$sqrmat\n";
for (my $i = 0; $i < $y; $i++) {
	for (my $j = 0; $j < $x; $j++) {
		if (int(rand($y) * 2) < $density) {
			print $fh "$obst";
		}
		else {
			print $fh "$path"; }
		}
	print $fh "\n";
}
