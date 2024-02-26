  # labwork.S
  # Written 2015-2017 by F Lundevall
  # Skeleton file for IS1200/IS1500 lab 1.
  # The macros PUSH and POP are in the public domain.
  # Please add your own code at the end of the file.
  # Edited by Adam Brolin 2024-01-27

  #
  # Please keep the two macros PUSH and POP unchanged
  #
.global delay
.global time2string
.global enable_interrupt
.macro	PUSH reg
	addi	$sp,$sp,-4
	sw	\reg,0($sp)
.endm

.macro	POP reg
	lw	\reg,0($sp)
	addi	$sp,$sp,4
.endm
  #
  # Please add your own code below this line
  #

	.data
	.align 2
mytime:	.word 0x5957
timstr:	.ascii "text more text lots of text\0"
dconst:	.word 6752
	.text
main:
	# print timstr
	la	$a0,timstr
	li	$v0,4
	syscall
	nop
	# wait a little
	li	$a0,1000
	jal	delay
	nop
	# call tick
	la	$a0,mytime
	jal	tick
	nop
	# call your function time2string
	la	$a0,timstr
	la	$t0,mytime
	lw	$a1,0($t0)
	jal	time2string
	nop
	# print a newline
	li	$a0,10
	li	$v0,11
	syscall
	nop
	# go back and do it all again
	j	main
	nop
# tick: update time pointed to by $a0
tick:	lw	$t0,0($a0)	# get time
	addiu	$t0,$t0,1	# increase
	andi	$t1,$t0,0xf	# check lowest digit
	sltiu	$t2,$t1,0xa	# if digit < a, okay
	bnez	$t2,tiend
	nop
	addiu	$t0,$t0,0x6	# adjust lowest digit
	andi	$t1,$t0,0xf0	# check next digit
	sltiu	$t2,$t1,0x60	# if digit < 6, okay
	bnez	$t2,tiend
	nop
	addiu	$t0,$t0,0xa0	# adjust digit
	andi	$t1,$t0,0xf00	# check minute digit
	sltiu	$t2,$t1,0xa00	# if digit < a, okay
	bnez	$t2,tiend
	nop
	addiu	$t0,$t0,0x600	# adjust digit
	andi	$t1,$t0,0xf000	# check last digit
	sltiu	$t2,$t1,0x6000	# if digit < 6, okay
	bnez	$t2,tiend
	nop
	addiu	$t0,$t0,0xa000	# adjust last digit
tiend:	sw	$t0,0($a0)	# save updated result
	jr	$ra		# return
	nop

  # you can write your code for subroutine "hexasc" below this line
  #
hexasc: 
	andi $t0, $a0, 0xf 	# get 4 lsb from $a0
	
	sltiu $t1, $t0, 10
	beq $0, $t1, else 	# if $a0 <= 9
	nop
	addi $v0, $t0, 0x30 	# add $a0 + 0x30
	
	j elseend
	nop	
else: 				# else
	addi $v0, $s0, 0x37 	# add $0 + 0x3b
elseend:

hexascend: 
	jr $ra # return
	nop
	
delay:
	la 	$t0, dconst
	lw	$t1,0($t0)
	
	
while:	
	slt	$t2, $0, $a0
	beq	$t2, $0, whileend
	nop
	
	li	$t4, 0
for:
	slt	$t3, $t4, $t1
	addi	$t4, $t4, 1
	bne	$t3, $0, for
	nop
	
forend:
	addi 	$a0, $a0, -1
	bne 	$t2, $0, while
	nop
whileend:
	
delayend:
	jr 	$ra
	nop
	
time2string: # $a0 - adress of area in memory, $a1 - 16 lsb timeinfo
	
	PUSH $ra	
	PUSH $s0 # push $s0,$s1
	PUSH $s1
	
	PUSH $s2
	PUSH $s3 
	
	move 	$s0, $a0		# argument s0, s1
	move 	$s1, $a1		# mask $a1
			
	andi 	$t0, $s1, 0xf000
	srl 	$a0, $t0, 12	
	jal 	hexasc		# call function
	nop
	addi	$s0,$s0,0
	move 	$s2, $v0
		
	andi 	$t0, $s1, 0x0f00
	srl 	$a0, $t0, 8		
	jal 	hexasc		# call function
	nop
	sll	$v0,$v0,8
	or	$s2,$s2,$v0

				# store return value in $a0	
	li	$t0, 0x3a0000
	or	$s2,$s2,$t0

		
	andi 	$t0, $s1, 0x00f0
	srl 	$a0, $t0, 4		
	jal 	hexasc		# call function
	nop
	sll	$v0, $v0, 24	
	or	$s2,$s2,$v0
	sw	$s2,0($s0) 	# store return value in $a0
	
	
	andi 	$a0, $s1, 0x000f	
	jal 	hexasc		# call function
	nop
	addi	$s0,$s0,4
	move 	$s3, $v0
	
		
	li	$t0, 0x00
	or	$s3,$s3,$t0
	sw	$s3,0($s0)	# store 0x00 in $a0
			
		
	POP $s3 
	POP $s2 
	
	POP $s1 
	POP $s0 
	POP $ra 
	
time2stringend:
	jr $ra
	nop

enable_interrupt:
	ei
	jr $ra
	nop

	
