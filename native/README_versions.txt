
	 what are the subdirectories here?
	^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
*) "src_original" is the original version.
*) "src32" is a modified 32-bit version.
*) "src64" is the 64-bit version.

	 what has been changed (in 64-bit version) and why?
	^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
*) reading the binary metadata from C# assembly files is fixed.
	=> the structs is MetaDataTables.h have padding bytes added in 64-bit platforms.
	=> the field values are written individually to the target structures.
	=> just reading the binary bytes and writing them into target structs in
		sequence no longer works because of the padding bytes.

*) some type definitions in Type.c are fixed to 32/64-bit use (using sizeof(void*)).

*) the JIT "Ops" table is converted to support both 32- and 64-bit values.
	=> the "PushXX()" macros at JIT.c have (optional) OpType information added.
	=> the "GET_OP()" macro at JIT_Execute.c is split to separate 32/64 operations:
		=> "GET_OP_32()" is a macro with (optional) OpType information checking.
			it picks one 32-bit value from JIT "Ops" table and returns it.
		=> "GET_OP_64()" is a similar macro, but it takes two 32-bit values from
			JIT "Ops" table and inserts them into "convDouble" union struct.
			the entire 64-bit value can then be obtained from "convDouble".

*) the JIT "Translate" function is converted to return 64-bit pointer values.

*) the JIT_Execute.c "GO_NEXT()" macro is converted to generate a 64-bit jump addresses.

*) since all pointers are 64-bit, all occasions where a "GET_OP()" result used to be
	casted to a pointer are converted to use "GET_OP_64()" instead.

*) in methods called using JIT_CALL_NATIVE (see InternalCalls.c), the pointers "PTR pParams"
	passed as the 2nd parameter must be fixed, if there are more than one parameter used.
	=> in 32bit the values used to be (almost/practically?) always of same size.
	=> but in 64bit the 32bit and 64bit values are often mixed.

*) in MetaData_Fill_FieldDef() function at MetaData_Fill.c corrections must be done for
	"memOffset" fields in cases where the field points to native structures (probably due
	to padding bytes automatically added by compiler to the structures). at least these
	datatypes are affected:
		*) System.Threading.Thread

