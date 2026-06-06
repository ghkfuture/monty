,           Read first digit into Cell 0
,           Read second digit into Cell 1
[
    -       Decrement Cell 1
    > + <   Increment Cell 2
]
<           Move back to Cell 0
[
    -       Decrement Cell 0
    >> + << Increment Cell 2
]
>>          Go to Cell 2 (Sum of ASCII values)
+++++ +++++ +++++ +++++ +++++ +++++ +++++ +++++ +++++ +++++ +++++ +++++
------      Subtract 48 to convert back from ASCII to digit value
.           Print result
