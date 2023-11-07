### Trapping Rain Water
![](./pics/intro.png)

### Problem
Given non-negative list of numbers representing an elevation map where the width of each bar is 1
compute how how much water it can trap after raining.

### Brue Force
well How can we approche this we could for example see the first two boxes how much water they can
container and add up oops two boxs can not hold any water

![](./pics/1.png)
![](./pics/2.png)
![](./pics/3.png)
![](./pics/4.png)

so as you can see at least we need 3 boxes but not any 3 boxes because if they are on the same elevation
no water will be held so we need the middel one to be lower than the sides.

![](./pics/5.png)
![](./pics/6.png)
![](./pics/7.png)

so how can we implement this well as first idea we could make loop start at first box then search forward
for box with **'lower height and then search for box with higher height'**

![](./pics/8.png)

okay so how can we calculate this area well we could do height*width and after that remove the bumbes
between them

![](./pics/9.png)

so what now well now we could continue from there to the right and add them all up later, can we ?
well let's look at this situation in more details, for example

![](./pics/10.png)
![](./pics/11.png)

if we follow the steps that we said we will result in this situation? which is clearly not the right
answer? so what is wrong in our proedure? well did you notice that I put quets around stuff that was
about heights some height being lower than other well what does that mean? we should be more accurate
on when to stop, okay let's run the procedure again and be carfull, same again we start with first
box of height 8, let's look for box that is lower than 8 well next to it is box of height 2, now our
target is to look for something heigher so we can trap water okay next box is of height 3 at index 2
okay the condition is met we have box of height 8 at index 0, box of lower height of 2 at index 1
heigher box again at index 3, well previously we stopped here? was that wise? because 3 is the bottelneck 
now and there's better options down the road like 5, and 7, so clearly we should not stop here, so instead
of stopping when we have heigher, lower and hiegher we continue until we found box that is either heigher
than the first or the end, in this case it will reach the end which is what we want.

![](./pics/12.png)

this is other case when we reach heigher box not end of the list

![](./pics/13.png)

well did we consider all situations well no look at these

![](./pics/14.png)
![](./pics/15.png)
![](./pics/16.png)

The Big question when should you stop?

stop when the right side has heigher height? what if there's none
well stop at the heightest box? maybe