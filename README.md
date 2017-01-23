# cg-controller

##Game controller standard
The following is proposed logic that the controller will return. To make this simple, the controller acts as an 
external keyboard and mimics a button press on an actual keyboard.

* Button 1 = press t (A single button on top of the controller generally used to toggle a game on or off)
* Button 2 = press q (Generally used to move left or down)
* Button 3 = press e (Generally used to move right or up)

Eventually the games will allow a user to choose preferred button positions.

##Energy reader (stepper/wheel)
Games require a degree of energy to be played so the user must step or pedal in order to invoke action
in the game. 

The energy action is used to move an object in the game or have certain functionality opened.

At present this has been hacked to work with pre-existing games which require a “key press” type
action which is not ideal. The plan is to return RPMs giving the game the freedom to choose what to do with the input.


