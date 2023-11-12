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
well stop at the heightest box? yes

okay let's say easy cases then add all the cases
![](./pics/17.png)
this is the case where there's height that equal to the start.
![](./pics/18.png)
so first as we said before we start at left then find equal or hiegher height on the right and calculate the **Area** but
how can we calculate the area well width=(rightIndex - leftIndex - 1) * height = min(leftHeight, rightHeight) this will gives us the blue area, but the blue area is wrong, why
there's the other boxes of heights 2, 3, 5 submerged there
so all we have to do is remove them from the Area that we calculated above and boom we got the area of that part

```cpp
int trap(std::vector<int>& height) {
    int leftIndex = 0, rightIndex;
    const int size = height.size();
    while (leftIndex < size - 2) {

    }

}
```

you may wonder why ```while(leftIndex < size - 2)``` well because water can not be trapped unless there's three heights
let's say that index in this case reached the value 7, it does not need to because there's no way can be trapped by 1 or 2 heights.

```cpp
int trap(std::vector<int>& height) {
    int leftIndex = 0, rightIndex;
    const int size = height.size();
    while (leftIndex < size - 2) {
        if (height[leftIndex] > height[leftIndex + 1]) {

        } else {
            ++leftIndex;
        }
    }

}
```

why ```if (height[leftIndex] > height[leftIndex + 1])``` well if there's next box but that next box is heigher
there's no need to continue from there so we move to it
![](./pics/19.png)

okay let's say that the condition is right what now
![](./pics/20.png)

```cpp
int trap(std::vector<int>& height) {
    int leftIndex = 0, rightIndex;
    const int size = height.size();
    while (leftIndex < size - 2) {
        if (height[leftIndex] > height[leftIndex + 1]) {
            rightIndex = leftIndex + 2;
            while (
                rightIndex < size &&
                height[leftIndex] > height[rightIndex]
            ) {
                ++rightIndex;
            }

            const int width = (rightIndex - leftIndex - 1);
            const int h = std::min(
                height[leftIndex],
                height[rightIndex]
            );
            const int area = width * h;

        } else {
            ++leftIndex;
        }
    }

}
```

well now we search for the next height that is either hiegher or equal to the left box so it should stop at box at
index 4 with height 8
![](./pics/21.png)

well we now we have the area, all we need to do is to remove
the added area (submerged black boxes) we could add variable
that store the sum of heights while we are searching for box
on the right

```cpp
int trap(std::vector<int>& height) {
    int leftIndex = 0, rightIndex;
    int subMergedArea;
    const int size = height.size();
    while (leftIndex < size - 2) {
        if (height[leftIndex] > height[leftIndex + 1]) {
            subMergedArea = height[leftIndex + 1];
            rightIndex = leftIndex + 2;
            while (
                rightIndex < size &&
                height[leftIndex] > height[rightIndex]
            ) {
                subMergedArea += height[rightIndex];
                ++rightIndex;
            }

            const int width = (rightIndex - leftIndex - 1);
            const int h = std::min(
                height[leftIndex],
                height[rightIndex]
            );
            const int area = (width * h) - subMergedArea;

        } else {
            ++leftIndex;
        }
    }

}
```

why ```subMergedArea = height[leftIndex + 1]``` at the start well because the inner loop will start from leftIndex + 2 and
it will be skiped that's why we added it first.

and what now ? well we add this area variable to some variable that holdes the entire area of all heights and we
repeat by moving the leftIndex to the rightIndex


```cpp
int trap(std::vector<int>& height) {
    int overAllArea = 0;
    int leftIndex, rightIndex;
    int subMergedArea;
    const int size = height.size();
    while (leftIndex < size - 2) {
        if (height[leftIndex] > height[leftIndex + 1]) {
            subMergedArea = height[leftIndex + 1];
            rightIndex = leftIndex + 2;
            while (
                rightIndex < size &&
                height[leftIndex] > height[rightIndex]
            ) {
                subMergedArea += height[rightIndex];
                ++rightIndex;
            }

            const int width = (rightIndex - leftIndex - 1);
            const int h = std::min(
                height[leftIndex],
                height[rightIndex]
            );
            const int area = (width * h) - subMergedArea;
            overAllArea += area;
            leftIndex = rightIndex;
        } else {
            ++leftIndex;
        }
    }
    return overAllArea;
}
```

okay seems fine let's see the other cases, for example that
there's no heigher box to the right

![](./pics/22.png)
![](./pics/23.png)

let's say for example the first case, well this is also easy
instead of looking into box with height bigger than the box
on the left we will also look for the heighest box in this case
box at index 3 of height 5, and apply the same tactic as before to find area.



