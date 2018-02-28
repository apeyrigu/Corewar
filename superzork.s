.name "zork"
.comment "I'M ALIIIIVE"

l1:		ld %191365376, r2
		st r2, 250
		ld %268435462, r2
		st r2, 242
		ld %1677787136, r2
		st r2, 234
		ld %257, r2
		st r2, 226
		ld %1, r2
		st r2, 218
		ld %167770880, r2
		st r2, 210

fork:   fork %185

l2:		sti r1, %:live, %1
		and r1, %0, r1

live:	live %1
		zjmp %:live
