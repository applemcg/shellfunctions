
_divert(-1)

_changecom(@@)_

# comment
@@ another comment

_changequote(@{,}@)_

   Use PATSUB in dashify
   
_define(@{_dashify}@,@{_
_translit(@{$1}@,@{  }@,@{-}@)}@)

_define(@{_namify}@,@{_
_dashify(_tolower(_ttb(@{$1}@)))}@)

* namify
   * dashify
       + translit
   * tolower
       + translit
   * ttb
       + regexp

_define(@{_tolower}@,@{_
_translit(@{$1}@,@{A-Z}@,@{a-z}@)}@)

_define(@{_ttb}@,@{_
_regexp(@{$1}@,@{\(.*[^ ]\) *$}@,@{\1}@)}@)_

    to define arrays, numbered, and associative, see: 

    https://www.gnu.org/software/m4/manual/m4-1.4.14/html_node/Define.html#Define

    OR
    https://mbreen.com/m4.html#unexpandingmacros
    
_define(@{_header_level}@,@{1}@)


_define(@{_reverse}@, @{_ifelse(@{$#}@, @{0}@, , @{$#}@, @{1}@, @{@{$1}@}@,
                               @{$0(_shift($@)), @{$1}@}@)}@)


_define(@{_repeated}@,@{_
_ifelse(@{$1}@, @{0}@, , @{$1}@, @{1}@, @{$2}@,
                               @{$2@{}@$0(_decr($1),@{$2}@)}@)}@)

 ---------------------------------------- code emitters	--

_ifdef(@{_markdown}@,@{

# must be requested
#    uses namify,

_include(markdown.m4)

}@,@{

# the DEFAULT
#  uses namify

_include(markua.m4)


}@)

_divert(0)_