```cpp
int trap(std::vector<int>& height) {
    int leftIndex = 0, rightIndex;
    int subMergedArea;
    const int size = height.size();
    while (leftIndex < size - 2) {
        if (height[leftIndex] > height[leftIndex + 1]) {
            subMergedArea = height[leftIndex + 1];
            rightIndex = leftIndex + 2;
            while (
                rightIndex < size &&
                height[leftIndex] > height[rightIndex]
            ) {
                subMergedArea += height[rightIndex];
                ++rightIndex;
            }

            const int width = (rightIndex - leftIndex - 1);
            const int h = std::min(
                height[leftIndex],
                height[rightIndex]
            );
            const int area = (width * h) - subMergedArea;

        } else {
            ++leftIndex;
        }
    }

}
```

why ```subMergedArea = height[leftIndex + 1]``` at the start well because the inner loop will start from leftIndex + 2 and
it will be skiped that's why we added it first.

and what now ? well we add this area variable to some variable that holdes the entire area of all heights and we
repeat by moving the leftIndex to the rightIndex


```cpp
int trap(std::vector<int>& height) {
    int overAllArea = 0;
    int leftIndex = 0, rightIndex;
    int subMergedArea;
    const int size = height.size();
    int heighestBoxIndex;
    int heighestBox;
    int areaForHeighestBox;
    while (leftIndex < size - 2) {
        if (height[leftIndex] > height[leftIndex + 1]) {
            heighestBoxIndex = 0;
            heighestBox = -1;
            subMergedArea = height[leftIndex + 1];
            rightIndex = leftIndex + 2;
            while (
                rightIndex < size &&
                height[leftIndex] > height[rightIndex]
            ) {
                if (height[rightIndex] > heighestBox) {
                    heighestBox = height[rightIndex];
                    heighestBoxIndex = rightIndex;
                    areaForHeighestBox = subMergedArea;
                }
                subMergedArea += height[rightIndex];
                ++rightIndex;
            }

            if (rightIndex < size) {
                const int width = (rightIndex - leftIndex - 1);
                const int h = std::min(
                    height[leftIndex],
                    height[rightIndex]
                );
                const int area = (width * h) - subMergedArea;
                overAllArea += area;
                leftIndex = rightIndex;
            } else {
               const int width = (heighestBoxIndex - leftIndex - 1);
                const int h = std::min(
                    height[leftIndex],
                    heighestBox
                );
                const int area = (width * h) - areaForHeighestBox;
                overAllArea += area;
                leftIndex = heighestBoxIndex;
            }
        } else {
            ++leftIndex;
        }
    }
    return overAllArea;
}
```

there's some minor problems with this code, remember this case
![](./pics/23.png)
well we intended to find the heightest box and since we are doing rightIndex = leftIndex + 2
we are going to skip it and we will find last box instead which is wrong so we should make
rightIndex = leftIndex + 1, and if we do that subMergedArea should be equal to  zero at the
start because it will not be skiped inside the loop

```cpp
int trap(std::vector<int>& height) {
    int overAllArea = 0;
    int leftIndex = 0, rightIndex;
    int subMergedArea;
    const int size = height.size();
    int heighestBoxIndex;
    int heighestBox;
    int areaForHeighestBox;
    while (leftIndex < size - 2) {
        if (height[leftIndex] > height[leftIndex + 1]) {
            heighestBoxIndex = 0;
            heighestBox = -1;
            subMergedArea = 0;
            rightIndex = leftIndex + 1;
            while (
                rightIndex < size &&
                height[leftIndex] > height[rightIndex]
            ) {
                if (height[rightIndex] > heighestBox) {
                    heighestBox = height[rightIndex];
                    heighestBoxIndex = rightIndex;
                    areaForHeighestBox = subMergedArea;
                }
                subMergedArea += height[rightIndex];
                ++rightIndex;
            }

            if (rightIndex < size) {
                const int width = (rightIndex - leftIndex - 1);
                const int h = std::min(
                    height[leftIndex],
                    height[rightIndex]
                );
                const int area = (width * h) - subMergedArea;
                overAllArea += area;
                leftIndex = rightIndex;
            } else {
               const int width = (heighestBoxIndex - leftIndex - 1);
                const int h = std::min(
                    height[leftIndex],
                    heighestBox
                );
                const int area = (width * h) - areaForHeighestBox;
                if (area > 0)
                    overAllArea += area;
                leftIndex = heighestBoxIndex;
            }
        } else {
            ++leftIndex;
        }
    }
    return overAllArea;
}
```

and what about ```if (area > 0)``` why? well let's say that (heighestBoxIndex - leftIndex - 1) = 0
well that means there's no way we could trap water there, but areaForHeighestBox will be holding the
value of box at heighestBoxIndex which would result in area < 0, which is wrong so we just ignor it.

### Can We do Better?