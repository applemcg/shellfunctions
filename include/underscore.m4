 _divert(-1)
  need hacks.m4
_changequote(`,')

define(`m4_defn',defn(`defn'))
	define(`_defn',defn(`defn'))undefine(`defn')
define(`m4_define',_defn(`define'))
	define(`_define',_defn(`define'))undefine(`define')
_define(`om4_undefine',_defn(`undefine'))
	_define(`_undefine',_defn(`undefine'))_undefine(`undefine')

  ------------------------------------------------------- ReDefinitions	--

_define(`_define_',`_define(`_$1',`$2')')
_define_(ifdef_,`_ifdef(`_$1',`$2',`$3')')
_define_( ifndef_,`_ifdef_( $1, $3, $2)')
_define_(pushdef_,`_pushdef(`_$1',`$2')')
_define_(popdef_,`_ifelse($1,,,`_popdef(`_$1')_dnl
_ifdef_($1,,`$0(_shift($@))')')')
_define_(undefine_,`_undefine(`_$1')')
_define_(dumpdef_,`_ifelse($1,,,`_dumpdef(`_$1')`'$0(_shift($@))')')

 _divert(0)
