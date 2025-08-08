
#     Program to sum the digits 1 to 10 and display the answer

	.data					# data declaration section
ID:	.ascii	"\nQtSPIM Sample 2  \n\n"

 	.asciiz "CS 243 \n\n"	# asciiz NULL terminates

	.text		
main:	
	la $a0, ID		# load address of prompt to be displayed
	li $v0, 4		# syscall 4 = print string
	syscall

	# Initialize values
	li	$s0, 0	# Clear sum
	li	$t1, 10	# Initialize loop count

	# Main addition loop
loop:	add	$s0, $s0, $t1  	# $s0 = $s0 + $t1
	addi	$t1, $t1, -1	# Dec. loop count
	bgtz	$t1, loop 	# if ($t1 > 0) branch 

	# display result
	move	$a0, $s0   	# Store the result into $a0 for printing
	li	$v0, 1		# syscall 1 = print integer
	syscall

	# we're done
	li	$v0, 10	 	# syscall 10 = End of program	
	syscall			# this is an Exit from the program!
