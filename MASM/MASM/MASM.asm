; Alexander King
; Augest 4th 2021
; CSET 2230.901
; Final Exam - Write a program that checks to see how many numbers evenly divide into the last two digits of your Rocket ID.   

;1) Manually enter the last 2 digits of your Rocket ID as an integer

;2) Initialize a counter value

;3) Create loop that ranges from 1 to the last 2 digits of your Rocket ID.  You can also loop in descending order, from Rocket ID down.

;4) Divide your Rocket ID by the loop value.  Note that the IDIV instruction returns the remainder. 

;5) Check if the remainder is zero, if so, increment the count

;6) Print out the count value.

;For example, if my Rocket ID is 00111193, then the last two digits is 93.  I would manually enter 93 into my program.  My program would divide 93 by 1, then 2, 3 and so on all the way up to 93.  Since 93 is divisible by 1, 3, 31, and 93 then my program will print out 4.  Note that you can also do the loop in reverse; 93, then 92, etc.

;Attach your entire .cpp program to Blackboard as a file.


include irvine32.inc 

.data 
Num1 dd ?
Num2 dd 0
str1 db "Enter your Rocket Number : ", 10, 13, 0
str2 db "The number of times divided with remainder 0 is: "


.code
main proc



mov edx, offset str1
call writestring 
call readint 
mov Num1,eax

mov ecx,0



l1:
add ecx,1

; Result: EAX
; Remainder : EDX

mov edx,0
mov eax,Num1
mov ebx, ecx
div ebx

cmp edx,0
je l2
jmp l1



l2:
add Num2,1
cmp ecx,Num1
je l3
jmp l1




l3:
mov edx, offset str2
call WriteString
mov eax, Num2
call WriteInt

exit
main endp
end main