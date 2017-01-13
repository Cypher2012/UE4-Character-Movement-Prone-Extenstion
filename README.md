# UE4-Character-Movement-Prone-Extenstion
An extension of the UCharacterMovementComponent which enables support for prone movement and transition pauses.

WARNING: This is a work in progress!

WARNING: The overriden crouch functionality does NOT use the origonal crouch variables. This class has its own crouch variables/functions. Be sure that any animation/actions etc, are driven from the correct data, especially if you already have something using it already. Animation blueprints are a typical place you may already be using crouch functionality.

Use the 'StandUp' and 'Prone' functions exactly how you would the standard 'Crouch' function.

No need to call 'UnCrouch' when using either 'StandUp' or 'Prone'.

Use the StartTransition/EndTransition functions to stop the character moving while in an animation. The recommended usage is to have animation notify events call these two functions.
