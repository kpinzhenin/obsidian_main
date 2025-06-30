В GLib есть фундаментальные и не фундаментальные типы, отличия заключаются в том, что фундаментальные типы не имеют родительского типа. 
 - class size : `class_size` 
 - class initialization functions (C++ constructor): the `base_init` and `class_init` fields in `GTypeInfo`.
 - class destruction functions (C++ destructor): the `base_finalize` and `class_finalize` fields in `GTypeInfo`.
 - instance size (C++ parameter to new): the `instance_size` field in `GTypeInfo`.
 - instantiation policy (C++ type of new operator): the `n_preallocs` field in `GTypeInfo`.
 - copy functions (C++ copy operators): the `value_table` field in `GTypeInfo`.
 - type characteristic flags: `GTypeFlags`

