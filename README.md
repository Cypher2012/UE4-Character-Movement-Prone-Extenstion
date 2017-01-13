# UE4-Character-Movement-Prone-Extenstion
An extension of the UCharacterMovementComponent which enables support for prone movement and transition pauses.

WARNING: This is a work in progress!

Use the 'StandUp' and 'Prone' functions exactly how you would the standard 'Crouch' function.

No need to call 'UnCrouch' when using either 'StandUp' or 'Prone'.

Use the StartTransition/EndTransition functions to stop the character moving while in an animation. The recommended usage is to have animation notify events call these functions.
