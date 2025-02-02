GObject instance is created with `g_object_new` function. GObject has not only instances but also classes (подразумевается, что память под объект класса выделяется при первом вызове). однако `g_object_new` возвращает указатель только на сам экземпляр класса, но не на сам класс.
- A class of GObject is created at the first call of `g_object_new`. And there exists only one GObject class.
- GObject instance is created whenever `g_object_new` is called. So, two or more GObject instances can exist.
`g_object_unref` decreases the reference count by 1. If the reference count drops to zero, the instance destroys itself.
GObject type is a static type. Static type never destroys its class. So, even if the destroyed instance is the last instance, the class still remains.

Определение наследника класса GObject базируется на макросе `G_DEFINE_TYPE`, который объявляет функции инициализации будущего `класса` и `экземпляра` и функцию которая регистрацию типа как GType и производит:
 - `<name space>_<name>_class_init()`
 - `<name space>_<name>_init()`
 - `<name space>_<name>_get_type()`
