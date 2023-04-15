# Slucchetinator
 A program that helps you unlock combination locks that you don't have the combination to

## Premises
If you didn't know, it's possible to open combination locks without knowing the combination. 
I will leave a youtube link to a tutorial on how it works [here](https://www.youtube.com/watch?v=dt87u_GsChg)

Sometimes though opening a lock like this can be not so straightforward, as false gates are put in place so that you can feel "clicks" even if you are not on the right number. This of course makes it harder to easily identify the actual combination. The thing is that by just identifying all candidates for being the right number (the numbers that you feel are "harder" than the others), you're effectively greatly lowering the number of combinations that could be the actual one, as you now know that there aren't 10 possibilities for every gear, but maybe 2 or 3.

This program just tells you all the combinations that make sense after you have identified the stiffer numbers (which are the most likely candidates to be the actual number). This basically transform a feeling game into a numbers game.

## Basic usage
After you've identified by feeling the gears the most probable candidates for every one of them, start by modifying accordingly the numeri.txt file.

Let's say that you are trying to unlock a 4 gear combination lock and you think that possible numbers are: 
 - first gear: 2,5
 - second gear: 3,4
 - third gear: 5,9
 - fourth gear: 1,5,7
 
 What you should do is modify the numeri.txt file to be like this
 ```
 2 5
 3 4
 5 9
 1 5 7
 ```
 
 After you've done this you can start main.exe and input the number of gears (in this case 4). You will now see every possible combination with these hypotesis with the format | xxxx | 

What you need to do now is just to try all these combinations and you will probably manage to open the lock. 
