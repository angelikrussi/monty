#!/bin/bash
sed -i	's/op_push/_push/g'	*.c *.h
sed -i	's/op_pall/_pall/g'	*.c *.h
sed -i	's/op_pint/_pint/g'	*.c *.h
sed -i	's/op_pop/_pop/g'	*.c *.h
sed -i	's/op_swap/_swap/g'	*.c *.h
sed -i	's/op_add/_add/g'	*.c *.h
sed -i	's/op_nop/_nop/g'	*.c *.h
sed -i	's/op_sub/_sub/g'	*.c *.h
