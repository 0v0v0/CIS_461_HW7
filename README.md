# CIS_461_HW7

## Full Lighting 2 Lights ##

![](./2lights_full.png)

This is the final result for full lighting. 
The Russian Rullete is included. 

## Full Lighting WITHOUT Russian Rullete ##

![](./2lights_full_without_rr.png)

Since Russian Rullete may ignore some "possible details", it is disabled here to test if the result cound be somewhat better. 
Compare it with the upper one, sadly it is not any better. 


## Time Costs

![](./time_with_rr.png)
This is the time costed with Russian Rullete. 


![](./time_without_rr.png)
This is the time costed without Russian Rullete. You can see that it is 14 sec slower. 

![](./time_return.png)
I noticed that in multi thread looping, "break" is slower than "return".
Since in FullLightIntrgrator, anyway we are returning L...and there's no operations after the big for loop.
So, why not just return when the break critiria is met?
As you can see, it is 18 sec faster than the first result(with Russian Rullete).
