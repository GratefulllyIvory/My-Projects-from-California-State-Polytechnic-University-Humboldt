
	.data
message:
	.asciiz "sum = "

	.text
	.globl main

main:	move $s0, $ra		# Save return address 

	li $v0, 5			# system call for read_int
	syscall
	move $t0, $v0		# number read is put in $t0

	li $v0, 5			# system call for read_int
	syscall
	move $t1, $v0		# number read is put in $t1

	add $t3, $t0, $t1		# add the two numbers

	li $v0, 4			# system call for print_string
	la $a0, message		# message to be printed
	syscall

	li $v0, 1			# system call for print_int
	move $a0, $t3		# number in $t3 is to be printed
	syscall

	move $ra, $s0		# Restore return address 
	jr $31			# Return from main  (ra = 31)

					# Note that this last couplet is for
					# returning to an OS; we don't have 
					# such here!  So we should Exit.
