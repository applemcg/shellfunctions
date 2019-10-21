
_include( version.txt)_
_
_H(One, First Header)_
_
This is lower case of First Header: _tolower( First Header)

_H(
## ,Unit Tests)
_H(
### , TTB )

+ ( some text  ) : {_ttb( some text  )}
+ ( some Other text ): {_ttb( some Other text )}
+ ( one last try): {_ttb( one last try)}

_H(
# , Header with trailing space )

{_namify( Another Trailing Blank  )}

{_dashify( Another   Trailing Blank)}


_H(
# , Other Utilities )

_H(
## , Reverse )

_dumpdef(@{_reverse}@)

reverse( a, b, c, 13, 12, 11):

_reverse( a, b, c, 13, 12, 11)

_H(
## , Repeated )

_dumpdef(@{_repeated}@)

repeated( 4, *):  _repeated( 4, *)
repeated( 1, stuff ): _repeated( 1, stuff )
repeated( 0, nothing): _repeated( 0, nothing)
repeated( 2, more stuff ): _repeated( 2, more stuff )

_H(
# , Available Internal Data )
__file__, __line__, __program__
