#!/usr/bin/perl -w
use strict;

my $adr = 0;

my $error=0;

while (defined(my $line = <>)) {
    chomp($line);
    next if ($line =~ m/^\s*([*#;.].*)?$/);
    if ($line =~ m/^([0-9a-fA-F][0-9a-fA-F]*) +([0-9a-fA-F]+) +(.*)$/) {
        my $position = $1;
        my $hex_position = eval "0x$position";
        my $code = $2;
        my $comment = $3;

	if ($adr > $hex_position) {
	    print STDERR "Error: instruction address $hex_position is lesser than current position $adr";
            $error=1;
	}
        while ($adr < $hex_position) {
            printf("00  @ adr %2x  :\n", $adr);
            $adr++;
        }
        while (length($code)) {
            print (substr $code, 0, 2);
            if (length($position)) {
                printf ("  @ adr %2x  : %s\n", $adr, $comment);
            } else {
                printf ("  @ adr %2x  : (cont.)\n", $adr);
            }
            $code = substr $code, 2;
            $position="";
            $adr++;
        }
    } elsif ($line =~ m/^([0-9a-fA-F][0-9a-fA-F]) +([0-9a-fxA-FX]+) +(.*)$/) {
	print STDERR "Error: Invalid opcode '$2' in line:\n$line\n";
	$error=1;
    } elsif ($line =~ m/^([0-9a-fA-F]+) +([0-9a-fxA-FX]+) +(.*)$/) {
	print STDERR "Invalid adress '$1' in line:\n$line\n";
	$error=1;
    } else {
        print STDERR "Warning: ignoring line '$line'\n";
    }
}
while ($adr < 254) {
    printf("00  @ adr %2x  :\n", $adr);
    $adr++;
}
while ($adr < 255) {
    printf("00  @ adr %2x  :  %s\n", $adr, "ATTENTION BUG : ne pas mettre la ligne ff");
    $adr++;
}
exit($error)
