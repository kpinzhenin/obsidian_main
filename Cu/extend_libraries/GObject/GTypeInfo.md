``` c
typedef struct _GTypeInfo  GTypeInfo;

struct _GTypeInfo
{
  /* interface types, classed types, instantiated types */
  guint16                class_size; // `sizeof (TDoubleClass)`

  GBaseInitFunc          base_init;
  GBaseFinalizeFunc      base_finalize;

  /* interface types, classed types, instantiated types */
  GClassInitFunc         class_init;
  GClassFinalizeFunc     class_finalize;
  gconstpointer          class_data;

  /* instantiated types */
  guint16                instance_size;
  guint16                n_preallocs;
  GInstanceInitFunc      instance_init;

  /* value handling */
  const GTypeValueTable  *value_table;
};
```
