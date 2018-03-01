.name	"Leeloo"
.comment "Multipass"
	
begin:	ld %0,r6
jump:	zjmp %:deb
	
pare:	st r16,:begin -52
	st r16,:begin -44
	st r16,:begin -52
	st r16,:begin -44
	st r16,:begin -52
	st r16,:begin -44
	st r16,:begin -52
	live %1
	st r16,:begin -44
	st r16,:begin -52
	st r16,:begin -44
	st r16,:begin -52
	st r16,:begin -44
	st r16,:begin -52
	st r16,:begin -44
	zjmp %:pare
toto:	st r15,-480
	st r4,-481
	st r7,-482
	st r8,-483
	st r13,-484
	st r14,-485
	zjmp %-510
deb:	
st1:	st r1,:lastlive1 +1
st2:	st r1,:lastlive2 +1
st3:	st r1,:lastlive3 +1
st4:	st r1,:lastlive4 +1
st5:	st r1,:live1 +1
st6:	st r1,:live2 +1
st7:	st r1,:live3 +1
st8:	st r1,:live4 +1
	st r16,:jump
	st r16,:begin -4
	st r16,:begin -8
	st r16,:begin -12

hop:	live %1
	fork %:decal2
	live %1
	ld %0,r2
	zjmp %:decal

toto1:	zjmp %:toto	
pare1:	ld %0,r16
	zjmp %:pare	
decal2: live %1
	fork %:suite
	live %1
	ld %57672448,r5
	ld %67334147,r6

	ld %57673214,r9
	ld %201551878,r10
	ld %4262136318,r11
	ld %33554432,r12

	ld %57674238,r15
	ld %369324042,r4
	ld %4262790000,r7
	ld %201200643,r8
	ld %1879899667,r13
	ld %167641600,r14
	
	fork %:separ2
	live %4
	ld %5639279506,r3   #ld %0x07F40370,r3

	ld %0,r2
	zjmp %:toto
separ2:	live %3
	ld %57672948,r3  #ld %0x70037004,r3

	xor r2,r2,r2
	zjmp %:toto
	
padec2:	live %1
	fork %:suite
	live %1
	ld %0,r2
	zjmp %:decal

catch1:	zjmp %:catch
	
suite:	live %1
	fork %:hop
	live %1
	fork %:just
just:	live %3
	fork %:just2
just2:	live %3
	fork %:just3
just3:	live %3
	fork %:just4
	live %3
just4:	live %3
	fork %:just5
	live %3
just5:	fork %:middle
suitb:	live %3
	st r16,:st1+1
	live %3
	st r16,:st1+1
	live %3
	st r16,:st1+1
live1:	live %3
	st r16,:st1+1
live2:	live %3
	st r16,:st1+1
lastlive1: live %1
	ld %0,r6
lastlive2: live %1
	zjmp %:suitb
middle:	live %3
	st r16,:st2+1
	live %3
	st r16,:st2+1
	live %3
	st r16,:st2+1
live3:	live %3
	st r16,:st2+1
live4:	live %4
lastlive3: live %1
	ld %0,r6
lastlive4: live %1
	zjmp %:middle

	
decal:	live %1
	fork %:pare1
	live %1
	fork %:fuite
	live %1
	ld %57672448,r5
	ld %67334147,r6

	ld %57672961,r9
	ld %4228083718,r10
	ld %33229057,r11
	ld %4060086272,r12

	ld %57673985,r15
	ld %4228083722,r4
	ld %33227632,r7
	ld %184678915,r8
	ld %1879835129,r13
	ld %151119872,r14
	
	fork %:sepa
	live %4
	ld %122749808,r3
	ld %0,r2
	zjmp %:tot
sepa:	live %3
	ld %1879273476,r3
	xor r2,r2,r2
	zjmp %:tot
catch:	
	live %5
	live %5
	live %5
	live %5
	live %5
	live %5
	live %5
	live %5
	live %5
	live %5
	live %5
	live %5
	live %5
	ld %0,r16
	zjmp %:catch
	
fuite:	live %1
	fork %:separe
	live %4
	ld %122749808,r3
	ld %0,r2
	zjmp %:debut
separe:	live %3
	ld %1879273476,r3
	xor r2,r2,r2
	zjmp %:debut
	
		
tot:	st r15,488
	st r4,487
	st r7,486
	st r8,485
	st r13,484
	st r14,483
	zjmp %458
	
debut:	st r3,4
fin:

avant:	

#	075103700370075103700771

arriere:

#       08 F4 03 70 03 70 08 F4 03 70


