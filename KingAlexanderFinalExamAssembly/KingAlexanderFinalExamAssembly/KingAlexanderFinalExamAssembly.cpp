// Alexander J King
// August 5th 2021
// CSET 2230.901
// Final Exam - Write a program that checks to see how many numbers evenly divide into the last two digits of your rocket ID


/*
;1) Manually enter the last 2 digits of your Rocket ID as an integer

;2) Initialize a counter value

;3) Create loop that ranges from 1 to the last 2 digits of your Rocket ID.  You can also loop in descending order, from Rocket ID down.

;4) Divide your Rocket ID by the loop value.  Note that the IDIV instruction returns the remainder.

;5) Check if the remainder is zero, if so, increment the count

;6) Print out the count value.

;For example, if my Rocket ID is 00111193, then the last two digits is 93.  I would manually enter 93 into my program.  My program would divide 93 by 1, then 2, 3 and so on all the way up to 93.  Since 93 is divisible by 1, 3, 31, and 93 then my program will print out 4.  Note that you can also do the loop in reverse; 93, then 92, etc.

;Attach your entire .cpp program to Blackboard as a file.
*/

#include <iostream>
int main()
{
    int Num1; // user input number
    int Num2 = 0; // count of number of times divided with remainder zero. 
    std::cout << "Please input the last 2 digits of your Rocket Number: ";
    std::cin >> Num1;

    __asm
    {
        mov ecx, 0 // set counter to zero

        l1:
        add ecx, 1 // add one to counter every iteration. 

        //Result: EAX
        //Remainder: EDX

        mov edx, 0 // reset remainder to zero before doing iteration
        mov eax, Num1 // set EAX to user input (number we're going to divide)
        mov ebx, ecx // set EBX to ECX to have this iterations proper number to divide by. 
        div ebx // (EAX/EBX) and produces EAX int result and EDX remainder
        cmp edx, 0 // check to see if the remainder was zero
        je l2 // if remainder zero jump to l2 to perform appropriate steps.
        jmp l1 // if not remainder zero jump back to top of l1 and run again for next iteration.



        l2: // triggers when we have remainder zero.
        add Num2, 1 // add to Num2 count of total times we divided and got a remainder zero
        cmp ecx, Num1 // compare the counter to the user input number. If they're equal we're done. This check is here to minimize how many times we make the check. We know the last number will trigger l2 because they will be equal which requires a remainder zero. 
        je l3 // jump equal to L3 which will trigger the end of the program
        jmp l1 // if they're not equal (above step fails) go back to l1 and keep running. 

        l3:
    }
    std::cout << "The total number of times the provided number divided with remainder zero is: ";
    std::cout  << Num2; // present the user with the total number of times their given number was divisible with a remainder zero.
    // could use something like this to hunt for primes. IF (num2 = 2 ) it's prime.
    // would obviously be better at finding easier to acquire (smaller) known primes.
    exit(EXIT_SUCCESS); // **Que Dora The Explora victory theme** WE DID IT! HOORAY! 
}
